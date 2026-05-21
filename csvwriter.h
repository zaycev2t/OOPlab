#ifndef CSVWRITER_H
#define CSVWRITER_H
#include <fstream>
#include <string>
#include "Human.h"
#include "Student.h"
class CsvWriter
{public:
    CsvWriter();
    void open(const std::string& filename, std::ios::openmode mode);
    bool is_open();
    void write(const Human& human);
    void close();

private:
    std::ofstream ofcsv;
};

#endif // CSVWRITER_H
