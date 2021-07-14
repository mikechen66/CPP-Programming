
/* Delete a node in the circular linkedlist */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

class list {  
    public:
    int num,score;
    char name[10];
    class list *next;
};
typedef class list node;
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

link deletenode(link head,link del) {
    link CurNode=NULL;  
    link PreNode=NULL;
    link TailNode=NULL;
    if (head==NULL) { 
        cout<<"[The circular linkedlist is empty]";
        return NULL;
    } else {
        if (del==head) {                     /* If delete the node for the head of linkedlist */
            CurNode=head;
            while (CurNode->next!=head)
               CurNode=CurNode->next;
               TailNode=CurNode;             /* Look for the last node and record it */
               head=head->next;              /* (1) Make the ptr (for the likedlist head) move to the next node */
               TailNode->next=head;          /* (2) Make the ptr for (the last node) point to the new linkedlist head */
               return head;
        } else {                             /* if not the the node for the head of linkedlist */
            CurNode=head;
            while (CurNode->next!=del)
                CurNode=CurNode->next;
            PreNode=CurNode;                 /* (1) Find the previous node before the to-be-deleted node and record it */
            CurNode=CurNode->next;           /* The node to be deleted */
            PreNode->next=CurNode->next;     /* (2) Make the previous ptr (before the to-be-deleted) point to its next node */
            free(CurNode);
            return head;
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
    cout<<"No.  Score  No.  Score  No.  Score  No.  Score"<<endl;
    cout<<"=============================================="<<endl;
    
    for (i=0; i<12; i++) {  
        data[i][0]=i+1;
        data[i][1]=rand()%50+51;
    }

    for (i=0;i<3;i++) {  
        for (j=0;j<4;j++)
            cout<<"["<<data[j*3+i][0]<<"]"<<setw(4)<<"["<<data[j*3+i][1]<<"]  ";
        cout<<endl;
    }

    head=new node;                            /* Create the ptr for the linkedlist head */
    if (!head) {  
        cout<<"Error!! Memory allocation is failed!!"<<endl;
        exit(1);
    } 

    head->num=data[0][0];

    for (j=0;j<10;j++)
        head->name[j]=namedata[0][j];
    head->score=data[0][1];
    head->next=NULL;
    ptr=head;

    for (i=1; i<12; i++) {                     /* Create the linkedlist */
        newnode=new node;
        newnode->num=data[i][0];
        for (j=0; j<10; j++)
            newnode->name[j]=namedata[i][j];
        newnode->score=data[i][1];
        newnode->next=NULL;
        ptr->next=newnode;                    /* Make the prevous node point to the new-built node */
        ptr=newnode;                          /* The new mode has become a prior node */
    }

    newnode->next=head;                       /* Complete the circular linkedlist by making the last node point to the head node */

    while (1) {  
        cout<<"Please input the ID to be deleted with ending -1: ";
        cin>>position;
        if (position==-1) {                   /* Interrupt the loop condition */
            break;
        } else {  
            ptr=findnode(head,position);
            head=deletenode(head,ptr);
        }
    }

    ptr=head;                                 /* Point to the beginning of the linkedlist */
    cout<<"\n\tNo.\t    Name\tScore\n";         
    cout<<"\t==============================\n";

    do {
        cout<<"\t["<<ptr->num<<"]\t[ "<<setw(10)<<ptr->name<<"]\t["<<ptr->score<<"]"<<endl;
        ptr=ptr->next;                        /* Point to the next node */
    } while (head!=ptr && head!=head->next);

    free(head);
    return 0;
}



/* Output */

/*
No.  Score  No.  Score  No.  Score  No.  Score
==============================================
[1]   [60]  [4]   [62]  [7]   [88]  [10]   [54]  
[2]   [98]  [5]   [72]  [8]   [64]  [11]   [77]  
[3]   [94]  [6]   [86]  [9]   [86]  [12]   [99]  
Please input the ID to be deleted with ending -1: -1

        No.         Name        Score
        ==============================
        [1]     [      Allen]   [60]
        [2]     [      Scott]   [98]
        [3]     [      Marry]   [94]
        [4]     [       John]   [62]
        [5]     [       Mark]   [72]
        [6]     [      Ricky]   [86]
        [7]     [       Lisa]   [88]
        [8]     [     Jasica]   [64]
        [9]     [     Hanson]   [86]
        [10]    [        Amy]   [54]
        [11]    [        Bob]   [77]
        [12]    [       Jack]   [99]
 */