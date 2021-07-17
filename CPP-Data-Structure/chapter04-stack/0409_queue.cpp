
/* Implement the data into and out of the queue */

#include <iostream>

using namespace std;
const int MAX=20; /* Define a size of a queue */

int main(void) {
    int front, rear, val, queue[MAX]={0};
    char ch;
    front=rear=-1;
    while (rear<MAX-1&&ch!='E') {  
        cout<<"[I]Store a value [G]Take a value [E]End: ";
        cin>>ch;
        switch (ch) {
            case 'I':
                cout<<"[Please input the value]: ";
                cin>>val;
                rear++;
                queue[rear]=val;
                break;
            case 'G':
                if (rear>front) {  
                    front++;
                    cout<<"[Take the value as]: ["<<queue[front]<<"]";
                    cout<<endl;
                    queue[front]=0;
                } else {  
                    cout<<"[The queue is empty]"<<endl;
                    exit(0);
                }
                break;
            default:
                cout<<endl;
                break;
        }
    }
    if (rear==MAX-1) {
        cout<<"[The queue is full]"<<endl;
    }
    cout<<"[The data of the current queue]:";
    if (front>=rear) {
        cout<<"No"<<endl;
        cout<<"[The queue is empty]"<<endl;
    } else {
        while (rear>front) {  
            front++;
            cout<<"["<<queue[front]<<"]\t";
        }
        cout<<endl;
    }
    return 0;
}



/* Output */

/* 
[I]Store a value [G]Take a value [E]End: 6

[I]Store a value [G]Take a value [E]End: 8

[I]Store a value [G]Take a value [E]End: 9

[I]Store a value [G]Take a value [E]End: 12

[I]Store a value [G]Take a value [E]End: 
[I]Store a value [G]Take a value [E]End: 18

[I]Store a value [G]Take a value [E]End: 
[I]Store a value [G]Take a value [E]End: E

[The data of the current queue]:No
[The queue is empty]
 */