
/* Basic Stack Operation */

#include <iostream>
#include <iomanip>
#define MAXSTACK 100                                

using namespace std;

int stack[MAXSTACK];                               
int top=-1;     

int isEmpty() {
    if (top==-1) return 1;
    else 
        return 0;
}

int push(int data) {
    if (top>=MAXSTACK) {
        cout<<"The stack is full and can not be pushed"<<endl;
        return 0; 
    } else {
       stack[++top]=data;                            
        return 1;   
    }
}

int pop() {
    if (isEmpty())                                     
        return -1;
    else
        /* Move the stack pointer down after a data item pops up */
        return stack[top--];  
}

int main(void) {
    int value;
    int i;
    cout<<"Please input 10 data items in order: "<<endl;
    for (i=0;i<10;i++) {
        cin>>value;
        push(value);
    }
    cout<<"===================="<<endl;
    while (!isEmpty())                                  
        cout<<"The pop-up order is: "<<setw(2)<<pop()<<endl; 
    cout<<"===================="<<endl;   
    return 0; 
}


/* Output */

/*
Please input 10 data items in order: 
 */