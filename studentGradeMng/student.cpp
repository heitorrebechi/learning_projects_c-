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
const unordered_map<Subject, map<int, Grade>>& Student::getGrades() const{
    return grades;
}
void Student::addGrade(Subject sj, int testNum, Grade g){

    grades[sj].insert({testNum, g});

}
void Student::removeGrade(Subject sj, int testNum){

    grades[sj].erase(testNum);

}
void Student::updateGrade(Subject sj, int testNum, Grade newGrade){

    auto it = grades[sj].find(testNum);

    if(it != grades[sj].end()){
        it->second = newGrade;
    }
    else{
        grades[sj].insert({testNum, newGrade});
    }

}
double Student::getAverage(const Subject& sj, vector<double>* scores) const{

    auto sjIt = grades.find(sj);
    if(sjIt == grades.end()) return 0.0;
    const map<int, Grade>& gradesMap = sjIt->second;

    double total = 0.0;

    for(int i=1; i <= 4; i++){
        auto itScore = gradesMap.find(i);
        double score = (itScore == gradesMap.end()? 0.0 : itScore->second.getScore());

        total += score;

        if(scores != nullptr){
            scores->push_back(score);
        }
    }

    if(gradesMap.empty()) return 0.0;
    return total / gradesMap.size();

}
double Student::getHighest() const{
    return 0;
}
double Student::getLowest() const{
    return 0;
}
Student::Student(int id, string name, string birthDate){
    this->id = id;
    this->name = name;
    this->birthDate = birthDate;
}