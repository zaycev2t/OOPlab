#ifndef CSVREADER_H
#define CSVREADER_H
#include <string>
#include <fstream>
#include <vector>
#include "Human.h"
#include "Student.h"
#include "AbstractReader.h"
class CsvReader : public AbstractReader
{
public:
    CsvReader();
    void open(const std::string& filename) override;
    bool is_open() override;
    std::pair<std::vector<Human>, std::vector<Student>> readAll() override;
private:
    std::ifstream csv;
};

#endif // CSVREADER_H
