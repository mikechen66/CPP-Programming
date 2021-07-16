
/* Application of the Struct array */

#include<iostream>
#include<string>
using namespace std;

struct student{  // the elements of the structs      
    int number;
    int score;
    string name; 
}; 

int main(void){
    student s[4]={{1, 100, "Mike Lee"}, //Declare and initialize the struct array
                  {2, 98,  "Jeff Dean"},
                  {3, 95,  "Steve Jobs"},
                  {4, 92,  "Dennis Ritchie"},
        }; 
    for (int i=0; i<4; i++){
        cout<<"Seat_Number.:"<<s[i].number<<endl;
        cout<<"Name:"<<s[i].name<<"\t"<<"Score:"<<s[i].score<<endl;
    }
    return 0;
}



/* Output */

/*
Seat_Number.:1
Name:Mike Lee   Score:100
Seat_Number.:2
Name:Jeff Dean  Score:98
Seat_Number.:3
Name:Steve Jobs Score:95
Seat_Number.:4
Name:Dennis Ritchie     Score:92
 */