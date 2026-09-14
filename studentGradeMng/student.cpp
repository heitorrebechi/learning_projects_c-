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
unordered_map<Subject, map<int, Grade>> Student::getGrades() const{
    return grades;
}
void Student::addGrade(Subject sj, int testNum, Grade g){

    grades[sj].insert({testNum, g});

}
void Student::removeGrade(Subject sj, int testNum){

    grades[sj].erase(testNum);

}
void Student::updateGrade(Subject sj, int testNum, Grade newGrade){

    grades[sj][testNum] = newGrade;

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