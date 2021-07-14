
/* Delete nodes in the two-way linkedlist  */

#include <iostream>
#include <cstdlib>
#include <ctime>
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
    while(ptr!=NULL){
        if(ptr->num==num)
           return ptr;
        ptr=ptr->rlink;
    }
    return ptr;
}

link deletenode(link head,link del) {  
    if (head==NULL) {                             /* The two-way linkedlist is empty */
       cout<<"[The linkedlist is empty]"<<endl;
       return NULL;
    }
    if (del==NULL) {
        cout<<"[Error:It is not the node of the linkedlist]"<<endl;
        return NULL;
    }
    if (del==head) {
        head=head->rlink;          
        head->llink=NULL;
    } else {
        if (del->rlink==NULL) {                   /* Delete the tail of the linkedlist */
            del->llink->rlink=NULL;
        } else {                                  /* Delete the nodes in the middle of the linkedlist */
            del->llink->rlink=del->rlink;
            del->rlink->llink=del->llink;
        }
    }
    free(del);
    return head;
}


int main() {  
    link head,ptr;
    link llinknode=NULL;
    link newnode=NULL;
    int new_num, new_score;
    char new_name[10];
    int i,j,position=0,find,data[12][2];
    char namedata[12][10]={{"Allen"},{"Scott"},{"Marry"},
    {"John"},{"Mark"},{"Ricky"},{"Lisa"},
    {"Jasica"},{"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
    srand((unsigned)time(NULL));
    cout<<"No.  Score  No.  Score  No.  Score  No.  Score"<<endl;
    cout<<"=============================================="<<endl;
    
    for (i=0; i<12; i++) {  
        data[i][0]=i+1;
        data[i][1]=rand()%50+51;
    }
    for (i=0; i<3; i++) {  
        for (j=0; j<4; j++)
            cout<<"["<<setw(2)<<data[j*3+i][0]
            <<"] ["<<setw(3)<<data[j*3+i][1]<<"]  ";
        cout<<endl;
    }

    head=new node;                                 /* Create the head ptr for the linkedlist */
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
        for (i=1; i<12; i++) {                     /* Create the linkedlist */
            newnode=new node;
            newnode->llink = NULL;
            newnode->rlink = NULL;
            newnode->num=data[i][0];
            for (j=0;j<10;j++)
                newnode->name[j]=namedata[i][j];
            newnode->score=data[i][1];
            llinknode->rlink=newnode;
            newnode->llink=llinknode;
            llinknode=newnode;
       }
    }
    
    while (1) {  
        cout<<"Please input the ID to be deleted with ending -1: ";
        scanf("%d",&position);
        if (position==-1) {                        /* Interrupt the loop condition */
            break;
        } else {  
            ptr=findnode(head,position);
            head=deletenode(head,ptr);
        }
    }
    cout<<endl<<"\tNo.\t    Name\tScore"<<endl;         
    cout<<"\t=============================="<<endl;
    ptr=head;
    while (ptr!=NULL) {
        cout<<"\t["<<setiosflags(ios::right)
        <<setw(2)<<ptr->num<<"]\t[ "
        <<setiosflags(ios::left)<<setw(10)<<ptr->name
        <<"]\t["<<setw(3)<<ptr->score<<"]"<<endl;
        ptr=ptr->rlink;   
    }
    return 0;
}


/* Output */

/*
No.  Score  No.  Score  No.  Score  No.  Score
==============================================
[ 1] [ 85]  [ 4] [ 96]  [ 7] [ 79]  [10] [ 69]  
[ 2] [ 65]  [ 5] [ 56]  [ 8] [ 87]  [11] [ 73]  
[ 3] [ 84]  [ 6] [ 69]  [ 9] [ 98]  [12] [ 82]  
Please input the ID to be deleted with ending -1: -1

        No.         Name        Score
        ==============================
        [ 1]    [      Allen]   [ 85]
        [ 2]    [      Scott]   [ 65]
        [ 3]    [      Marry]   [ 84]
        [ 4]    [       John]   [ 96]
        [ 5]    [       Mark]   [ 56]
        [ 6]    [      Ricky]   [ 69]
        [ 7]    [       Lisa]   [ 79]
        [ 8]    [     Jasica]   [ 87]
        [ 9]    [     Hanson]   [ 98]
        [10]    [        Amy]   [ 69]
        [11]    [        Bob]   [ 73]
        [12]    [       Jack]   [ 82]
 */