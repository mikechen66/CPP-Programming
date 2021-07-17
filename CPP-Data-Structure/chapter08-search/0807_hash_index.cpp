#include <iostream>
#include <iomanip>
#include <ctime>
#include<cstdlib>
using namespace std;
const int INDEXBOX=7;      
const int MAXNUM=13;     

void creat_table(int);       
void print_data(int);       
int findnum(int);          

class list {
    public:
    int val;
    list *next;
};

typedef class list node;
typedef node *link;
node indextable[INDEXBOX];  

int main(void) {  
    int i, num, data[MAXNUM];
    srand(time(NULL));

    for (i=0; i<INDEXBOX; i++) {  
        indextable[i].val=i;
        indextable[i].next=NULL;
    }

    cout<<"Original Data: \n\t";

    for (i=0; i<MAXNUM; i++) {  
        data[i]=rand()%30+1;    
        cout<<"["<<setw(2)<<data[i]<<"] ";
        
        if (i%8==7)
            cout<<"\n\t";
    }

    cout<<endl;

    for (i=0; i<MAXNUM; i++)
        creat_table(data[i]);

    while (1) {  
        cout<<"Please look up the data element (1-30) while ending with -1: £º";
        cin>>num;
        if (num==-1) {
            break;
        }
        i=findnum(num);

        if (i==0) {
            cout<<"#####Do not find it "<<num<<" #####"<<endl;
        } else {
            cout<<"Find out it "<<num<<"£¬totally find out  "<<i<<" times!"<<endl;
        }
    }

    cout<<"\nHash Table"<<endl;

    for (i=0;i<INDEXBOX;i++)
        print_data(i);
    cout<<endl;
    return 0;
}

void creat_table(int val) {  
    link newnode;
    int hash;
    hash=val%7; 
    newnode=(link)malloc(sizeof(node));
    if (!newnode) {  
        cout<<"ERROR!! Memory allocation is failed!!"<<endl;
        exit(1);
    }

    newnode->val=val;
    newnode->next=NULL;
    newnode->next=indextable[hash].next;
    indextable[hash].next=newnode;
}

void print_data(int val) {  
    link head;
    int i=0;
    head=indextable[val].next; 
    cout<<setw(2)<<val<<"£º\t"; 
    while (head!=NULL) {  
        cout<<"["<<setw(2)<<head->val<<"]-";
        i++;
        if (i%8==7)
            cout<<"\n\t";
        head=head->next;
    }
    cout<<"\b "<<endl;
}

int findnum(int num) {  
    link ptr;
    int i=0,hash;
    hash=num%7;
    ptr=indextable[hash].next;
    while (ptr!=NULL) {  
        i++;
        if (ptr->val==num) {
            return i;
        } else {
            ptr=ptr->next;
        }
    }
    return 0;
}



/* Output */

/*
Original Data: 
        [15] [16] [18] [14] [21] [ 4] [13] [14] 
        [ 9] [26] [22] [16] [17] 
Please look up the data element (1-30) while ending with -1: £º-1

Hash Table
 0£º    [14]-[21]-[14] 
 1£º    [22]-[15] 
 2£º    [16]-[ 9]-[16] 
 3£º    [17] 
 4£º    [ 4]-[18] 
 5£º    [26] 
 6£º    [13] 
 */