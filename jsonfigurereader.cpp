#include "jsonfigurereader.h"
#include "rectanglefigure.h"
#include "circlefigure.h"
#include "trianglefigure.h"
#include "json.hpp"
#include <stdexcept>
#include <QPoint>
#include <QPolygon>

bool JsonFigureReader::open(const std::string& filename) {
    m_file.open(filename);
    return m_file.is_open();
}

bool JsonFigureReader::is_open() const {
    return m_file.is_open();
}

void JsonFigureReader::close() {
    if (m_file.is_open())
        m_file.close();
}

std::vector<std::unique_ptr<Figure>> JsonFigureReader::readAll() {
    if (!m_file.is_open())
        throw std::runtime_error(std::string("File is not opened"));

    nlohmann::json jsonData;
    m_file >> jsonData;
    m_file.close();
    std::vector<std::unique_ptr<Figure>> figures;

    for (const auto& item : jsonData) {
        if (!item.contains("type")) continue;
        std::string type = item["type"].get<std::string>();

        if (type == "rectangle") {
            auto rect = std::make_unique<RectangleFigure>();
            rect->setPos(QPoint(item.at("x"), item.at("y")));
            rect->setSize(item.at("width"), item.at("height"));
            figures.push_back(std::move(rect));
        }
        else if (type == "circle") {
            auto circ = std::make_unique<CircleFigure>();
            circ->setPos(QPoint(item.at("x"), item.at("y")));
            circ->setRadius(item.at("radius"));
            figures.push_back(std::move(circ));
        }
        else if (type == "triangle") {
            auto tri = std::make_unique<TriangleFigure>();
            QPolygon polygon;
            for (const auto& point : item.at("points")) {
                polygon << QPoint(point.at("x"), point.at("y"));
            }
            tri->setPolygon(polygon);
            figures.push_back(std::move(tri));
        }
    }
    return figures;
}
