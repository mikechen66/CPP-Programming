/*
CH01_01.cpp
Fibonacci recursion for multiplication
*/

#include <iostream>
using namespace std;

int recursive(int);  //º¯ÊýÔ­ÐÍ
int main(void) {  
    for (int i=0; i<16; i++)
        cout<<"The "<<i<<"th the factorial value is "<<recursive(i)<<endl;
    system("pause");      
    return 0;
}

int recursive(int i) {  
    int sum;
    if (i == 0)                     //set the basic condition
        return(1);
    else
        sum = i * recursive(i-1);   //sum = n * (n-1)! 
    return sum;
}


/* Output */

/* 
The 11th the factorial value is 39916800
The 12th the factorial value is 479001600
The 13th the factorial value is 1932053504
The 14th the factorial value is 1278945280
The 15th the factorial value is 2004310016
sh: 1: pause: not found
 */