#include <iostream>
#include <string>
using namespace std;

struct Node{
    int data;
    Node *prev;
    Node *next;
};

int mainMenu();
int dataInputMenu();
void pushBack(Node*& head, Node*& tail, int value);
void pushFront(Node*& head, Node*& tail, int value);
bool removeFront(Node*& head, Node*& tail);
bool removeBack(Node*& head, Node*& tail);
int getIndex(int len);
void insertAt(Node*& head, Node*& tail, int value, int len);
bool removeAt(Node*& head, Node*& tail, int len);
Node* find(Node*& head, int value);
void printForward(Node*& head);
void printBackwards(Node*& tail);
void clearList(Node*& head, Node*& tail);

int main(){

    Node *head = nullptr;
    Node *tail = nullptr;
    int len = 0;
    while(true){
    
        int option = mainMenu();

        switch(option){
            case 1:
                pushBack(head, tail, dataInputMenu());
                len++;
                break;
            case 2:
                pushFront(head, tail, dataInputMenu());
                len++;
                break;
            case 3:
                if(removeFront(head, tail)){
                    len --;
                }
                break;
            case 4:
                if(removeBack(head, tail)){
                    len--;
                }
                break;
            case 5:
                insertAt(head, tail, dataInputMenu(), len);
                len++;
                break;
            case 6:
                if(removeAt(head, tail, len)){
                    len--;
                }
                break;
            case 7:
                {Node* it = find(head, dataInputMenu());
                if(it != nullptr){
                    cout << it->data << endl;
                }
                else{
                    cout << "Node not found" << endl;
                }
                break;}
            case 8:
                printForward(head);
                break;
            case 9:
                printBackwards(tail);
                break;
            case 0:
                cout << "Exiting..." << endl;
                clearList(head, tail);
                return 0;
        }

    }

    return 0;
}
int mainMenu(){

    cout << string(20, '=') << endl;
    cout << "     Linked List     " << endl;
    cout << string(20, '=') << endl;
    cout << "1. Push Back" << endl;
    cout << "2. Push Front" << endl;
    cout << "3. Remove Front" << endl;
    cout << "4. Remove Back" << endl;
    cout << "5. Insert At" << endl; 
    cout << "6. Remove At" << endl;
    cout << "7. Find" << endl;
    cout << "8. Print Forward" << endl;
    cout << "9. Print Backwards" << endl;
    cout << "0. Exit" << endl;
    cout << string(20, '=') << endl;

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

        if(option < 0 || option > 9){
            cout << "Invalid Option" << endl;
            continue;
        }

        return option;
    }

}
int dataInputMenu(){

    int value;
    while(true){
        cout << "Enter the value to store/search: ";
        cin >> value;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input" << endl;
            continue;
        }

        break;

    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return value;

}
void pushBack(Node*& head, Node*& tail, int value){

    if(head == nullptr){
        head = new Node{value, nullptr, nullptr};
        tail = head;
        return;
    }

    Node *temp = tail;

    tail = new Node{value, temp, nullptr};
    temp->next = tail;

}
void pushFront(Node*& head, Node*& tail, int value){

    if(head == nullptr){
        head = new Node{value, nullptr, nullptr};
        tail = head;
        return;
    }

    Node *temp = head;
    head = new Node{value, nullptr, temp};
    temp->prev = head;

}
bool removeFront(Node*& head, Node*& tail){

    if(head == nullptr){
        cout << "There are no Nodes" << endl;
        return false;
    }
    if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
        cout << "Front Node deleted" << endl;
        return true;
    }

    Node *temp = head->next;

    delete head;

    temp->prev = nullptr;
    head = temp;

    cout << "Front Node deleted" << endl;

    return true;

}
bool removeBack(Node*& head, Node*& tail){

    if(head == nullptr){
        cout << "There are no Nodes" << endl;
        return false;
    }
    if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
        cout << "Back Node deleted" << endl;
        return true;
    }

    Node *temp = tail->prev;
    temp->next = nullptr;
    
    delete tail;

    tail = temp;

    cout << "Back Node deleted" << endl;

    return true;

}
void insertAt(Node*& head, Node*& tail, int value, int len){

    if(head == nullptr){
        pushFront(head, tail, value);
        cout << "List is empty, new node inserted at index 0" << endl;
        return;
    }

    int index = getIndex(len);

    if(index == 0){
        pushFront(head, tail, value);
        cout << "New node inserted at index 0" << endl;
        return;
    }
    if(index == len){
        pushBack(head, tail, value);
        cout << "New node inserted at index " << index << endl;
        return;
    }

    if(index < len / 2){

        Node *temp = head;
        Node *prevNode = nullptr;
        int itIndex = 0;

        while(itIndex != index){
            prevNode = temp;
            temp = temp->next;
            itIndex++;
        }

        temp = new Node{value, prevNode, temp};
        temp->next->prev = temp;
        prevNode->next = temp;

        cout << "New node inserted at index " << index << endl; 

    }
    else{

        Node *temp = tail;
        Node *nextNode = nullptr;
        int itIndex = len;

        while(itIndex != index){
            nextNode = temp;
            temp = temp->prev;
            itIndex--;
        }

        temp = new Node{value, temp, nextNode};
        temp->prev->next = temp;
        nextNode->prev = temp;

        cout << "New node inserted at index " << index << endl; 

    }

}
int getIndex(int len){

    int index;
    while(true){
        cout << "Enter index to insert/delete: ";
        cin >> index;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input" << endl;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(index < 0 || index > len){
            cout << "Index out of range" << endl;
            continue;
        }
        
        return index;

    }

}
bool removeAt(Node*& head, Node*& tail, int len){

    if(head == nullptr){
        cout << "There are no Nodes" << endl;
        return false;
    }

    int index = getIndex(len - 1);

    if(index == 0){
        return removeFront(head, tail);
    }
    if(index == len - 1){
        return removeBack(head, tail);
    }

    if(index < len / 2){

        Node *temp = head;
        int itIndex = 0;

        while(itIndex != index){
            temp = temp->next;
            itIndex++;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;

        cout << "Node at index " << index << " was deleted" << endl;

        return true;

    }
    else{

        Node *temp = tail;
        int itIndex = len - 1;

        while(itIndex != index){
            temp = temp->prev;
            itIndex--;
        }

        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;

        delete temp;

        cout << "Node at index " << index << " was deleted" << endl;

        return true;

    }

}
Node* find(Node*& head, int value){

    if(head == nullptr){
        cout << "There are no Nodes" << endl;
        return nullptr;
    }

    Node *temp = head;

    while(temp != nullptr && temp->data != value){
        temp = temp->next;
    }

    return temp;

}
void printForward(Node*& head){

    if(head == nullptr){
        cout << "There are no Nodes" << endl;
        return;
    }

    Node *temp = head;

    while(temp != nullptr){
        cout << temp->data << endl;
        temp = temp->next;
    }

}
void printBackwards(Node*& tail){

    if(tail == nullptr){
        cout << "There are no Nodes" << endl;
        return;
    }

    Node *temp = tail;

    while(temp != nullptr){
        cout << temp->data << endl;
        temp = temp->prev;
    }

}
void clearList(Node*& head, Node*& tail){

    if(head == nullptr){
        return;
    }

    Node *temp = head->next;
    while(temp != nullptr){
        delete head;
        head = temp;
        temp = temp->next;
    }

    delete head;
    head = nullptr;
    tail = nullptr;

}