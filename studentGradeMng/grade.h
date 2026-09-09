#ifndef GRADE_H
#define GRADE_H

#include <iostream>
using namespace std;

class Grade{
    private:
        int subjectId;
        double score;
        string date;
    public:
        int getSubjectId() const;
        double getScore() const;
        string getDate() const;
    Grade(int subjectId, double score, string date);
};

#endif