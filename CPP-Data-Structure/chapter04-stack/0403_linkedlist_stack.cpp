
/* Push and Pop Operation of the Stack */

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;
class Node {  
    public:
        int data;    
        class Node *next;           /* The stack points to the pointer at the next node */
};

typedef class Node Stack_Node;     /* Define new types in the nodes of the stack */
typedef Stack_Node *Linked_Stack;  /* Define the new type of stack in the linkedlist */
Linked_Stack top=NULL;             /* Point to the top of the stack */ 

int isEmpty() {
    if (top==NULL) 
        return 1;
    else 
        return 0;
}

void push(int data) {
    Linked_Stack new_add_node;     /* The pointer that newly joints at the node */
    new_add_node=new Stack_Node;   /* Allocate memory to the new node */
    new_add_node->data=data;       /* Assign value to the variable of the node */
    new_add_node->next=top;        /* Make the new node ptr point to the top of the stack*/
    top=new_add_node;              /* The new node is the top of the stack*/
}

int pop() {
    Linked_Stack ptr;              /* The ptr that points to the top of the stack */
    int temp;
    if (isEmpty()) {                /* If the stack is empty, it return -1 */
        cout<<"===It is an empty stack at present==="<<endl;
        return -1;
    } else {
        ptr=top;                   /* Point to the top of the stack */
        top=top->next;             /* The ptr points to the next node */
        temp=ptr->data;            /* Tke a data item out of the stack */
        free(ptr);                 /* Release the memory in the node */
        return temp;               /* Return temp to the main*/
    }
}

int main(void) {
    int value;
    int i;
    cout<<"Please input 10 data items in order: "<<endl;
    for (i=0;i<10;i++) {
        cin>>value;
        push(value);
    }
    cout<<"====================================="<<endl;
    while (!isEmpty())              
        cout<<"The pop-up order is: "<<setw(2)<<pop()<<endl; 
    cout<<"====================================="<<endl;     
    return 0; 
}


/* Output */

/* 
$g++ -o main *.cpp
$main
Please input 10 data items in order: 
=====================================
The pop-up order is: 4196496
The pop-up order is: 4196496
The pop-up order is: 4196496
The pop-up order is: 4196496
The pop-up order is: 4196496
The pop-up order is: 4196496
The pop-up order is: 4196496
The pop-up order is: 4196496
The pop-up order is: 4196496
The pop-up order is: 4196496
===================================== 
 */ 