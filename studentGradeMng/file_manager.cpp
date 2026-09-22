#include "file_manager.h"

void loadStudents(vector<Student>& students){

    ifstream file(ST_FILE);

    if(!file.is_open()){
        cout << "Unable to open students file" << endl;
        return;
    }

    // file must be:
    // id|name|birthDate

    string line;
    while(getline(file, line)){
        stringstream ss(line);
        string token;

        int id;
        string name;

        getline(ss, token, '|');
        try{
            id = stoi(token);
        }
        catch(const invalid_argument& e){
            continue;
        }

        getline(ss, token, '|');
        if(!token.empty()){
            name = token;
        }
        else{
            continue;
        }

        getline(ss, token, '|');
        if(isValidDate(token)){
            students.push_back(Student(id, name, token));
        }
        else{
            students.push_back(Student(id, name));
        }
    }

    file.close();

}
void loadSubjects(vector<Subject>& subjects){

    ifstream file(SJ_FILE);

    if(!file.is_open()){
        cout << "Unable to open subjects file" << endl;
        return;
    }

    // file must be:
    // id|name|teacher

    string line;
    while(getline(file, line)){
        stringstream ss(line);
        string token;

        int id;
        string name;
        string teacher;

        getline(ss, token, '|');
        try{
            id = stoi(token);
        }
        catch(const invalid_argument& e){
            continue;
        }

        getline(ss, token, '|');
        if(!token.empty()){
            name = token;
        }
        else{
            continue;
        }

        getline(ss, token, '|');
        if(!token.empty()){
            teacher = token;
        }
        else{
            continue;
        }

        subjects.push_back(Subject(id, name, teacher));
    }

    file.close();

}
void loadGrades(vector<Student>& students, vector<Subject>& subjects){

    ifstream file(GRADES_FILE);

    if(!file.is_open()){
        cout << "Unable to open grades file" << endl;
        return;
    }

    // file must be:
    // studentId|subjectId|testNum|score|date

    string line;
    while(getline(file, line)){
        stringstream ss(line);
        string token;

        int stId;
        int sjId;
        int testNum;
        double score;
        string date;

        Student *st = nullptr;
        Subject *sj = nullptr;

        getline(ss, token, '|');
        try{
            stId = stoi(token);

            auto it = find_if(students.begin(), students.end(), [stId](const Student& st){
                return stId == st.getId();
            });
            if(it == students.end()){
                continue;
            }

            st = &(*it);
        }
        catch(const invalid_argument& e){
            continue;
        }

        getline(ss, token, '|');
        try{
            sjId = stoi(token);

            auto it = find_if(subjects.begin(), subjects.end(), [sjId](const Subject& sj){
                return sjId == sj.getId();                
            });
            if(it == subjects.end()){
                continue;
            }

            sj = &(*it);
        }
        catch(const invalid_argument& e){
            continue;
        }

        getline(ss, token, '|');
        try{
            testNum = stoi(token);

            if(testNum < 1 || testNum > 4){
                continue;
            }
            
            auto sjGradesIt = st->getGrades().find(*sj);
            if(sjGradesIt != st->getGrades().end()){
                auto testIt = sjGradesIt->second.find(testNum);
                if(testIt != sjGradesIt->second.end()){
                    continue;
                }
            }

        }
        catch(const invalid_argument& e){
            continue;
        }

        getline(ss, token, '|');
        try{
            score = stod(token);

            if(score < 0.0 || score > 10.0){
                continue;
            }
        }
        catch(const invalid_argument& e){
            continue;
        }

        getline(ss, token, '|');
        if(isValidDate(token)){
            st->addGrade(*sj, testNum, Grade(stId, sjId, testNum, score, token));
        }
        else{
            st->addGrade(*sj, testNum, Grade(stId, sjId, testNum, score));
        }
    }

    file.close();

}
void saveStudents(const vector<Student>& students){

    ofstream file(ST_FILE);

    if(!file.is_open()){
        cout << "Failed to save to students.txt" << endl;
        return;
    }

    // file must be:
    // id|name|birthDate

    for(const Student& st: students){
        file << st.getId() << "|" << st.getName() << "|" << st.getBirthDate() << '\n';
    }

    file.close();

}
void saveSubjects(const vector<Subject>& subjects){

    ofstream file(SJ_FILE);

    if(!file.is_open()){
        cout << "Failed to save to subjects.txt" << endl;
        return;
    }

    // file must be:
    // id|name|teacher

    for(const Subject& sj: subjects){
        file << sj.getId() << "|" << sj.getName() << "|" << sj.getTeacher() << '\n';
    }

    file.close();

}
void saveGrades(const vector<Student>& students){

    ofstream file(GRADES_FILE);

    if(!file.is_open()){
        cout << "Failed to save to grades.txt" << endl;
        return;
    }

    // file must be:
    // studentId|subjectId|testNum|score|date

    for(const Student& st: students){   
        for(const auto& [sj, gradesMap]: st.getGrades()){
            for(const auto& [testNum, g]: gradesMap){
                file << g.getStudentId() << "|" 
                     << g.getSubjectId() << "|" 
                     << testNum << "|"
                     << fixed << setprecision(1) << g.getScore() << "|" 
                     << g.getDate() << '\n';
            }
        }
    }

}