#ifndef JSONFIGUREREADER_H
#define JSONFIGUREREADER_H

#include "Figure.h"
#include <fstream>
#include <memory>
#include <vector>
#include <string>

class JsonFigureReader {
public:

    bool open(const std::string& filename);
    bool is_open() const;
    void close();
    std::vector<std::unique_ptr<Figure>> readAll();

private:
    std::ifstream m_file;
};

#endif // JSONFIGUREREADER_H
