#include "student.h"

int Student::getId() const{
    return id;
}
string Student::getName() const{
    return name;
}
string Student::getBirthDate() const{
    return birthDate;
}
unordered_map<int, map<int, Grade>> Student::getGrades() const{
    return grades;
}
void Student::addGrade(int sjId, int testNum, Grade g){

    grades[sjId].insert({testNum, g});

}
void Student::removeGrade(int sjId, int testNum){

    grades[sjId].erase(testNum);

}
double Student::getAverage() const{
    return 0;
}
double Student::getHighest() const{
    return 0;
}
double Student::getLowest() const{
    return 0;
}
Status Student::getStatus() const{
    return Status::PASSING;
}
Student::Student(int id, string name, string birthDate){
    this->id = id;
    this->name = name;
    this->birthDate = birthDate;
}