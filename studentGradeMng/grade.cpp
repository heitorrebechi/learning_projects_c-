#include "grade.h"

int Grade::getStudentId() const{
    return studentId;
}
int Grade::getSubjectId() const{
    return subjectId;
}
int Grade::getTestNum() const{
    return testNum;
}
double Grade::getScore() const{
    return score;
}
string Grade::getDate() const{
    return date;
}
Grade::Grade(int studentId, int subjectId, int testNum, double score, string date){
    this->studentId = studentId;
    this->subjectId = subjectId;
    this->testNum = testNum;
    this->score = score;
    this->date = date;
}