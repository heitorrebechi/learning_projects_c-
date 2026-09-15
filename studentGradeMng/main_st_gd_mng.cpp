#include "main_st_gd_mng.h"

int main(){

    vector<Student> students = {};
    vector<Subject> subjects = {};

    srand(time(0));

    while(true){
        int option = mainMenu();

        switch(option){
            case 1:
                studentMngMenu(students);
                break;
            case 2:
                subjectMngMenu(subjects);
                break;
            case 3:
                gradeMngMenu(students, subjects);
                break;
            case 4:
                studentReportMenu(students, subjects);
                break;
            case 5:
                break;
            case 0:
                cout << "Exiting...";
                return 0;
        }

    }

    return 0;
}
int mainMenu(){

    cout << "==========================" << endl;
    cout << "   Stuent Grade Manager   " << endl;
    cout << "==========================" << endl;
    cout << "1. Student Management" << endl;
    cout << "2. Subject Management" << endl;
    cout << "3. Grade Management" << endl;
    cout << "4. Student Report" << endl;
    cout << "5. Class Report" << endl;
    cout << "0. Exit" << endl;
    cout << "==========================" << endl;

    int option;
    while(true){
        cout << "Choose an option: ";
        cin >> option;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Option" << endl;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if(option < 0 || option > 5){
            cout << "Invalid Option" << endl;
        }
        else{
            return option;
        }
    }

}
void studentMngMenu(vector<Student>& students){

    while(true){
        cout << "==========================" << endl;
        cout << "         Students         " << endl;
        cout << "==========================" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Remove student" << endl;
        cout << "3. List all students" << endl;
        cout << "0. Exit" << endl;
        cout << "==========================" << endl;

        int option;
        while(true){
            cout << "Choose an option: ";
            cin >> option;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Option" << endl;
                continue;
            }
            
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if(option < 0 || option > 3){
                cout << "Invalid Option" << endl;
            }
            else{
                break;
            }
        }
        
        switch(option){
            case 1:
                addStudent(students);
                cout << "New student added" << endl;
                break;
            case 2:
                removeStudent(students);
                break;
            case 3:
                listAllStudents(students);
                break;
            case 0:
                return;
        }

    }

}
void addStudent(vector<Student>& students){
    
    int id = generateStudentId(students);

    string name;
    while(true){
        cout << "Enter student name: ";
        getline(cin, name);

        if(name.length() > 45){
            cout << "Invalid name, too long" << endl;
        }
        else{
            break;
        }
    }

    string birthDate;
    while(true){
        cout << "Enter birth date (YYYY-MM-DD): ";
        cin >> birthDate;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(!isValidDate(birthDate)){
            cout << "Invalid Date" << endl;
        }
        else{
            break;
        }
    }

    Student s(id, name, birthDate);

    students.push_back(s);

}
int generateStudentId(vector<Student>& students){

    while(true){
        int id = rand() % 5000 + 1;

        auto it = find_if(students.begin(), students.end(), [id](const Student& st){
            return st.getId() == id;
        });

        if(it == students.end()){
            return id;
        }
    }

}
bool isValidDate(string& date){

    const regex date_pattern(R"(^\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2]\d|3[01])$)");
    
    if(!regex_match(date, date_pattern)){
        return 0;
    }
    
    //0123456789
    //2008-02-02
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));

    time_t now = time(0);
    tm* today = localtime(&now);

    int currentYear = today->tm_year + 1900;
    int currentMonth = today->tm_mon + 1;
    int currentDay = today->tm_mday;

    if(year > currentYear){
        return 0;
    }
    else if(year == currentYear && month > currentMonth){
        return 0;
    }
    else if(year == currentYear && month == currentMonth && day > currentDay){
        return 0;
    }
    else if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
        if(month == 2 && day > 29){
            return 0;
        }
        else{
            return 1;
        }
    }
    else if(month == 2 && day > 28){
        return 0;
    }
    else{
        return 1;
    }

}
void removeStudent(vector<Student>& students){

    int id;
    while(true){
        cout << "Enter the ID of the student to remove(0 to exit): ";
        cin >> id;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Id" << endl;
            continue;
        }
        else if(id > 5000 || id < 0){
            cout << "Invalid Id" << endl;
            continue;
        }
        else if(id == 0){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        auto it = find_if(students.begin(), students.end(), [id](const Student& s){
            return s.getId() == id;
        });
        if(it == students.end()){
            cout << "Id not found" << endl;
        }
        else{
            students.erase(it);
            cout << "Student removed" << endl;
            return;
        }
    }

}
void listAllStudents(vector<Student>& students){

    if(students.empty()){
        cout << "Zero students found" << endl;
        return;
    }

    // STUDENTS
    cout << string(64, '-') << endl;

    cout << left
         << setw(6) << "ID"
         << setw(46) << "Name"
         << setw(12) << "Birth-Date" << endl;

    cout << string(64, '-') << endl;

    for(const Student& s: students){
        cout << left
             << setw(6) << s.getId()
             << setw(46) << s.getName()
             << setw(12) << s.getBirthDate() << endl;
    }

}
void subjectMngMenu(vector<Subject>& subjects){

    while(true){
        cout << "==========================" << endl;
        cout << "1. Add subject" << endl;
        cout << "2. Remove subject" << endl;
        cout << "3. List all subjects" << endl;
        cout << "0. Exit" << endl;
        cout << "==========================" << endl;

        int option;
        while(true){
            cout << "Choose an option: ";
            cin >> option;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid option" << endl;       
            }
            else if(option < 0 || option > 3){
                cout << "Invalid option" << endl;
            }
            else{
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }

        switch(option){
            case 1:
                addSubject(subjects);
                cout << "New subject added" << endl;
                break;
            case 2:
                removeSubject(subjects);
                break;
            case 3:
                listAllSubjects(subjects);
                break;
            case 0:
                return;
        }

    }

}
void addSubject(vector<Subject>& subjects){

    int id = generateSubjectId(subjects);

    string subjectName;
    while(true){
        cout << "Enter subject name: ";
        getline(cin, subjectName);

        if(subjectName.length() > 45){
            cout << "Invalid, subject name too long" << endl;
        }
        else{
            break;
        }
    }

    string teacher;
    while(true){
        cout << "Enter teacher name: ";
        getline(cin, teacher);

        if(teacher.length() > 45){
            cout << "Invalid, teacher's name too long" << endl;
        }
        else{
            break;
        }
    }

    Subject sj(id, subjectName, teacher);

    subjects.push_back(sj);

}
int generateSubjectId(vector<Subject>& subjects){

    while(true){
        int id = rand() % 5000 + 1;

        auto it = find_if(subjects.begin(), subjects.end(), [id](const Subject& sj){
            return sj.getId() == id;
        });

        if(it == subjects.end()){
            return id;
        }
    }

}
void removeSubject(vector<Subject>& subjects){

    int id;
    while(true){
        cout << "Enter subject Id (0 to exit): ";
        cin >> id;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Id" << endl;
            continue;
        }
        else if(id > 5000 || id < 0){
            cout << "Invalid Id" << endl;
            continue;
        }
        else if(id == 0){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        auto it = find_if(subjects.begin(), subjects.end(), [id](const Subject& sj){
            return sj.getId() == id;
        });

        if(it == subjects.end()){
            cout << "Id not found" << endl;
        }
        else{
            subjects.erase(it);
            cout << "Subject removed" << endl;
            return;
        }
    }

}
void listAllSubjects(vector<Subject>& subjects){

    if(subjects.empty()){
        cout << "Zero subjects found" << endl;
        return;
    }

    cout << string(98, '-') << endl;

    cout << left
         << setw(6) << "ID"
         << setw(46) << "Subject"
         << setw(46) << "Teacher" << endl;

    cout << string(98, '-') << endl;

    for(const Subject& sj: subjects){
        cout << left
             << setw(6) << sj.getId()
             << setw(46) << sj.getName()
             << setw(46) << sj.getTeacher() << endl;
    }

}
void gradeMngMenu(vector<Student>& students, vector<Subject>& subjects){

    while(true){
        cout << "==========================" << endl;
        cout << "          Grades          " << endl;
        cout << "==========================" << endl;
        cout << "1. Add grade" << endl;
        cout << "2. Remove a grade" << endl;
        cout << "3. Update grade" << endl;
        cout << "0. Exit" << endl;
        cout << "==========================" << endl;

        int option;
        while(true){
            cout << "Choose an option: ";
            cin >> option;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Option" << endl;
            }
            else if(option < 0 || option > 3){
                cout << "Invalid Option" << endl;
            }
            else{
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }

        switch(option){
            case 1:
                addGrade(students, subjects);
                break;
            case 2:
                removeGrade(students, subjects);
                break;
            case 3:
                updateGrade(students, subjects);
                break;
            case 0:
                return;
        }

    }

}
void addGrade(vector<Student>& students, vector<Subject>& subjects){

    if(students.empty()){
        cout << "There are no students" << endl;
        return;
    }
    if(subjects.empty()){
        cout << "There are no subjects" << endl;
        return;
    }

    Student* st = nullptr;
    if(!studentIdInput(students, st)){
        return;
    }

    Subject* sj = nullptr;
    if(!subjectIdInput(subjects, sj)){
        return;
    }

    int sjId = sj->getId();
    unordered_map<Subject, map<int, Grade>> stGrades = st->getGrades();
    int testNum;
    auto sjIt = stGrades.find(*sj);
    if(sjIt == stGrades.end()){ // Subject not assigned

        testNum = 1;

    }
    else{ // Subject already assigned
         
        map<int, Grade>& testGrades = sjIt->second;

        if(testGrades.size() == 4){
            cout << "The student already have 4 grades assigned for this subject" << endl;
            return;
        }

        testNum = getTestNum(testGrades, 1);

        if(testNum == 0){
            return;
        }

    }

    double score;
    while(true){
        cout << "Enter the test " << testNum << " score: ";
        cin >> score;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid score" << endl;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(score < 0 || score > 10){
            cout << "Score must be between 0-10" << endl;
        }
        else{
            break;
        }
    }

    string testDate;
    while(true){
        cout << "Enter test date: ";
        cin >> testDate;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(!isValidDate(testDate)){
            cout << "Invalid date" << endl;
        }
        else{
            break;
        }
    }

    Grade g(sjId, score, testDate);

    st->addGrade(*sj, testNum, g);

    cout << "Grade assigned" << endl;

}
void removeGrade(vector<Student>& students, vector<Subject>& subjects){

    if(students.empty()){
        cout << "There are no students" << endl;
        return;
    }
    if(subjects.empty()){
        cout << "There are no subjects" << endl;
        return;
    }

    Student* st = nullptr;
    if(!studentIdInput(students, st)){
        return;
    }

    if(st->getGrades().empty()){
        cout << st->getName() << " have no grades assigned" << endl;
    }

    Subject* sj = nullptr;
    if(!subjectIdInput(subjects, sj)){
        return;
    }

    int sjId = sj->getId();
    unordered_map<Subject, map<int, Grade>> stGrades = st->getGrades();
    
    auto sjIt = stGrades.find(*sj);
    map<int, Grade> testGrades = sjIt->second;

    int testNum;
    while(true){
        testNum = getTestNum(testGrades, 2);
        if(testNum == 0){
            return;
        }

        auto testIt = stGrades[*sj].find(testNum);
        if(testIt == stGrades[*sj].end()){
            cout << "Test not found within subject" << endl;
        }
        else{
            break;
        }
    }

    st->removeGrade(*sj, testNum);

    cout << "Grade removed" << endl;

}
void updateGrade(vector<Student>& students, vector<Subject>& subjects){

    if(students.empty()){
        cout << "There are no students" << endl;
        return;
    }
    
    if(subjects.empty()){
        cout << "There are no subjects" << endl;
        return;
    }

    Student* st;
    if(!studentIdInput(students, st)){
        return;
    }

    if(st->getGrades().empty()){
        cout << "The student have no grades assigned" << endl;
        return;
    }

    Subject* sj;
    if(!subjectIdInput(subjects, sj)){
        return;
    }

    int sjId = sj->getId();
    unordered_map<Subject, map<int, Grade>> stGrades = st->getGrades();

    auto sjIt = stGrades.find(*sj);
    map<int, Grade> testGrades = sjIt->second;
    if(testGrades.empty()){
        cout << "The student doesn't have any grades assigned for this subject" << endl;
        return;
    }

    int testNum;
    while(true){
        testNum = getTestNum(testGrades, 3);

        if(testNum == 0){
            return;
        }

        auto testIt = stGrades[*sj].find(testNum);
        if(testIt == stGrades[*sj].end()){
            cout << "Test not found" << endl;
        }
        else{
            break;
        }
    }

    int newScore;
    while(true){
        cout << "Enter the test new score: ";
        cin >> newScore;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid score" << endl;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(newScore < 0 || newScore > 10){
            cout << "Score must be between 0-10" << endl;
        }
        else{
            break;
        }
    }

    string newDate;
    while(true){
        cout << "Enter the test new date: ";
        cin >> newDate;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(!isValidDate(newDate)){
            cout << "Invalid Date" << endl;
        }
        else{
            break;
        }
    }

    Grade newGrade(sjId, newScore, newDate);

    st->updateGrade(*sj, testNum, newGrade);

    cout << "Grade updated" << endl;

}
bool studentIdInput(vector<Student>& students, Student*& st){

    int stId;
    while(true){
        cout << "Enter student Id (0 to exit): ";
        cin >> stId;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Id" << endl;
            continue;
        }
        else if(stId < 0 || stId > 5000){
            cout << "Invalid Id" << endl;
            continue;
        }
        else if(stId == 0){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return 0;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        auto stIt = find_if(students.begin(), students.end(), [stId](const Student& st){
            return st.getId() == stId;
        });

        if(stIt == students.end()){
            cout << "Id not found" << endl;
        }
        else{
            st = &(*stIt);
            return 1;
        }

    }

}
bool subjectIdInput(vector<Subject>& subjects, Subject*& sj){

    int sjId;
    while(true){
        cout << "Enter subject Id (0 to exit): ";
        cin >> sjId;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Id" << endl;
            continue;
        }
        else if(sjId < 0 || sjId > 5000){
            cout << "Invalid Id" << endl;
            continue;
        }
        else if(sjId == 0){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return 0;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        auto sjIt = find_if(subjects.begin(), subjects.end(), [sjId](const Subject& sj){
            return sj.getId() == sjId;
        });

        if(sjIt == subjects.end()){
            cout << "Id not found" << endl;
        }
        else{
            sj = &(*sjIt);
            return 1;
        }
    }

}
int getTestNum(map<int, Grade>& testGrades, int operation){

    int testNum;

    cout << "Select the test " << endl;
    cout << "1. Test 1" << endl;
    cout << "2. Test 2" << endl;
    cout << "3. Test 3" << endl;
    cout << "4. Test 4" << endl;
    cout << "0. Cancel" << endl;

    while(true){
        cout << "Select a test: ";
        cin >> testNum;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Option" << endl;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(testNum < 0 || testNum > 4){
            cout << "Invalid Option" << endl;
        }
        else if(testNum == 0){
            return 0;
        }
        
        auto it = testGrades.find(testNum);
        if(operation == 1){
            if(it != testGrades.end()){
                cout << "Grade for test " << testNum << " is already assigned" << endl;
            }
            else{
                return testNum;
            }
        }
        else if(operation == 2){
            return testNum;
        }
        else{
            return testNum;
        }

    }

    return 0;

}
void studentReportMenu(vector<Student>& students, vector<Subject>& subjects){

    while(true){
        cout << "==========================" << endl;
        cout << "      Student Report      " << endl;
        cout << "==========================" << endl;
        cout << "1. Search student by Id" << endl;
        cout << "0. Exit" << endl;
        cout << "==========================" << endl;
        
        int option;
        while(true){
            cout << "Choose an option: ";
            cin >> option;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid option" << endl;
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if(option < 0 || option > 1){
                cout << "Invalid option" << endl;
            }
            else{
                break;
            }
        }

        switch(option){
            case 1:
                showStudentReport(students, subjects);
                break;
            case 0:
                return;
        }

    }

}
void showStudentReport(vector<Student>& students, vector<Subject>& subjects){

    if(students.empty()){
        cout << "There are no students" << endl;
        return;
    }

    if(subjects.empty()){
        cout << "There are no subjects" << endl;
        return;
    }

    Student* st = nullptr;
    if(!studentIdInput(students, st)){
        return;
    }

    if(st->getGrades().empty()){
        cout << "The student have no grades assigned" << endl;
        return;
    }

    cout << string(120, '=') << endl;
    cout << "Student report: " << st->getName() << endl;
    cout << string(120, '-') << endl;

    cout << left
         << setw(46) << "Subject" << " | "
         << setw(5) << "T1" << " | "
         << setw(5) << "T2" << " | "  
         << setw(5) << "T3" << " | "  
         << setw(5) << "T4" << " | "
         << setw(5) << "Avg" << " | "
         << setw(8) << "Status" << endl;
    cout << string(120, '-') << endl;

    for(const auto& [subject, gradesMap]: st->getGrades()){
        
        string sjName = subject.getName();
        vector<double> scores;
        int nTests = 0;
        
        for(int i=1; i < 5; i++){
            auto itScore = gradesMap.find(i);

            if(itScore == gradesMap.end()){
                scores.push_back(0);
            }
            else{
                scores.push_back(itScore->second.getScore());
                nTests++;
            }

        }

        double avg = (scores[0] + scores[1] + scores[2] + scores[3]) / nTests;
        Status status = (avg >= 7.0? Status::Passing : Status::Failing);

        cout << left
             << setw(46) << sjName << " | "
             << setw(5) << fixed << setprecision(1) << scores[0] << " | "
             << setw(5) << fixed << setprecision(1) << scores[1] << " | "
             << setw(5) << fixed << setprecision(1) << scores[2] << " | "
             << setw(5) << fixed << setprecision(1) << scores[3] << " | "
             << setw(5) << fixed << setprecision(1) << avg << " | "
             << setw(8) << status << endl;

    }

}
