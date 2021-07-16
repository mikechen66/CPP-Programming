
/* Execute switch-case statement */

#include<iostream>
using namespace std;

int main(void){
    int a,b;
    cout<<"==============================================="<<endl;
    cout<<"Integer four operations"<<endl;
    cout<<"Please input two numbers:"; 
    cin>>a>>b;
    cout<<"Please input the necessaryoperator (+,-,*,/):";
    char s;
    cin>>s;

    switch(s){
        case '+':
            cout<<a<<"+"<<b<<"="<<a+b<<endl;
            break;
        case '-':
            cout<<a<<"-"<<b<<"="<<a-b<<endl;
            break;
        case '*': 
            cout<<a<<"*"<<b<<"="<<a*b<<endl;
            break;
        case '/':
            cout<<a<<"/"<<b<<"="<<a/b<<endl;
            break;
        default:
            cout<<"Input error"<<endl;
            break;
    } 
    return 0;
}


/* Output */

/*
===============================================
Integer four operations
Please input two numbers:21 23
Please input the necessaryoperator (+,-,*,/):+
21+23=44
 */