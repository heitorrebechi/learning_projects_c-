#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){

    unordered_map<string, int> storage;

    storage["banana"] = 5;
    storage["apple"] = 10;
    storage["pineapple"] = 3;
    storage["coconut"] = 0;

    cout << "Fruit    | Quantity" << endl;
    for(const auto& [fruit, qty]: storage){
        cout << fruit << "  |  " << qty << endl;
    }

    return 0;
}