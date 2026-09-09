#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
using namespace std;

class Subject{
    private:
        int id;
        string name;
        string teacher;
    public:
        int getId() const;
        string getName() const;
        string getTeacher() const;
    Subject(int id, string name, string teacher);
};


#endif