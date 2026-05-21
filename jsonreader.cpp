#include "JsonReader.h"
#include "json.hpp"
#include <iostream>

using json = nlohmann::json;

JsonReader::JsonReader() {}

void JsonReader::open(const std::string& filename) {
    file.open(filename);
}

bool JsonReader::is_open() {
    return file.is_open();
}

std::pair<std::vector<Human>, std::vector<Student>> JsonReader::readAll() {
    std::vector<Human> humans;
    std::vector<Student> students;

    json j;
    try {
        file >> j;
    } catch (const json::parse_error& e) {
        return {humans, students};
    }

    if (!j.is_array()) {
        return {humans, students};
    }

    for (const auto& item : j) {
        if (!item.contains("type") || !item.contains("name") ||
            !item.contains("height") || !item.contains("weight")) {
            continue;
        }

        int type = item["type"].get<int>();
        std::string name = item["name"].get<std::string>();
        int height = item["height"].get<int>();
        int weight = item["weight"].get<int>();

        if (type == 1) {
            Human h;
            h.setName(name);
            h.setHeight(height);
            h.setWeight(weight);
            humans.push_back(h);
        }
        else if (type == 2) {
            if (!item.contains("avgSc")) continue;
            double avg = item["avgSc"].get<double>();
            Student s;
            s.setName(name);
            s.setHeight(height);
            s.setWeight(weight);
            s.setAvgSc(avg);
            students.push_back(s);
        }
    }

    return {humans, students};
}
