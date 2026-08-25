#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <limits>
using namespace std;

struct To_do_list{
    int id;
    string title;
    string description;
    enum Status {Pending, InProgress, Done};
    Status status;
    enum Priority {Low, Medium, High};
    Priority priority;
};

int mainMenu();
To_do_list addTask(const vector<To_do_list>& tasks);
int removeTask(const vector<To_do_list>& tasks);
int getId(const vector<To_do_list>& tasks);
int changeStatus(const vector<To_do_list>& tasks, int index);
void showTasks(const vector<To_do_list>& tasks);
int generateId(const vector<To_do_list>& tasks);
string getStatus(To_do_list task);
string getPriority(To_do_list task);
int checkId(const vector<To_do_list>& tasks, int tempId);

int main(){

    srand(time(0));

    vector<To_do_list> tasks = {};

    int option;

    while(true){
        option = mainMenu();    

        if(option == 1){
            tasks.push_back(addTask(tasks));
        } else if(option == 2){
            int index = removeTask(tasks);

            if(index >= 0){
                tasks.erase(tasks.begin() + index);
            }
        
        } else if(option == 3){

            int i = getId(tasks);

            if(i >= 0){
                int tempStatus = changeStatus(tasks, i);

                switch(tempStatus){
                    case 0:
                        tasks[i].status = To_do_list::Pending;
                        break;
                    case 1:
                        tasks[i].status = To_do_list::InProgress;
                        break;
                    case 2:
                        tasks[i].status = To_do_list::Done;
                        break;
                }

                cout << "New status saved!" << endl;
            }
            
        } else if(option == 4){
            showTasks(tasks);
        } else {
            cout << "Exiting...";
            break;
        }
    }

    return 0;
}

int mainMenu(){
    cout << "===== To-do List =====" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. Remove Task" << endl;
    cout << "3. Change Task Status" << endl;
    cout << "4. Show Tasks" << endl;
    cout << "0. Exit" << endl;
    cout << "======================" << endl;

    int choice;

    while(true){
        cout << "Choose an option: ";
        cin >> choice;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Answer" << endl;
        }
        else if(choice < 0 || choice > 4){
            cout << "Invalid Option" << endl;
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
    }
}
To_do_list addTask(vector<To_do_list>& tasks){
    
    To_do_list task;
    
    while(true){
        int tempId = generateId(tasks);
        if(tempId != 0){
            task.id = tempId; 
            break;
        }
    }

    string tempTitle;
    cout << "Enter the Task Title: ";
    getline(cin, tempTitle);
    task.title = tempTitle;

    string tempDesc;
    cout << "Enter the Task description: ";
    getline(cin, tempDesc);
    task.description = tempDesc;

    task.status = To_do_list::Pending;

    while(true){
        int tempPriority;
        cout << "Set a priority (1.Low | 2.Medium | 3.High): ";
        cin >> tempPriority;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Option" << endl;
        }
        else if(tempPriority == 1){
            task.priority = To_do_list::Low;
            break;
        }
        else if(tempPriority == 2){
            task.priority = To_do_list::Medium;
            break;
        }
        else if(tempPriority == 3){
            task.priority = To_do_list::High;
            break;
        }
        else{
            cout << "Invalid Option" << endl;
        }
    }

    return task;
}
int generateId(const vector<To_do_list>& tasks){
    
    int id = rand() % 5000 + 1;
    for(int i=0; i<tasks.size(); i++){
        if(id == tasks[i].id){
            return 0;
        }
    }
    
    return id;

}
int removeTask(const vector<To_do_list>& tasks){

    int tempId;

    while(true){
        cout << "Insert Id of the task you want to remove (0 to exit): ";
        cin >> tempId;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Id" << endl;
        }
        else if(tempId == 0){
            return -1;
        }
        else{
            int index = checkId(tasks, tempId);

            if(index >= 0){
                cout << "Task with Id " << tempId << " was removed" << endl;
                return index;
            }
            else{
                cout << "Id not found" << endl;
            }
        }
    }

    return -1;

}
int checkId(const vector<To_do_list>& tasks, int tempId){

    for(int i=0; i < tasks.size(); i++){
        if(tempId == tasks[i].id){
            return i;
        }
    }

    return -1;

}
int getId(const vector<To_do_list>& tasks){
    
    int tempId;

    while(true){
        cout << "Insert Id of the task you want to change(0 to cancel): ";
        cin >> tempId;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Answer" << endl;
            continue;
        }
        else if(tempId == 0){
            return -1;
        }
        
        if(checkId(tasks, tempId) >= 0){
            return checkId(tasks, tempId);
        }
        else{
            cout << "Invalid Id" << endl;
        }

    }

}
int changeStatus(const vector<To_do_list>& tasks, int index){
    while(true){
        int tempStatus;

        cout << "Choose the new status(1. Pending | 2. In Progress | 3. Done): ";
        cin >> tempStatus;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Option" << endl;
        }
        else if(tempStatus < 1 || tempStatus > 3){
            cout << "Invalid Option" << endl;
        }
        else if(tasks[index].status == tempStatus - 1){
            cout << "The task is already " << getStatus(tasks[index]) << endl;
        }
        else{
            return tempStatus - 1;
        }
    }
}
void showTasks(const vector<To_do_list>& tasks){

    cout << "-------------------------------------------------------" << endl;

    if(tasks.size() == 0){
        cout << "There are no tasks" << endl;
    }

    for(int i=0; i<tasks.size(); i++){
        cout << "|" << tasks[i].id << "|" << getStatus(tasks[i]) << "|" << tasks[i].title << "|" << tasks[i].description << "|" << getPriority(tasks[i]) << "|" << endl;
        cout << "-------------------------------------------------------" << endl;
    }

}
string getStatus(To_do_list task){
    
    switch(task.status){
        case 0:
            return "Pending";
        case 1:
            return "In Progress";
        case 2:
            return "Done";
    }

    return "";

}
string getPriority(To_do_list task){
    
    switch(task.priority){
        case 0:
            return "Low";
        case 1:
            return "Medium";
        case 2:
            return "High";
    }

    return "";

}