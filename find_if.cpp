#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isEven(int n){
    return (n % 2) == 0;
}

int main(){

    vector<int> data = {3, 8, 7, 9};

    auto it = find_if(data.begin(), data.end(), isEven);

    cout << "First even element is " << *it << endl;

    data.erase(it);

    for(const int d: data){
        cout << d << endl;
    }

    return 0;
}