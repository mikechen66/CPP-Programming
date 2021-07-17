
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

list del_ptr(list *head,list *ptr);
int main() {  
    list *ptr;
    int findword=0,find,data[12][2];
    char namedata[12][10]={{"Allen"},{"Moko"},
    {"Lean"},{"Melissa"},{"Angel"},{"Sabrina"},
    {"Joyce"},{"Jasica"},{"Hanson"},{"Amy"},
    {"Bob"},{"Jack"}};
    srand((unsigned)time(NULL));                                       /* Take the number as a seed number */
    cout<<"No. Score  No. Score  No. Score  No.  Score"<<endl;
    cout<<"=============================================="<<endl;
    for (int i=0; i<12; i++) {  
        data[i][0]=i+1;
        data[i][1]=rand()%50+51;
    }
    for (int i=0; i<3; i++) {  
        for (int j=0; j<4; j++)
            cout<<"["<<data[j*3+i][0]<<"]  ["<<data[j*3+i][1]<<"]  ";
        cout<<endl;
    }
    list *head=new list;                                               /* Create the ptr for linkedlist head */
    if (!head) {  
        cout<<"Error! Memory allocated is failed!"<<endl;
        exit(1);
    }

    head->num=data[0][0];
    for (int j=0;j<10;j++)
        head->name[j]=namedata[0][j];
    head->score=data[0][1];
    head->next=NULL;
    ptr=head;

    for (int i=1;i<12;i++) {  
        list *newnode=new list;                                        /* Create the linkedlist */
        newnode->num=data[i][0];
        for (int j=0;j<10;j++)
            newnode->name[j]=namedata[i][j];
        newnode->score=data[i][1];
        newnode->next=NULL;
        ptr->next=newnode;
        ptr=ptr->next;
    }

    while (1) {  
        cout<<"Output the table for the inserted students with the ending number -1£º";
        cin>>findword;
        if (findword==-1) {                                            /* Interrupt the loop condition */
            break;
        } else {  
            ptr=head;
            find=0;
            while (ptr!=NULL) {  
                if (ptr->score==findword) {  
                    *ptr=del_ptr(head,ptr);                            /* Delete the data */
                    find++;
                }
                ptr=ptr->next;
            }
            if (find==0)
            cout<<"######Not found######"<<endl;
        }
    }
    ptr=head;
    cout<<"\n\tNo.\t    Name\tScore"<<endl;                            /* Output the left data in the linkedlist */
    cout<<"\t=============================="<<endl;

    while(ptr!=NULL) {  
        cout<<"\t["<<ptr->num<<"]\t["<<setw(10)<<ptr->name
            <<"]\t["<<ptr->score<<"]"<<endl;
        ptr=ptr->next;
    }
}

list del_ptr(list *head,list *ptr) {                                   /* Delete the subroutine of the node */
    list *top;
    top=head;
    if (ptr==head) {                                                   /* [Scenario 1]: Delete the node in the linkedlist head */
        head=head->next;
        cout<<"Already delete the "<<ptr->num<<" student!!name: "
            <<ptr->name<<endl;
    } else {  
        while (top->next!=ptr)                                         /* Find out the previous location of the node */
            top=top->next;
        if (ptr->next==NULL) {                                         /* [Scenario 2]: Delete the node in the linkedlist tail */ 
            top->next=NULL;
            cout<<"Already delete the "<<ptr->num<<" student!!name: "
                <<ptr->name<<endl;
        } else {                                                       /* [Scenario 3]: Delete any other node in the middle of the linkedlist */
            top->next=ptr->next;
            cout<<"lready delete the "<<ptr->num<<" student!!name: "
                <<ptr->name<<endl;
        }
    }
    delete []ptr;                                                      /* Release the memory space */
    return *head;                                                      /* Return to the linkedlist */
}


/* Output */

/* 
No. Score  No. Score  No. Score  No.  Score
==============================================
[1]  [98]  [4]  [84]  [7]  [87]  [10]  [71]  
[2]  [68]  [5]  [73]  [8]  [96]  [11]  [81]  
[3]  [65]  [6]  [64]  [9]  [95]  [12]  [65]  
Output the table for the inserted students with the ending number -1£º-1

        No.         Name        Score
        ==============================
        [1]     [     Allen]    [98]
        [2]     [      Moko]    [68]
        [3]     [      Lean]    [65]
        [4]     [   Melissa]    [84]
        [5]     [     Angel]    [73]
        [6]     [   Sabrina]    [64]
        [7]     [     Joyce]    [87]
        [8]     [    Jasica]    [96]
        [9]     [    Hanson]    [95]
        [10]    [       Amy]    [71]
        [11]    [       Bob]    [81]
        [12]    [      Jack]    [65]
 */