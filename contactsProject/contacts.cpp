#include "contact.h"

int main(){

    srand(time(0));

    vector<Contact> contacts = {};
    if(!loadContacts(contacts)){
        return 0;
    }

    while(true){
        int option = mainMenu();

        switch(option){
            case 1:
                addContact(contacts);
                save(contacts);
                break;
            case 2:
                if(removeContact(contacts)){
                    cout << "Contact deleted" << endl;
                    save(contacts);
                }
                break;
            case 3:
                listContacts(contacts);
                break;
            case 4:
                searchContactByName(contacts);
                break;
            case 0:
                return 0;
        }

    }

    return 0;
}
bool loadContacts(vector<Contact>& contacts){
    
    ifstream file(CFILE);

    if(!file.is_open()){
        cout << "Error loading Contacts file" << endl;
        return 0;
    }

    string line;
    while(getline(file, line)){
        stringstream ss(line);
        string token;
        Contact c;

        getline(ss, token, '|');
        c.id = stoi(token);
        getline(ss, token, '|');
        c.name = token;
        getline(ss, token, '|');
        c.phone = token;
        getline(ss, token, '|');
        c.email = token;
        getline(ss, token, '|');
        c.category = token;

        contacts.push_back(c);
    }

    file.close();

    return 1;

}
int mainMenu(){
    
    cout << "===== Contact List =====" << endl;
    cout << "1. Add Contact" << endl;
    cout << "2. Remove Contact" << endl;
    cout << "3. List All Contacts" << endl;
    cout << "4. Search by Name" << endl;
    cout << "0. Exit " << endl;

    int option;
    while(true){
        cout << "Choose an option: ";
        cin >> option;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Option" << endl;
        }
        else if(option < 0 || option > 4){
            cout << "Invalid Option" << endl;
        }
        else{
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return option;
        }
    }

}
bool save(const vector<Contact>& contacts){

    ofstream file(CFILE);

    if(!file.is_open()){
        cout << "Error saving contacts file" << endl;
        return 0;
    }

    for(const Contact c: contacts){
        file << c.id << "|" << c.name << "|" << c.phone << "|" << c.email << "|" << c.category << '\n';
    }

    file.close();

    return 1;

}
void addContact(vector<Contact>& contacts){

    Contact c;

    // Id:
    while(true){
        int id = rand() % 5000 + 1;
        if(checkId(contacts, id)){
            c.id = id;
            break;
        }
    }

    // Name:
    string name;
    while(true){
        cout << "Enter a name for the contact: ";
        getline(cin, name);
        if(!name.empty()){
            c.name = name;
            break;
        }
        
        cout << "The contact must have a name" << endl;

    }

    // Phone:
    while(true){
        string phone;
        cout << "Enter the phone number (only numbers):";
        getline(cin, phone);

        if(checkPhone(contacts, phone)){
            c.phone = formatPhone(phone);
            break;
        }

    }

    // Email
    while(true){
        string email;
        cout << "Enter the contact email: ";
        cin >> email;

        if(checkEmail(email)){
            c.email = email;
            break;
        }
        else{
            cout << "Invalid email" << endl;
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Category
    string category;
    while(true){
        cout << "Enter the contact category (Ex. Friend, Family, Other): ";
        getline(cin, category);
        if(!category.empty()){
            c.category = category;
            break;
        }

        cout << "You must insert a category" << endl;

    }

    // Confirm
    while(true){
        char confirm;
        cout << "Confirm new contact (y/n)?: ";
        cin >> confirm;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Option" << endl;
        }
        else if(tolower(confirm) == 'y'){
            contacts.push_back(c);
            break;
        }
        else if(tolower(confirm) == 'n'){
            cout << "Canceled" << endl;
            break;
        }
        else{
            cout << "Invalid Option" << endl;
        }

    }

}
bool checkId(const vector<Contact>& contacts, int id){

    for(const Contact c: contacts){
        if(c.id == id){
            return 0;
        }
    }

    return 1;

}
bool checkPhone(const vector<Contact>& contacts, const string& phone){

    for(const char n: phone){
        if(!isdigit(n)){
            cout << "The phone must contain only digits" << endl;
            return 0;
        }
    }

    if(phone.length() != 11 && phone.length() != 10){
        cout << "Invalid phone size" << endl;
        return 0;
    }

    int ddd = stoi(phone.substr(0, 2));
    if(!checkDDD(ddd)){
        cout << "Invalid Phone DDD" << endl;
        return 0;
    }

    if(phone.length() == 11){
        if(phone[2] != '9'){
            cout << "Invalid Phone number" << endl;
            return 0;
        }
    }

    if(phone.length() == 10){
        int fdigit = phone[2] - '0';
        if(fdigit < 2 || fdigit > 5){
            cout << "Invalid Phone number 'fix'" << endl;
            return 0;
        }
    }

    for(const Contact c: contacts){
        if(formatPhone(phone) == c.phone){
            cout << "Phone already registered" << endl;
            return 0;
        }
    }

    return 1;

}
bool checkDDD(int ddd){
    for(const int n: ddds){
        if(n == ddd){
            return 1;
        }
    }

    return 0;
}
string formatPhone(const string& phone){

    int len = phone.length();

    if(len == 11){
        return "(" + phone.substr(0, 2) + ") " + phone.substr(2, 5) + "-" + phone.substr(5, 4);
    }

    if(len == 10){
        return "(" + phone.substr(0, 2) + ") " + phone.substr(2, 4) + "-" + phone.substr(5, 4);
    }

    return "";
    
}
bool checkEmail(const string& email){

    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    return regex_match(email, pattern);

}
bool removeContact(vector<Contact>& contacts){

    while(true){
        int id;
        cout << "Insert Id of contact to remove: ";
        cin >> id;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Id" << endl;
            continue;
        }

        for(int i=0; i < contacts.size(); i++){
            if(contacts[i].id == id){
                contacts.erase(contacts.begin() + i);
                return 1;
            }
        }

        cout << "Id not found" << endl;
    }

    return 0;

}
void listContacts(const vector<Contact>& contacts){

    if(contacts.empty()){
        cout << "No contacts found" << endl;
        return;
    }

    for(const Contact& c: contacts){
        cout << c.id << "|" << c.name << "|" << c.phone << "|" << c.email << "|" << c.category << endl;
    }

}
void searchContactByName(const vector<Contact>& contacts){

    vector<Contact> ctSearch = {};

    string search;
    while(true){
        cout << "Search by name: ";
        getline(cin, search);
        if(search.empty()){
            cout << "You have to type something to search" << endl;
            continue;
        }
        
        break;

    }

    for(const Contact c: contacts){
        if(c.name.find(search) != string::npos){
            ctSearch.push_back(c);
        }
    }
    
    if(!ctSearch.empty()){
        cout << "Search results: " << endl;
        listContacts(ctSearch);
    }
    else{
        cout << "No contact with '" << search << "' was found" << endl;
    }

}
