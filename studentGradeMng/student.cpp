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

    if(grades[sj].empty()){
        grades.erase(sj);
    }

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
double Student::getAverage(const Subject& sj) const{

    auto sjIt = grades.find(sj);
    if(sjIt == grades.end()) return -1.0;
    const map<int, Grade>& gradesMap = sjIt->second;

    double total = 0.0;
    double nScores = 0.0;

    for(int i=1; i <= 4; i++){
        auto itScore = gradesMap.find(i);
        if(itScore != gradesMap.end()){
            total += itScore->second.getScore();
            nScores += 1.0;
        }

    }

    if(nScores == 0) return -1.0;
    return total / nScores;

}
double Student::getGeneralAverage() const{

    vector<double> allAverages;

    for(const auto& [sj, gradesMap]: grades){
        allAverages.push_back(getAverage(sj));
    }

    if(allAverages.empty()) return -1.0;

    double totalAvg = 0.0;

    for(const double& avg: allAverages){
        totalAvg += avg;
    }

    return totalAvg / allAverages.size();

}
double Student::getHighest() const{

    vector<double> scores;

    for(const auto& [sj, gradesMap]: grades){
        for(const auto& [test, grade]: gradesMap){
            scores.push_back(grade.getScore());
        }
    }

    return *max_element(scores.begin(), scores.end());
    
}
double Student::getLowest() const{
    
    vector<double> scores;

    for(const auto& [sj, gradesMap]: grades){
        for(const auto& [test, grade]: gradesMap){
            scores.push_back(grade.getScore());
        }
    }

    return *min_element(scores.begin(), scores.end());

}
Student::Student(int id, string name, string birthDate){
    this->id = id;
    this->name = name;
    this->birthDate = birthDate;
}