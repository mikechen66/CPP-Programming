
/* 范例:ch0B_11.cpp
 * 说明:输出指针变量的地址与取值 
 */

#include<iostream>
using namespace std;

int main(void){
    int x=100;
    int* y;
    y=&x;                              //把x的地址赋值给指针变量y 
    cout<<"x="<<x<<endl;;
    cout<<"x's addres="<<&x<<endl;     //利用&输出x的地址 
    cout<<"y所记录="<<y<<endl;       
    cout<<"y所指向地址的值="<<*y<<endl;  //须加上*运算符才代表是数值
    return 0;
}


#include<iostream>
using namespace std;

int main(void){
    int x=100;
    int* y;
    y=&x;                              //Assign the address of x to the ptr variable y  
    cout<<"x="<<x<<endl;;
    cout<<"x's addres="<<&x<<endl;     //Use & to output the address of x 
    cout<<"y所记录="<<y<<endl;       
    cout<<"y所指向地址的值="<<*y<<endl;  //Add the operator of * */
    return 0;
}
