
/* Print out the data after inverting the linkedlist */

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

int main() {  
    link ptr,last,before;
    int i,j,findword=0,data[12][2];
    char namedata[12][10]={{"Allen"},{"Mako"},{"Lean"},
    {"Melissa"},{"Angel"},{"Sabrina"},{"Joyce"},
    {"Jasica"},{"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
    srand((unsigned)time(NULL));
    for (i=0; i<12; i++) {  
        data[i][0]=i+1;
        data[i][1]=rand()%50+51;
    }

    link head=new node;                                      /* Create the ptr for the linkedlist head */

    if (!head) {  
        cout<<"Error! Memory allocated is failed!"<<endl;
        exit(1);
    }

    head->num=data[0][0];

    for (j=0;j<10;j++)
        head->name[j]=namedata[0][j];
    head->score=data[0][1];
    head->next=NULL;
    ptr=head;

    for (i=1; i<12; i++) {                                   /* Create the linkedlist */
        link newnode=new node;
        newnode->num=data[i][0];
        for (j=0;j<10;j++)
            newnode->name[j]=namedata[i][j];
        newnode->score=data[i][1];
        newnode->next=NULL;
        ptr->next=newnode;
        ptr=ptr->next;
    }

    ptr=head;
    i=0;
    cout<<"Data in the original linkedlist:"<<endl;   

    while (ptr!=NULL) {                                      /* Print out the data in the linkedlist */
        cout<<"["<<setw(2)<<ptr->num<<setw(8)
        <<ptr->name<<setw(3)<<ptr->score<<"] -> ";
        i++;
        if (i>=3) {                                          /* A row inlcudes three elements */
            cout<<endl;
            i=0;
        }
        ptr=ptr->next;
    }

    ptr=head;
    before=NULL;
    cout<<"\nData after inverting the linkedlist:"<<endl;    

    while (ptr!=NULL) {                                       /* Invert the linkedlist */
        last=before;
        before=ptr;
        ptr=ptr->next;
        before->next=last;
    }

    ptr=before;

    while (ptr!=NULL) {  
        cout<<"["<<setw(2)<<ptr->num<<setw(8)
        <<ptr->name<<setw(3)<<ptr->score<<"] -> ";
        i++;
        if (i>=3) {  
            cout<<endl;
            i=0;
        }
        ptr=ptr->next;
    }
}


/* Output */

/* 
Data in the original linkedlist:
[ 1   Allen 52] -> [ 2    Mako100] -> [ 3    Lean 61] -> 
[ 4 Melissa 84] -> [ 5   Angel 68] -> [ 6 Sabrina 73] -> 
[ 7   Joyce 67] -> [ 8  Jasica 84] -> [ 9  Hanson 58] -> 
[10     Amy 81] -> [11     Bob 83] -> [12    Jack 75] -> 

Data after inverting the linkedlist:
[12    Jack 75] -> [11     Bob 83] -> [10     Amy 81] -> 
[ 9  Hanson 58] -> [ 8  Jasica 84] -> [ 7   Joyce 67] -> 
[ 6 Sabrina 73] -> [ 5   Angel 68] -> [ 4 Melissa 84] -> 
[ 3    Lean 61] -> [ 2    Mako100] -> [ 1   Allen 52] -
 */ 