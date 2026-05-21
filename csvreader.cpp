#include "csvreader.h"
#include "csvparseexception.h"
CsvReader::CsvReader() {}

void CsvReader::open(const std::string& filename)
{
    csv.open(filename);
}
bool CsvReader::is_open()
{
    return csv.is_open();
}
std::pair<std::vector<Human>, std::vector<Student>> CsvReader::readAll()
{
    std::vector<Human> humans;
    std::vector<Student> students;
    unsigned lineNumber = 0;
    while(!csv.eof()){
        int type;
        ++lineNumber;
        Human h;
        Student s;
        std::string line;
        std::getline(csv, line);
        if (line.empty()) continue;
        size_t pos_1 = line.find(';');
        /*try {
            type = std::stoi(line.substr(0,pos_1));
        } catch (...) {
            continue;   // неверный тип – пропустить строку
        }
        */
        try {
            type = std::stoi(line.substr(0,pos_1));
            if (type < 0) throw CsvParseException("Invalid type value in CSV", lineNumber);
        } catch (const std::invalid_argument&) {
            throw CsvParseException("Invalid type value in CSV", lineNumber);
        }catch (const std::out_of_range& ex){
            throw CsvParseException("Out of range in CSV", lineNumber);
        }
        if (type == 1){
            size_t pos_2 = line.find(';', pos_1+1);
            size_t pos_3 = line.find(';', pos_2+1);
            size_t pos_4 = line.find(';', pos_3+1);
            h.setName(line.substr(pos_1+1,pos_2-pos_1-1));
            std::string height_str = line.substr(pos_2+1,pos_3-pos_2-1);
            std::string weight_str = line.substr(pos_3+1,pos_4-pos_2-1);
            try {
                h.setHeight(std::stoi(height_str));
                if (std::stoi(height_str) < 0) throw CsvParseException("Invalid type value in CSV", lineNumber);
                h.setWeight(std::stoi(weight_str));
                if (std::stoi(weight_str) < 0) throw CsvParseException("Invalid type value in CSV", lineNumber);
                humans.push_back(h);
            } catch (const std::invalid_argument& ex) {
                throw CsvParseException("Invalid height or weight", lineNumber);
            }catch (std::out_of_range& ex) {
                throw CsvParseException("Out of range in height or weight", lineNumber);
            }
        }
        else if (type == 2){
            size_t pos_2 = line.find(';', pos_1+1);
            size_t pos_3 = line.find(';', pos_2+1);
            size_t pos_4 = line.find(';', pos_3+1);
            size_t pos_5 = line.find(';', pos_4+1);
            s.setName(line.substr(pos_1+1,pos_2-pos_1-1));
            std::string height_str = line.substr(pos_2+1,pos_3-pos_2-1);
            std::string weight_str = line.substr(pos_3+1,pos_4-pos_3-1);
            std::string AvgSc_str = line.substr(pos_4+1,pos_5-pos_4-1);
            try {
                s.setHeight(std::stoi(height_str));
                s.setWeight(std::stoi(weight_str));
                s.setAvgSc(std::stod(AvgSc_str));
                if ((std::stoi(height_str) < 0) or (std::stoi(weight_str) < 0) or (std::stod(AvgSc_str) < 0)) throw CsvParseException("Invalid type value in CSV", lineNumber);
                students.push_back(s);
            } catch (const std::invalid_argument& ex) {
                throw CsvParseException("Invalid height or weight or AvgScore", lineNumber);
            }catch (std::out_of_range& ex) {
                throw CsvParseException("Out of range in height or weight or AvgScore", lineNumber);
            }
        }
    }
    return std::make_pair(humans, students);
}
