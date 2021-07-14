
/* Create and insert nodes into the circular linkedlist */ 

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h> 
#include <iomanip>

using namespace std;

class list {   
    public:
    int num,score;
    char name[10];
    class list *next;
};

typedef struct list node;
typedef node *link;

link findnode(link head,int num) {
    link ptr;
    ptr=head;
    while (ptr!=NULL) {
        if (ptr->num==num)
           return ptr;
        ptr=ptr->next;
    }
    return ptr;
}

link insertnode(link head,link after,int num,int score,char name[10]) {  
    link InsertNode;
    InsertNode=new node;
    link CurNode=NULL;
    InsertNode->num=num;
    InsertNode->score=score;
    strcpy(InsertNode->name,name);
    InsertNode->next=NULL;

    if (InsertNode==NULL) {
        cout<<"Memory allocation is failed"<<endl;
        return NULL;
    } else {
        if (head==NULL) {                         /* The linkedlist is null */
           head=InsertNode;
           InsertNode->next=head;
           return head;
        } else {
            if (after==NULL) {                                                   
                InsertNode->next=head;            /* Add the new nodes at the head of the linkedlist */
                CurNode=head;                     /* (1) Make the new ptr of the newly-added node to point to the head */
                while (CurNode->next!=head)
                    CurNode=CurNode->next;                                 
                CurNode->next=InsertNode;         /* (2) Make the ptr (for the newly-added node) to point to the tail of the linkedlist  */                              
                head=InsertNode;                  /* (3) Make the ptr of the linkedlist head to the newl added node */
                return head;
            } else {                              /* if it is else */                                
                InsertNode->next=after->next;     /* (1) Make the ptr (for the newly-added node) point to the node of 'next'*/                       
                after->next=InsertNode;           /* (2) Make the ptr (for the node of after) point to a newly-added node */
                return head; 
            }
        } 
    }
}


int main() {  
    link head,ptr,newnode;
    int new_num, new_score;
    char new_name[10];
    int i,j,position=0,find,data[12][2];
    char namedata[12][10]={{"Allen"},{"Scott"},{"Marry"},
    {"John"},{"Mark"},{"Ricky"},{"Lisa"},{"Jasica"},
    {"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
    srand((unsigned)time(NULL));
    cout<<"No. Score  No. Score  No. Score  No. Score"<<endl;
    cout<<"=============================================="<<endl;
    
    for (i=0; i<12; i++) {  
        data[i][0]=i+1;
        data[i][1]=rand()%50+51;
    }

    for (i=0; i<3; i++) {  
        for (j=0; j<4; j++)
            cout<<"["<<data[j*3+i][0]<<"] ["<<data[j*3+i][1]<<"]  ";
        cout<<endl;
    }

    head=new node;                               /* Create the head ptr for the linkedlist */
    if(!head) {  
        cout<<"Error!! Memory allocation is failed!!"<<endl;
        exit(1);
    }

    head->num=data[0][0];
    for (j=0; j<10; j++)
        head->name[j]=namedata[0][j];
    head->score=data[0][1];
    head->next=NULL;
    ptr=head;

    for(i=1;i<12;i++) {                           /* Create a linkedlist */
        newnode=new node;
        newnode->num=data[i][0];
        for (j=0;j<10;j++)
            newnode->name[j]=namedata[i][j];
        newnode->score=data[i][1];
        newnode->next=NULL;
        ptr->next=newnode;                        /* Make the next node point to the new-created node */
        ptr=newnode;                            
    }

    newnode->next=head;                           /* Complete the circular linkedlist by making the last node point to the head node */

    while (1) {  
        cout<<"Output the table for the inserted students with the ending number -1: ";
        cin>>position;
        if (position==-1) {                       /* Interrupt the loop condition */
            break;
        } else {  
            ptr=findnode(head,position);
            cout<<"Please input the ID number for any newly inserted student: ";
            cin>>new_num;
            cout<<"Please input the score for any newly inserted student: ";
            cin>>new_score;
            cout<<"Please insert the name for any newly inserted student: ";
            cin>>new_name;
            head=insertnode(head,ptr,new_num,new_score,new_name);
        }
    }
    ptr=head;                                     /* Point to the beginning of the linkedlist */
    cout<<"\n\tNo.\t    Name\tScore\n";      
    cout<<"\t==============================\n";
    do {
        cout<<"\t["<<ptr->num<<"]\t[ "<<setw(10)<<ptr->name<<"]\t["<<ptr->score<<"]\n";
        ptr=ptr->next;                            /* Point to the next node */
    } while (head!=ptr && head!=head->next); 

    delete newnode;
    return 0;
}



/* Output */

/*
No. Score  No. Score  No. Score  No. Score
==============================================
[1] [59]  [4] [83]  [7] [91]  [10] [81]  
[2] [82]  [5] [78]  [8] [80]  [11] [88]  
[3] [83]  [6] [64]  [9] [90]  [12] [76]  
Output the table for the inserted students with the ending number -1: -1

        No.         Name        Score
        ==============================
        [1]     [      Allen]   [59]
        [2]     [      Scott]   [82]
        [3]     [      Marry]   [83]
        [4]     [       John]   [83]
        [5]     [       Mark]   [78]
        [6]     [      Ricky]   [64]
        [7]     [       Lisa]   [91]
        [8]     [     Jasica]   [80]
        [9]     [     Hanson]   [90]
        [10]    [        Amy]   [81]
        [11]    [        Bob]   [88]
        [12]    [       Jack]   [76]

 */