#include <iostream>
using namespace std;

class Animal{
    public:
        string especie;
        string habitat;
        string comida_fav;
        
    void moraEm(){
        cout << especie << " mora em " << habitat << endl;
    }
    void comer(){
        cout << especie << " come " << comida_fav << endl;
    }
};

class Castor: public Animal{
    public:
        void constroiCasa(){
            cout << especie << " constroi casa no rio" << endl;
        }
    Castor(string especie, string habitat, string comida_fav){
        this->especie = especie;
        this->habitat = habitat;
        this->comida_fav = comida_fav;
    }
};

class Aguia: public Animal{
    public:
        void voar(){
            cout << especie << " sabe voar" << endl;
        }
    Aguia(string especie, string habitat, string comida_fav){
        this->especie = especie;
        this->habitat = habitat;
        this->comida_fav = comida_fav;
    }
};

int main(){

    Castor castor("Castor", "Rio", "Madeira");
    castor.moraEm();
    castor.comer();
    castor.constroiCasa();

    Aguia aguia("Aguia", "Taiga", "Roedores");
    aguia.moraEm();
    aguia.comer();
    aguia.voar();

    return 0;
}