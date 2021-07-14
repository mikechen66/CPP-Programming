
/* Implement the data item to enter into and out of the queue */

#include <iostream>
using namespace std;

int main(void) {  
    int front,rear,val=0,queue[5]={0};
    front=rear=-1;
    while (rear<5&&val!=-1) {  
        cout<<"Please input a value to access to a queue£¬input -2 to take out of the value (End with inputting -1): ";
        cin>>val;
        if (val==-2) {  
            if (front==rear) {  
                cout<<"[The queue is empty]"<<endl;
                break;
            }
            front++;
            if (front==5) {
                front=0;
            }
            cout<<"Take the value out of the queue ["<<queue[front]<<"]"<<endl;
            queue[front]=0;
        } else if (val!=-1 && rear<5) {  
            if (rear+1==front || rear==4 && front<=0) {  
                cout<<"[The queue is full]"<<endl;
                break;
            }
            rear++;
            if (rear==5) {
                rear=0;
            }
            queue[rear]=val;
        }
    }
    cout<<"\nThe remained data item in the queue: "<<endl;
    if (front==rear) {
        cout<<"The queue is empty!!"<<endl;
    } else { 
        while (front!=rear) {  
            front++;
            if (front==5)
                front=0;
            cout<<"["<<queue[front]<<"]";
            queue[front]=0;
        }
    }
    cout<<endl;
    return 0;
}



/* Output */

/*
Please input a value to access to a queue£¬input -2 to take out of the value (End with inputting -1): 18
Please input a value to access to a queue£¬input -2 to take out of the value (End with inputting -1): 21
Please input a value to access to a queue£¬input -2 to take out of the value (End with inputting -1): 32
Please input a value to access to a queue£¬input -2 to take out of the value (End with inputting -1): 36
Please input a value to access to a queue£¬input -2 to take out of the value (End with inputting -1): 38
Please input a value to access to a queue£¬input -2 to take out of the value (End with inputting -1): 41
[The queue is full]

The remained data item in the queue: 
[18][21][32][36][38]
 */