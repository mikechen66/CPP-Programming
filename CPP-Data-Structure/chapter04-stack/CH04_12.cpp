
/* Implement a dequeue */

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

class Node {
   public:
   int data;
   class Node *next;
};

typedef class Node QueueNode;
typedef QueueNode *QueueByLinkedList;
QueueByLinkedList front=NULL;
QueueByLinkedList rear=NULL;

void enqueue(int value) {
    QueueByLinkedList node;              /* Create a node */
    node=new QueueNode;
    node->data=value;
    node->next=NULL;

    if (rear==NULL)                      /* Check wether the deque is empty */
        front=node;                      /* The newly-created node is the 1st node*/
    else
        rear->next=node;                 /* Add a node into the tail of the queue */
    rear=node;                           /* The tail ptr points to the new-added node */
}

int dequeue(int action) {
    int value;
    QueueByLinkedList tempNode, startNode;
    
    if (!(front==NULL) && action==1) {   /* Take the data item from the front of the dequeue */
        if (front==rear) 
            rear=NULL;
        value=front->data;               /* Take the data item out of the front of the dequeue */
        front=front->next;               /* Put the front ptr to point to the next */
        return value;
    } else if (!(rear==NULL) && action==2) {
        startNode=front;                /* Record the index of the front */
        value=rear->data;               /* Take the data item out of the current tail */
        
        tempNode=front;                 /* Look for the prior node close to the tail */
        while (front->next!=rear && front->next!=NULL) { 
            front=front->next;
            tempNode=front;
        }
        front=startNode;                /* Record the 1st front ptr after taking the data item out of the tail */
        rear=tempNode;                  /* Write a record */

        if ((front->next==NULL) || (rear->next==NULL)) { 
            front=NULL;                 /* Make the ptr point to Null */
            rear=NULL; 
        }
        return value; 
    } else 
        return -1;
}

int main(void) {
    int temp;
    cout<<"Implement the dequeue with linkedlist "<<endl;
    cout<<"===================================="<<endl;
    cout<<"Please add the 1st data item valuing 1 in the front of the dequeue"<<endl;
    enqueue(1);
    cout<<"Please add the 2nd data item valuing 3 in the front of the dequeue"<<endl;
    enqueue(3);
    cout<<"Please add the 3rd data item valuing 5 in the front of the dequeue"<<endl;
    enqueue(5);
    cout<<"Please add the 4th data item valuing 7 in the front of the dequeue"<<endl;
    enqueue(7);
    cout<<"Please add the 5th data item valuing 9 in the front of the dequeue"<<endl;
    enqueue(9);
    cout<<"===================================="<<endl;
    temp=dequeue(1);
    cout<<"The value to be taken out of the front of the dequeue is: "<<setw(1)<<temp<<endl;
    temp=dequeue(2);
    cout<<"The value to be taken out of the front of the dequeue is£º"<<setw(1)<<temp<<endl;
    temp=dequeue(1);
    cout<<"The value to be taken out of the front of the dequeue is£º"<<setw(1)<<temp<<endl;
    temp=dequeue(2);
    cout<<"The value to be taken out of the front of the dequeue is£º"<<setw(1)<<temp<<endl;
    temp=dequeue(1);
    cout<<"The value to be taken out of the front of the dequeue is£º"<<setw(1)<<temp<<endl;
    cout<<endl;
    return 0;
}


/* Output */

/*
Please input a value to access to a queue£¬input -2 to take out of the value (End with inputting -1): 18
Please input a value to access to a queue£¬input -2 to take out of the value (End with inputting -1): 21
Please input a value to access to a queue£¬input -2 to take out of the value (End with inputting -1): 24
Please input a value to access to a queue£¬input -2 to take out of the value (End with inputting -1): 27
Please input a value to access to a queue£¬input -2 to take out of the value (End with inputting -1): 30
Please input a value to access to a queue£¬input -2 to take out of the value (End with inputting -1): 33
[The queue is full]

The remained data item in the queue: 
[18][21][24][27][30]
 */