
/* Create a two-way linkedlist and insert nodes into it */

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
    class list *llink;
    class list *rlink;
};

typedef class list node;
typedef node *link;

link findnode(link head,int num) {
    link ptr;
    ptr=head;
    while (ptr!=NULL){
        if (ptr->num==num)
           return ptr;
        ptr=ptr->rlink;
    }
    return ptr;
}

link insertnode(link head,link ptr,int num,int score,char name[10]) {  
    link newnode=(link)malloc(sizeof(node));
    link newhead=(link)malloc(sizeof(node));
    newnode=new node;
    /* memset(newnode,0,sizeof(node)); */
    newnode->num=num;
    newnode->score=score;
    strcpy(newnode->name,name);

    if (head==NULL) {                           /* The double-way linkedlist is empty */
       newnode=new node;
      // memset(newhead,0,sizeof(node));       
       newhead->num=num;
       newhead->score=score;
       strcpy(newhead->name,name);
       return newhead;
    } else {
        if (ptr==NULL) {
           cout<<"[Error:It is not the node of the linkedlist]"<<endl;
        }
        if (ptr==head) {                        /* Insert it into the head of the linkedlist */
           head->llink=newnode;
           newnode->rlink=head;
           head=newnode;
        } else {
            if (ptr->rlink==NULL) {             /* Insert into the end of the linkedlist */
               ptr->rlink=newnode;
               newnode->llink=ptr;
               newnode->rlink=NULL;
            } else {                            /* Insert into the middle of nodes */
                newnode->rlink=ptr->rlink;
                ptr->rlink->llink=newnode;
                ptr->rlink=newnode;
                newnode->llink=ptr;
            }  
        }
    }
    return head;
}

int main(void) {  
    link head,ptr;
    link llinknode=NULL;
    link newnode=NULL;
    int new_num, new_score;
    char new_name[10];
    int i,j,position=0,find,data[12][2];
    char namedata[12][10]={{"Allen"},{"Scott"},{"Marry"}
    ,{"John"},{"Mark"},{"Ricky"},{"Lisa"}
    ,{"Jasica"},{"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
    srand((unsigned)time(NULL));
    cout<<"No.  Score  No.  Score  No.  Score  No.  Score"<<endl;
    cout<<"=============================================="<<endl;

    for (i=0; i<12; i++) {  
        data[i][0]=i+1;
        data[i][1]=rand()%50+51;
    }
    for (i=0; i<3; i++) {  
        for (j=0; j<4; j++)
            cout<<"["<<setw(2)<<data[j*3+i][0]<<"] ["
                <<setw(3)<<data[j*3+i][1]<<"]  ";
        cout<<endl;
    }

    head=new node;                              /* Create the ptr for the linkedlist head */
    if (head==NULL) {  
        cout<<"Error!! Memory allocation is failed!!"<<endl;
        exit(1);
    } else {
        head=new node;
        head->num=data[0][0];

        for (j=0; j<10; j++)
           head->name[j]=namedata[0][j];
        head->score=data[0][1];
        llinknode=head;

        for (i=1;i<12;i++) {                    /* Create the linkedlist */
            newnode=new node;
            newnode->llink = NULL;
            newnode->rlink = NULL;
            newnode->num=data[i][0];
            for (j=0; j<10; j++)
                newnode->name[j]=namedata[i][j];
            newnode->score=data[i][1];
            llinknode->rlink=newnode;
            newnode->llink=llinknode;
            llinknode=newnode;
       }
    }
    
    while (1) {  
        cout<<"Please input the ID to be inserted with ending -1: ";
        cin>>position;
        if (position==-1) {                      /* Interrup the loop condition */
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
    cout<<endl<<"\tNo.\t    Name\tScore"<<endl;         
    cout<<"\t=============================="<<endl;

    ptr=head;
    while (ptr!=NULL) {
       cout<<"\t["<<setw(2)<<ptr->num<<"]\t[ "
       <<setiosflags(ios::left)<<setw(10)
       <<ptr->name<<"]\t["<<setw(3)
       <<ptr->score<<"]"<<endl;
       ptr=ptr->rlink;   
    }

    free(head);
    free(newnode);
    return 0;
}



/* Output */

/*
No.  Score  No.  Score  No.  Score  No.  Score
==============================================
[ 1] [ 63]  [ 4] [ 81]  [ 7] [ 58]  [10] [ 55]  
[ 2] [ 93]  [ 5] [ 76]  [ 8] [ 96]  [11] [ 67]  
[ 3] [ 97]  [ 6] [ 88]  [ 9] [ 51]  [12] [ 91]  
Please input the ID to be inserted with ending -1: -1

        No.         Name        Score
        ==============================
        [ 1]    [ Allen     ]   [63 ]
        [2 ]    [ Scott     ]   [93 ]
        [3 ]    [ Marry     ]   [97 ]
        [4 ]    [ John      ]   [81 ]
        [5 ]    [ Mark      ]   [76 ]
        [6 ]    [ Ricky     ]   [88 ]
        [7 ]    [ Lisa      ]   [58 ]
        [8 ]    [ Jasica    ]   [96 ]
        [9 ]    [ Hanson    ]   [51 ]
        [10]    [ Amy       ]   [55 ]
        [11]    [ Bob       ]   [67 ]
        [12]    [ Jack      ]   [91 ]
 */