#include <string>
#include <iostream>
#include <human.h>
Human::Human(const std::string& a, int b, int c)
    : name(a),
    height(b),
    weight(c)
{
    std::cout << "Human " << name <<  " created" << std::endl;

}
void Human::setName(const std::string& t){
    name = t;
};
std::string Human::getName() const {
    return name;
};
void Human::setHeight(int t) {
    height = t;
};
int Human::getHeight() const  {
    return height;
};
void Human::setWeight(int t){
    weight = t;
};
int Human::getWeight() const  {
    return weight;
};
int Human::getType() const {
    return 1;
}
