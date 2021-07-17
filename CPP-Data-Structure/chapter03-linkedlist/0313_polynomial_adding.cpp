
/* Addition of the polynonials */

#include <iostream>
using namespace std;

class list {                            
    public :
    int coef,exp;
    class list *next;
};

typedef class list node;
typedef node *link;
link creat_link(int data[4]);
void print_link(link head);
link sum_link(link a,link b);

int main() {  
    link a,b,c;
    int data1[4]={3,0,4,2};                  /* Coefficient of the polynormial */
    int data2[4]={6,8,6,9};          
    cout<<"Original polynomial£º"<<endl<<"A=";
    a=creat_link(data1);                     /* Create the polynomial A */
    b=creat_link(data2);                 
    print_link(a);                        
    cout<<"B=";
    print_link(b);                        
    cout<<"Result of polynomial addition: \nC=";
    c=sum_link(a,b);                         /* C is summed with A and B C. */
    print_link(c);                       
    system("pause");
}

link creat_link(int data[4]) {               /* Create a subroutine of a polynomial */
    link head,newnode,ptr;
    for (int i=0; i<4; i++) {  
        newnode = new node;
        if (!newnode) {  
            cout<<"Error!! Memory allocation is failed!!"<<endl;
            exit(1);
        }
        if (i==0) {  
            newnode->coef=data[i];
            newnode->exp=3-i;
            newnode->next=NULL;
            head=newnode;
            ptr=head;
        } else if (data[i]!=0) {  
            newnode->coef=data[i];
            newnode->exp=3-i;
            newnode->next=NULL;
            ptr->next=newnode;
            ptr=newnode;
        }
    }
    return head;
}

void print_link(link head) {                 
    while (head!=NULL) {  
        if (head->exp==1 && head->coef!=0)   /* While X^1, do noe show the index */
            cout<<head->coef<<"X + ";
        else if (head->exp!=0 && head->coef!=0)
            cout<<head->coef<<"X^"<<head->exp<<" + ";
        else if (head->coef!=0)              /* while X^0, do not show variables */
            cout<<head->coef;
        head=head->next;
    }
    cout<<endl;
}

link sum_link(link a,link b) {               /* Add the polynormial subroutine */
    int sum[4],i=0;
    link ptr;
    ptr=b;
    while (a!=NULL) {                        /* Judge the polynomial A */
        b=ptr;                               /* Compare the index of both A and B */
        while (b!=NULL) {  
            if (a->exp==b->exp) {            /* Add the coefficients while the index is same */
                sum[i]=a->coef+b->coef;
                a=a->next;
                b=b->next;
                i++;
            } else if (b->exp > a->exp) {    /* While the index of B is bigger£¬consign a coeficient */
                sum[i]=b->coef;
                b=b->next;
                i++;
            } else if (a->exp > b->exp) {    /* A While the index of A is bigger, consign coefficient to C */
                sum[i]=a->coef;
                a=a->next;
                i++;
            }
        }
    }
    return creat_link(sum);                
}


/* Output */

/* 
Original polynomial£º
A=3X^3 + 4X + 2
B=6X^3 + 8X^2 + 6X + 9
Result of polynomial addition: 
C=9X^3 + 8X^2 + 10X + 11
sh: 1: pause: not found
 */