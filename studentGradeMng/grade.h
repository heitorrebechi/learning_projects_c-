#ifndef GRADE_H
#define GRADE_H

#include <iostream>
using namespace std;

class Grade{
    private:
        int studentId;
        int subjectId;
        int testNum;
        double score;
        string date;
    public:
        int getStudentId() const;
        int getSubjectId() const;
        int getTestNum() const;
        double getScore() const;
        string getDate() const;
    Grade(int studentId, int subjectId, int testNum, double score, string date="____-__-__");
};

#endif