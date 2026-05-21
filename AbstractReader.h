#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H
#include <string>
#include <vector>
#include "Human.h"
#include "Student.h"

class AbstractReader {
public:
    virtual ~AbstractReader() = default;

    virtual void open(const std::string& filename) = 0;
    virtual bool is_open() = 0;
    virtual std::pair<std::vector<Human>, std::vector<Student>> readAll() = 0;
};

#endif // ABSTRACTREADER_H
