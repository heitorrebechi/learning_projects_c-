#include "subject.h"

int Subject::getId() const{
    return id;
}
string Subject::getName() const{
    return name;
}
string Subject::getTeacher() const{
    return teacher;
}
Subject::Subject(int id, string name, string teacher){
    this->id = id;
    this->name = name;
    this->teacher = teacher;
}