
/* Output the address and value of pointer variable */

#include<iostream>
using namespace std;

int main(void){
    int x=100;
    int* y;
    y=&x;                              //Assign the address of x to the ptr variable y  
    cout<<"x="<<x<<endl;;
    cout<<"x's addres="<<&x<<endl;     //Use & to output the address of x 
    cout<<"y records="<<y<<endl;       
    cout<<"y points to the value of the pointed address="<<*y<<endl;  //Add the operator of * */
    return 0;
}


/* Output */

/* 
$g++ -o main *.cpp
$main
x=100
x's addres=0x7ffde3c6d0a4
y records=0x7ffde3c6d0a4
y points to the value of the pointed address=100
 */