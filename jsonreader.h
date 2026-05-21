#ifndef JSONREADER_H
#define JSONREADER_H

#include "AbstractReader.h"
#include <fstream>

class JsonReader : public AbstractReader {
private:
    std::ifstream file;
public:
    JsonReader();
    void open(const std::string& filename) override;
    bool is_open() override;
    std::pair<std::vector<Human>, std::vector<Student>> readAll() override;
};

#endif
