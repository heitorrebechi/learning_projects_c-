#include "isValidDate.h"

bool isValidDate(const string& date){

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