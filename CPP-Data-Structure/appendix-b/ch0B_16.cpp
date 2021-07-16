
/* Derived class's declaration and usage */

#include<iostream>
// #include<string>
using namespace std;
class student{  // student is base class
    int num;
    char name[20]; 
    public :
    void setdata(){
        cout<<"Seat_Number:";cin>>num;
        cout<<"Name:";cin>>name;
    } 
    void show(){
        cout<<name<<"Seat_Number=\t"<<num<<endl; 
    } 
};

class s_health:public student{ //s_health is a derived class
}; 

int main(void){
    s_health sh[5]; 
    for (int i=1; i<5; i++){
        sh[i].setdata(); //Apply the base class's method
    }cout<<endl;
    for (int j=1; j<5; j++){
        sh[j].show();    //Apply the base class's method
    }
    cout<<endl;
    return 0;
}



/* Output */

/*
Seat_Number:1
Name:Jobs
Seat_Number:2
Name:Ritchie
Seat_Number:3    
Name:Stephen
Seat_Number:4
Name:Jordan

JobsSeat_Number=        1
RitchieSeat_Number=     2
StephenSeat_Number=     3
JordanSeat_Number=      4
 */
