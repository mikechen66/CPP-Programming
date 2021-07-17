
/* Swap the numbers */

#include<iostream>
using namespace std;

int sum(int &,int&);   //Address-passing function */

int main(void){
    int main_a, main_b;
    cout<<"Please input two numbers: ";
    cin>>main_a>>main_b; 
    cout<<"Before function calling:"<<endl;
    cout<<"main_a="<<main_a<<"\t"<<"main_b="<<main_b<<endl;
    cout<<main_a<<"+"<<main_b<<"="<<sum(main_a,main_b)<<endl;   
    cout<<"Before function clalling :"<<endl;
    cout<<"main_a="<<main_a<<"\t"<<"main_b="<<main_b<<endl;
    return 0;
}

int sum(int &a, int &b){
    int sum = a+b;
    int temp; 

    temp=a; //Swap a and b
    a=b;
    b=temp;
    cout<<"Inside the function\na="<<a<<"\t"<<"b="<<b<<endl;
    return sum; 
}


/* Output */

/*
Please input two numbers: 21  23
Before function calling:
main_a=21       main_b=23
Inside the function
a=23    b=21
23+21=44
Before function calling :
main_a=23       main_b=21
 */