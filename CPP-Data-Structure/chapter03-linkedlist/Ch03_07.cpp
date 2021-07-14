
/* Linking functionalities of one-way linkedlist */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class list {  
    public:
    int num,score;
    char name[10];
    class list *next;
};

typedef struct list node;
typedef node *link;
link concatlist(link,link);

int main() {  
    link head,ptr,newnode,last,before;
    link head1,head2;
    int i,j,findword=0,data[12][2];
    /* Name of the first group of linkedlist */ 
    char namedata1[12][10]={{"Allen"},{"Scott"},{"Marry"},
    {"Jon"},{"Mark"},{"Ricky"},{"Lisa"},{"Jasica"},
    {"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
    /* Name of the second group of linkedlist */
    char namedata2[12][10]={{"May"},{"John"},{"Michael"},
    {"Andy"},{"Tom"},{"Jane"},{"Yoko"},{"Axel"},
    {"Alex"},{"Judy"},{"Kelly"},{"Lucy"}};
    srand((unsigned)time(NULL));
    
    for (i=0; i<12; i++) {  
        data[i][0]=i+1;
        data[i][1]=rand()%50+51;
    }
    head1=new node;                            /* Create the ptr for the first group of linkedlist head */

    if (!head1) {  
        cout<<"Error! Memory allocated is failed!"<<endl;
        exit(1);
    }

    head1->num=data[0][0];

    for (j=0; j<10; j++)
        head1->name[j]=namedata1[0][j];
    head1->score=data[0][1];
    head1->next=NULL;
    ptr=head1;

    for (i=1; i<12; i++) {                    /* Create the first group of linkedlist */
        newnode=new node;
        newnode->num=data[i][0];
        for (j=0; j<10; j++)
            newnode->name[j]=namedata1[i][j];
        newnode->score=data[i][1];
        newnode->next=NULL;
        ptr->next=newnode;
        ptr=ptr->next;
    }
    
    srand((unsigned)time(NULL));
    for (i=0; i<12; i++) {  
        data[i][0]=i+13;
        data[i][1]=rand()%40+41;
    }

    head2=new node;                           /* Create the second group of linkedlist */

    if (!head2) {  
        cout<<"Error! Memory allocation is failed!\n";
        exit(1);
    }

    head2->num=data[0][0];

    for (j=0; j<10; j++)
        head2->name[j]=namedata2[0][j];
    head2->score=data[0][1];
    head2->next=NULL;
    ptr=head2;
    for (i=1; i<12; i++) {                    /* Create the second group of linkedlist */
        newnode=new node;
        newnode->num=data[i][0];
        for (j=0;j<10;j++)
            newnode->name[j]=namedata2[i][j];
        newnode->score=data[i][1];
        newnode->next=NULL;
        ptr->next=newnode;
        ptr=ptr->next;
    }

    i=0;
    ptr=concatlist(head1,head2);              /* Concatenate the two linkedlist */                                          
    cout<<"Output the result with concatenating two linkedlist: "<<endl;               
    
    while (ptr!=NULL) {                       /* Input the data in the linkedlist */
        cout<<"["<<ptr->num<<" "<<ptr->name<<"  "<<ptr->score<<" ]\t-> ";
        i++;
        if (i>=3) {                           /* A row inlcudes three elements */
            cout<<endl;
            i=0;
        }
        ptr=ptr->next;
    }
    delete newnode;
    delete head2;
    return 0;
}

link concatlist(link ptr1,link ptr2) {
     link ptr;
     ptr=ptr1;
     while (ptr->next!=NULL)
        ptr=ptr->next;
     ptr->next=ptr2;
     return ptr1;
}



/* Output */

/*
Output the result with concatenating two linkedlist: 
[1 Allen  78 ]  -> [2 Scott  92 ]       -> [3 Marry  87 ]       -> 
[4 Jon  54 ]    -> [5 Mark  82 ]        -> [6 Ricky  69 ]       -> 
[7 Lisa  57 ]   -> [8 Jasica  99 ]      -> [9 Hanson  100 ]     -> 
[10 Amy  90 ]   -> [11 Bob  87 ]        -> [12 Jack  55 ]       -> 
[13 May  58 ]   -> [14 John  72 ]       -> [15 Michael  57 ]    -> 
[16 Andy  74 ]  -> [17 Tom  72 ]        -> [18 Jane  49 ]       -> 
[19 Yoko  77 ]  -> [20 Axel  49 ]       -> [21 Alex  70 ]       -> 
[22 Judy  80 ]  -> [23 Kelly  57 ]      -> [24 Lucy  55 ]       -> 
 */