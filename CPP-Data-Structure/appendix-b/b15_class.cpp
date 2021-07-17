
/* Declaration and usage of class */

#include<iostream>
#include<ctime>
using namespace std;

class myclock{
    public:            
        int sec, min, time;   //Data member 
        int setclock(int t,int m,int s){  //Member function
            sec=s;
            min=m;
            time=t;
    }
}; 

int main(void){
    myclock clock1;  //Declare an object
    cout<<"Current time = "<<__TIME__<<endl;
    cout<<"Please set ringing time: ";
    clock1.setclock(6,50,32);  //Choose member function
    cout<<clock1.time<<":"<<clock1.min<<":"<<clock1.sec<<endl;  
    cout<<"The alarm clock will ring on "<<clock1.time<<":"<<clock1.min<<":"<<clock1.sec<<endl;
    return 0;
}


/* Output */

/*
$g++ -o main *.cpp
$main
Current time=15:14:47
Please set ringing time: 6:50:32
The alarm clock will ring on 6:50:32
 */