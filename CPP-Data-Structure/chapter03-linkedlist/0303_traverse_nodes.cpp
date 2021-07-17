
/* The console has a little peoblem for the input */

#include <iostream>
using namespace std;

class list {
    public:
       int num,score;
       char name[10];
       class list *next;
};
typedef class list node;
typedef node *link;

int main() {  
    link newnode,ptr,delptr;    /* Declare the pointers of 3 linkedlists */
    cout<<"Please input the data of five students: "<<endl;
    delptr=new node;            /* Take the delptr as the pointer for linkedlist hear */
    if (!delptr) {  
        cout<<"[Error!! Memory allocated is failed!]"<<endl;
        exit(1);
    }
    cout<<"Please input the seat number: ";
    cin>>delptr->num;
    cout<<"Please input the name: ";
    cin>>delptr->name;
    cout<<"Please input the score: ";
    cin>>delptr->score;
    ptr=delptr;                 /* Retain the pointer for the linkedlist head while ptr is pointed to the current node */

    for (int i=1;i<5;i++) {  
        newnode=new node;       /* Create a new node */
        if (!newnode) {  
            cout<<"[Error!! Memory allocated is failed!"<<endl;
            exit(1);
        }
        cout<<"Please input the seat number: ";
        cin>>newnode->num;
        cout<<"Please input the name: ";
        cin>>newnode->name;
        cout<<"Please input the score: ";
        cin>>newnode->score;
        newnode->next=NULL;
        ptr->next=newnode;      /* Add the new node into the linkedlist */
        ptr=ptr->next;          /* Let ptr to be placed into the unmost tail */
    }
    cout<<"\n  students' score"<<endl;
    cout<<" Seat Number\tName\tScore\n=================================="<<endl;
    ptr=delptr;                 /* Let ptr goes back to the linkedlist head */
    while (ptr!=NULL) {  
        cout<<ptr->num<<"\t"<<ptr->name<<"\t"<<ptr->score<<endl;
        delptr=ptr;
        ptr=ptr->next;          /* The ptr iterates the whole linkedlist from head to tail. */
        delete delptr;          /* Releae the memory space */
    }
}



/* Please input the data of five students: 
Please input the seat number:20
Please input the name:Steve Jobs
Please input the score:
Please input the seat number:
Please input the name:
Please input the score:
Please input the seat number:
Please input the name:
Please input the score:
Please input the seat number:
Please input the name:
Please input the score:
Please input the seat number:
Please input the name:
Please input the score:
  students' score
 Seat Number    Name    Score
=====================
20      Steve   0
0               0
0               0
0               0
0               0
 */