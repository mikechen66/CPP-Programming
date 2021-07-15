
/* Use the adjacency list to express Graph (a) and (b)*/

#include <iostream>
using namespace std;

class list {
    public:
    int val;
    class list *next;
};

class list head[6];

int main(void) {  
    list *ptr,*newnode;
    int data[14][2]={{1,2},{2,1},{1,5},{5,1},
                    {2,3},{3,2},{2,4},{4,2},
                    {3,4},{4,3},{3,5},{5,3},
                    {4,5},{5,4}};

    cout<<"Graph(a) adjacency list: "<<endl;

    for (int i=1; i<6; i++) {  
        head[i].val=i; 
        head[i].next=NULL;
        cout<<"Vertice"<<i<<" =>";  
        ptr=&(head[i]);             
        for (int j=0; j<14; j++) {  
            if (data[j][0]==i) {  
                newnode = new list;
                newnode->val=data[j][1];
                newnode->next=NULL;
                while (ptr!=NULL)        
                    ptr=ptr->next;
                ptr=newnode;            
                cout<<"["<<newnode->val<<"] ";
            }
        }   
        cout<<endl;
    }
}


/* Output */

/*
Graph(a) adjacency list: 
Vertice1 =>[2] [5] 
Vertice2 =>[1] [3] [4] 
Vertice3 =>[2] [4] [5] 
Vertice4 =>[2] [3] [5] 
Vertice5 =>[1] [3] [4] 
 */

