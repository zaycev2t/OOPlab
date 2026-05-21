#ifndef HUMAN_H
#define HUMAN_H
#include <string>
class Human{
    private:
        std::string name = "default Name";
        int height = 50;
        int weight = 150;
    public: 
        Human() = default;
        Human(const std::string& a, int b, int c);
        void setName(const std::string& t);
        std::string getName() const;
        void setHeight(int t);
        int getHeight() const;
        void setWeight(int t);
        int getWeight() const;
        virtual int getType() const;
};



#endif // HUMAN_H
