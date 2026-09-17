#ifndef STUDENT_H
#define STUDENT_H

#include "grade.h"
#include "subject.h"
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>

enum class Status { Passing, Failing };

ostream& operator<<(ostream& os, Status status){
    switch(status){
        case Status::Passing:
            os << "Passing";
            break;
        case Status::Failing:
            os << "Failing";
            break;
    }

    return os;
    
}

class Student{
    private:
        int id;
        string name;
        string birthDate;
        unordered_map<Subject, map<int, Grade>> grades;
    public:
        int getId() const;
        string getName() const;
        string getBirthDate() const;
        const unordered_map<Subject, map<int, Grade>>& getGrades() const;
        void addGrade(Subject sj, int testNum, Grade g);
        void removeGrade(Subject sj, int testNum);
        void updateGrade(Subject sj, int testNum, Grade newGrade);
        double getAverage(const Subject& sj, vector<double>* scores = nullptr) const;
        double getHighest() const;
        double getLowest() const;
    Student(int id, string name, string birthDate);
};

#endif