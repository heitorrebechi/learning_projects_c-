#ifndef STUDENT_H
#define STUDENT_H

#include "grade.h"
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

enum class Status { PASSING, FAILING };

class Student{
    private:
        int id;
        string name;
        string birthDate;
        unordered_map<int, map<int, Grade>> grades;
    public:
        int getId() const;
        string getName() const;
        string getBirthDate() const;
        unordered_map<int, map<int, Grade>> getGrades() const;
        void addGrade(int sjId, int testNum, Grade g);
        void removeGrade(int sjId, int testNum);
        double getAverage() const;
        double getHighest() const;
        double getLowest() const;
        Status getStatus() const;
    Student(int id, string name, string birthDate);
};

#endif