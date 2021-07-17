
/* Implement the queue with using a linkedlist */

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

class Node{
   public:
   int data;
   class Node *next;
};

typedef class Node QueueNode;
typedef QueueNode *QueueByLinkedList;
QueueByLinkedList front=NULL;
QueueByLinkedList rear=NULL;

void enqueue(int value) {
    QueueByLinkedList node;    /* Create a node */
    node=new QueueNode;
    node->data=value;
    node->next=NULL;

    if (rear==NULL)            /* Check wether the node is empty */
        front=node;            /* The newly-created node is the 1st node */
    else
        rear->next=node;       /* Join the node into the tail of the queue */
    rear=node;                 /* Make the tail ptr pointo to the newly-joined node */
}

int dequeue() {
    int value;

    if (!(front==NULL)) {      /* Check wether the node is empty */
        if (front==rear) 
            rear=NULL;
        value=front->data;     /* Take a data item out of the queue */
        front=front->next;     /* Make the front ptr point to the next */
        return value;
    } else {
        return -1;
    }
}

int main(void) {
    int temp;
    cout<<"Implement the queue with linkedlist"<<endl;
    cout<<"=========================================="<<endl;
    cout<<"Please add the first data item valuing 1"<<endl;
    enqueue(1);
    cout<<"Please add the second data item valuing 3"<<endl;
    enqueue(3);
    cout<<"Please add the third data item valuing 5"<<endl;
    enqueue(5);
    cout<<"Please add the fourth data item valuing 7"<<endl;
    enqueue(7);
    cout<<"Please add the fifth data item valuing 9"<<endl;
    enqueue(9);
    cout<<"=============================================================="<<endl;
    while (1) {
        if (!(front==NULL)) {
            temp=dequeue();
            cout<<"The element of being taken out of the front of the queue is: "<<setw(1)<<temp<<endl;
        } else {
            break;
        }
   }
   cout<<endl;
   return 0;
}


/* Output */

/*
Implement the queue with linkedlist
==========================================
Please add the first data item valuing 1
Please add the second data item valuing 3
Please add the third data item valuing 5
Please add the fourth data item valuing 7
Please add the fifth data item valuing 9
==============================================================
The element of being taken out of the front of the queue is: 1
The element of being taken out of the front of the queue is: 3
The element of being taken out of the front of the queue is: 5
The element of being taken out of the front of the queue is: 7
The element of being taken out of the front of the queue is: 9

 */