#ifndef FILE_H
#define FILE_H

#include "grade.h"
#include "subject.h"
#include "student.h"
#include "isValidDate.h"
#include <fstream>
#include <sstream>
#include <iomanip>

inline const string ST_FILE = "students.txt";
inline const string SJ_FILE = "subjects.txt";
inline const string GRADES_FILE = "grades.txt";

void loadStudents(vector<Student>& students);
void loadSubjects(vector<Subject>& subjects);
void loadGrades(vector<Student>& students, vector<Subject>& subjects);
void saveStudents(const vector<Student>& students);
void saveSubjects(const vector<Subject>& subjects);
void saveGrades(const vector<Student>& students);

#endif