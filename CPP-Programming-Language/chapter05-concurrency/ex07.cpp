#include <iostream>
#include <string>

using namespace std;

int main() {
    const char* monthNames[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    for (int i = 0; i < 12; i++) {
        cout << monthNames[i] << ": " << days[i] << " days" << endl;
    }

    struct month {
        const char *name;
        int days;
    };

    month months[] = {
        {"Jan", 31},
        {"Feb", 28},
        {"Mar", 31},
        {"Apr", 30},
        {"May", 31},
        {"Jun", 30},
        {"Jul", 31},
        {"Aug", 31},
        {"Sep", 30},
        {"Oct", 31},
        {"Nov", 30},
        {"Dec", 31}
    };

    for (int i = 0; i < 12; i++) {
        cout << months[i].name << ": " << months[i].days << " days" << endl;
    }
}



/* Output */

/*
$g++ -o main *.cpp
$main
Jan: 31 days
Feb: 28 days
Mar: 31 days
Apr: 30 days
May: 31 days
Jun: 30 days
Jul: 31 days
Aug: 31 days
Sep: 30 days
Oct: 31 days
Nov: 30 days
Dec: 31 days
Jan: 31 days
Feb: 28 days
Mar: 31 days
Apr: 30 days
May: 31 days
Jun: 30 days
Jul: 31 days
Aug: 31 days
Sep: 30 days
Oct: 31 days
Nov: 30 days
Dec: 31 days
 */