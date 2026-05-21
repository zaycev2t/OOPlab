#include "student.h"


Student::Student(const std::string& a, int b, int c, float AvgSc)
    : Human(a, b, c),
    AvgSc(AvgSc)
{
}
void Student::setAvgSc(double a) {
    AvgSc = a;
};
double Student::getAvgSc() const  {
    return AvgSc;
};
int Student::getType() const {
    return 2;
}
