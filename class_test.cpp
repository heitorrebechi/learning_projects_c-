#include <iostream>
using namespace std;

class Human{
    public:
        string name;
        int age;

        void eat(){
            cout << name << " is eating" << endl;
        }
        void verifyAge(){
            if(age >= 18){
                cout << name << " is allowed to drive" << endl;
            }
            else{
                cout << name << " is NOT allowed to drive" << endl;
            }
        }

    Human(string name, int age){
        this->name = name;
        this->age = age;
    }
};

class Account{
    private:
        string email;
        string cpf;
    
    public:
        string getEmail(){
            return email;
        }
        string getCpf(){
            return cpf;
        }
        void changeEmail(string email){
            this->email = email;
        }

    Account(string email, string cpf){
        this->email = email;
        this->cpf = cpf;
    }
};

int main(){

    Human h("Heitor", 18);

    h.eat();
    h.verifyAge();

    Account a("h@gmail.com", "107.484.389-47");

    cout << "Email: " << a.getEmail() << endl;
    cout << "CPF: " << a.getCpf() << endl;

    a.changeEmail("heitor@outlook.com");

    cout << "New Email: " << a.getEmail() << endl;


    return 0;
}