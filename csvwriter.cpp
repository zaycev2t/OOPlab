#include "csvwriter.h"
#include <iostream>
CsvWriter::CsvWriter() {}
void CsvWriter::open(const std::string& filename, std::ios::openmode mode)
{
    ofcsv.open(filename, mode);
}
bool CsvWriter::is_open()
{
    return ofcsv.is_open();
}
void CsvWriter::write(const Human& human)
{
    if (!ofcsv.is_open())
        return;
    if (human.getType() == 1)
    {
        std::string line = "1;" + human.getName() + ";" +
                           std::to_string(human.getHeight()) + ";" +
                           std::to_string(human.getWeight()) + "\n";

        ofcsv << line;
    }
    else if (human.getType() == 2)
    {
        const Student& student = dynamic_cast<const Student&>(human);
        std::string line = "2;" + student.getName() + ";" +
                           std::to_string(student.getHeight()) + ";" +
                           std::to_string(student.getWeight()) + ";" + std::to_string(student.getAvgSc()) + "\n";

        ofcsv << line;
    }
    else {return;}
}

void CsvWriter::close()
{
    ofcsv.close();
}
