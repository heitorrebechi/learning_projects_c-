#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
using namespace std;

const string CFILE = "contacts.txt";

const int ddds[67] = {
  11, 12, 13, 14, 15, 16, 17, 18, 19,
  21, 22, 24, 27, 28,
  31, 32, 33, 34, 35, 37, 38,
  41, 42, 43, 44, 45, 46, 47, 48, 49,
  51, 53, 54, 55,
  61, 62, 63, 64, 65, 66, 67, 68, 69,
  71, 73, 74, 75, 77, 79,
  81, 82, 83, 84, 85, 86, 87, 88, 89,
  91, 92, 93, 94, 95, 96, 97, 98, 99
};

bool checkDDD(int ddd);

struct Contact{
    int id;
    string name;
    string phone;
    string email;
    string category;
};

bool loadContacts(vector<Contact>& contacts);
int mainMenu();
bool save(const vector<Contact>& contacts);
void addContact(vector<Contact>& contacts);
bool checkId(const vector<Contact>& contacts, int id);
bool checkPhone(const vector<Contact>& contacts, const string& phone);
string formatPhone(const string& phone);
bool checkEmail(const string& email);
bool removeContact(vector<Contact>& contacts);
void listContacts(const vector<Contact>& contacts);
void searchContactByName(const vector<Contact>& contacts);

#endif