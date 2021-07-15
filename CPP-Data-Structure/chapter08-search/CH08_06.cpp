#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#define INDEXBOX 7       
#define MAXNUM 13     

using namespace std;
void creat_table(int);     
void print_data(int);      

class list {  
    public:
    int val;
    class list *next;
};

typedef class list node;
typedef node *link;
node indextable[INDEXBOX];  

int main(void) {  
    int i, data[MAXNUM];
    srand((unsigned)time(NULL));

    for (i=0; i<INDEXBOX; i++) {  
        indextable[i].val=-1;
        indextable[i].next=NULL;
    }

    cout<<"Original Data: \n\t";

    for (i=0; i<MAXNUM; i++) {  
        data[i]=rand()%30+1; 
        cout<<"["<<setw(2)<<data[i]<<"] "; 
        if (i%8==7)
            cout<<"\n\t";
    }

    cout<<"\nHash Table\n";
    
    for (i=0; i<MAXNUM; i++)
        creat_table(data[i]); 
    for (i=0; i<INDEXBOX; i++)
        print_data(i);        
    cout<<endl;
    return 0;
}

void creat_table(int val) {  
    link newnode;
    link current;
    int hash;
    hash=val%7;             
    newnode=(link)malloc(sizeof(node));
    current=(link)malloc(sizeof(node));
    newnode->val=val;
    newnode->next=NULL;
    *current=indextable[hash];

    if (current->next==NULL) 
        indextable[hash].next=newnode;
    else
        while(current->next!=NULL) 
            current=current->next;
    current->next=newnode; 
}

void print_data(int val) {  
    link head;
    int i=0;
    head=indextable[val].next;  
    cout<<"   "<<setw(2)<<val<<"£º\t"; 
    while (head!=NULL) {  
        cout<<"["<<setw(2)<<head->val<<"]-";
        i++;
        if (i%8==7)  
            cout<<"\n\t";
        head=head->next;
    }
    cout<<"\b \n";
}



/* Output */

/*
Original Data: 
        [26] [16] [12] [ 7] [ 4] [ 7] [22] [ 9] 
        [18] [23] [23] [23] [29] 
Hash Table
    0£º [ 7]-[ 7] 
    1£º [22]-[29] 
    2£º [16]-[ 9]-[23]-[23]-[23] 
    3£º 
    4£º [ 4]-[18] 
    5£º [26]-[12] 
    6£º
 */