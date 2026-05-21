#ifndef STUDENT_H
#define STUDENT_H
#include <human.h>

class Student : public Human
{
private:
    float AvgSc = 4.0;
public:
    Student() = default;
    Student(const std::string& a, int b, int c, float AvgSc);
    void setAvgSc(double a);
    double getAvgSc() const;
    int getType() const override;
};

#endif // STUDENT_H
