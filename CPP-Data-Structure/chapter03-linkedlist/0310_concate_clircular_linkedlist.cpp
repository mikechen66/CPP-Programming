
/* Connect the two linkedlist for the two students' score and print it. */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

class list {
    public:
    int num,score;
    char name[10];
    class list *next;
};

typedef class list node;
typedef node *link;
link creat_link(int data[10][2],int num);
void print_link(link head);
link concat(link ptr1,link ptr2);

int main() {  
    link ptr1,ptr2,ptr;
    int i,data1[6][2],data2[6][2];
    srand(time(NULL));

    for (i=1; i<=6; i++) {  
        data1[i-1][0]=i*2-1;
        data1[i-1][1]=rand()%49+52;
        data2[i-1][0]=i*2;
        data2[i-1][1]=rand()%49+52;
    }

    ptr1=creat_link(data1,6);                /* Create the serial 1 */
    ptr2=creat_link(data2,6);                /* Create the serial 2 */
    i=0;
    cout<<"\t\t  Data for the original linkedlist:"<<endl;
    cout<<"\t    No.  Score  No.  Score  No. Score"<<endl;
    cout<<"\t    =================================="<<endl;
    cout<<"Circular linkedlist 1: ";
    print_link(ptr1);
    cout<<"Circular linkedlist 2: ";
    print_link(ptr2);
    cout<<"\t    =================================="<<endl;
    cout<<"Output the linkedlist after connection: ";
    ptr=concat(ptr1,ptr2);                   /* Connect the circular linkedlist */
    print_link(ptr);
}

link creat_link(int data[10][2],int num) {   /* Create a subroutine for the linkedlist */
    link head, ptr, newnode;
    for (int i=0;i<num;i++) {  
        newnode=new node;
        if (!newnode) {  
            cout<<"Error!! Memory allocation is failed!!"<<endl;
            exit(i);
        }
        if(i==0) {                           /* Create the head for the linkedlist */
            newnode->num=data[i][0];
            newnode->score=data[i][1];
            newnode->next=NULL;
            head=newnode;
            ptr=head;
        } else {                             /* Create the other nodes for the linkedlist */
            newnode->num=data[i][0];
            newnode->score=data[i][1];
            newnode->next=NULL;
            ptr->next=newnode;
            ptr=newnode;
        }
        newnode->next=head;
    }
    return ptr;                              /* Return the linkedlist */
}

void print_link(link head) {                 /* Print the subroutine of the linkedlist */ 
    link ptr;
    int i=0;
    ptr=head->next;
    do {  
        cout<<"["<<setw(2)<<ptr->num<<"-"<<setw(3)
            <<ptr->score<<"] -> ";
        i++;
        if (i>=3) {                          /* Print 3 elements for each row */
            cout<<"\n\t    ";
            i=0;
        }
        ptr=ptr->next;
    } while (ptr!=head->next);
    cout<<endl;
}

link concat(link ptr1,link ptr2) {           /* Connect the subroutine for the linkedlist */
    link head;
    head=ptr1->next;                         /* Find any node in each of the ptr1 and ptr2 */
    ptr1->next=ptr2->next;                   /* Exchange the next of the twop nodes */
    ptr2->next=head;
    return ptr2;
}



/* Output */

/*
                  Data for the original linkedlist:
            No.  Score  No.  Score  No. Score
            ==================================
Circular linkedlist 1: [ 1- 91] -> [ 3- 70] -> [ 5- 91] -> 
            [ 7- 62] -> [ 9- 81] -> [11- 59] -> 
            
Circular linkedlist 2: [ 2- 80] -> [ 4- 73] -> [ 6- 72] -> 
            [ 8- 78] -> [10- 83] -> [12- 86] -> 
            
            ==================================
Output the linkedlist after connection: [ 1- 91] -> [ 3- 70] -> [ 5- 91] -> 
            [ 7- 62] -> [ 9- 81] -> [11- 59] -> 
            [ 2- 80] -> [ 4- 73] -> [ 6- 72] -> 
            [ 8- 78] -> [10- 83] -> [12- 86] -> 
 */