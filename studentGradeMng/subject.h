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
        bool operator==(const Subject& other) const{
            return this->id == other.id;
        }
    Subject(int id, string name, string teacher);
};

namespace std {
    template <>
    struct hash<Subject> {
        size_t operator()(const Subject& sj) const{
            return hash<int>{}(sj.getId());
        }
    };
}

#endif