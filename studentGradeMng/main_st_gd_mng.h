#ifndef MAIN_H
#define MAIN_H

#include "subject.h"
#include "student.h"
#include "grade.h"
#include "subject.cpp"
#include "student.cpp"
#include "grade.cpp"
#include <ctime>
#include <string>
#include <regex>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <unordered_map>
#include <map>

int mainMenu();
void studentMngMenu(vector<Student>& students);
void addStudent(vector<Student>& students);
int generateStudentId(vector<Student>& students);
bool isValidDate(string& date);
void removeStudent(vector<Student>& students);
void listAllStudents(vector<Student>& students);
void subjectMngMenu(vector<Subject>& subjects);
void addSubject(vector<Subject>& subjects);
int generateSubjectId(vector<Subject>& subjects);
void removeSubject(vector<Subject>& subjects);
void listAllSubjects(vector<Subject>& subjects);
void gradeMngMenu(vector<Student>& students, vector<Subject>& subjects);
void addGrade(vector<Student>& students, vector<Subject>& subjects);
void removeGrade(vector<Student>& students, vector<Subject>& subjects);
void updateGrade(vector<Student>& students, vector<Subject>& subjects);
bool studentIdInput(vector<Student>& students, Student*& st);
bool subjectIdInput(vector<Subject>& subjects, Subject*& sj);
int getTestNum(map<int, Grade>& testGrades, int operation);
void studentReportMenu(vector<Student>& students, vector<Subject>& subjects);
void showStudentReport(vector<Student>& students, vector<Subject>& subjects);

#endif