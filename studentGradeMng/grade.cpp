#include "grade.h"

int Grade::getSubjectId() const{
    return subjectId;
}
double Grade::getScore() const{
    return score;
}
string Grade::getDate() const{
    return date;
}
Grade::Grade(int subjectId, double score, string date){
    this->subjectId = subjectId;
    this->score = score;
    this->date = date;
}