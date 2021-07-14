
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

link insertnode(link head,link ptr,int num,int score,char name[10]) {  
    link InsertNode;
    InsertNode=new node;
    if (!InsertNode)
       return NULL;
    InsertNode->num=num;
    InsertNode->score=score;
    strcpy(InsertNode->name,name);
    InsertNode->next=NULL;
    if (ptr==NULL) {                                 /* Insert the 1st node */
       InsertNode->next=head;
       return InsertNode;
    } else {
        if (ptr->next==NULL) {                       /* Insert the last node */
           ptr->next=InsertNode;
        } else {                                     /* Insert the middle node */
            InsertNode->next=ptr->next;
            ptr->next=InsertNode;     
        }
    }
    return head;
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
    cout<<"==========================================================="<<endl;
    for (i=0; i<12; i++) {  
        data[i][0]=i+1;
        data[i][1]=rand()%50+51;
    }
    for (i=0; i<3; i++) {  
        for (j=0; j<4; j++)
            cout<<"["<<data[j*3+i][0]<<"]  ["<<data[j*3+i][1]<<"]   ";
        cout<<endl;
    }

    head=new node;                                   /* Create the pointer for linkedlist head */
    if (!head) {  
        cout<<"Error! Memory allocated is failed!"<<endl;
        exit(1);
    }

    head->num=data[0][0];
    for (j=0; j<10; j++)
        head->name[j]=namedata[0][j];
    head->score=data[0][1];
    head->next=NULL;
    ptr=head;
    for (i=1; i<12; i++) {                           /* Creat a linkedlist */  
        newnode=(link)malloc(sizeof(node));
        newnode->num=data[i][0];
        for (j=0;j<10;j++)
            newnode->name[j]=namedata[i][j];
        newnode->score=data[i][1];
        newnode->next=NULL;
        ptr->next=newnode;
        ptr=ptr->next;
    }
    while (1) {  
        cout<<"Output the table for the inserted students with the ending number -1: ";
        cin>>position;
        if (position==-1) {                          /* Interrupt the loop condition */
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
    ptr=head;
    cout<<"\n\tSeat Number\t    Name\tScore\n";         
    cout<<"\t==============================\n";
    
    while (ptr!=NULL) {  
        cout<<"\t["<<ptr->num<<"]\t[ "<<ptr->name<<"]"<<setw(6)<<"\t["<<ptr->score<<"]\n";
        ptr=ptr->next;
    }
    delete head;
    return 0;
}



/* Output */

/*
No.  Score  No.  Score  No.  Score  No.  Score
===========================================================
[1]  [67]   [4]  [68]   [7]  [88]   [10]  [87]   
[2]  [75]   [5]  [89]   [8]  [89]   [11]  [56]   
[3]  [72]   [6]  [89]   [9]  [62]   [12]  [52]   
Output the table for the inserted students with the ending number -1: -1

        Seat Number         Name        Score
        ==============================
        [1]     [ Allen]        [67]
        [2]     [ Scott]        [75]
        [3]     [ Marry]        [72]
        [4]     [ John]         [68]
        [5]     [ Mark]         [89]
        [6]     [ Ricky]        [89]
        [7]     [ Lisa]         [88]
        [8]     [ Jasica]       [89]
        [9]     [ Hanson]       [62]
        [10]    [ Amy]          [87]
        [11]    [ Bob]          [56]
        [12]    [ Jack]         [52]

 */
