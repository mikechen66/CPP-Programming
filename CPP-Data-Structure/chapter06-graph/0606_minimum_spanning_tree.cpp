
/* Minimum spanning tree */

#include <iostream>
#define VERTS   6   
using namespace std;

class edge {  
    public:
        int from,to;
        int find,val;
        class edge* next;
};

typedef class edge node;
typedef node* mst;
void mintree(mst head);
mst findmincost(mst head);    
int v[VERTS+1];

int main(void) {  
    int data[10][3] = {{1,2,6},{1,6,12},
                      {1,5,10},{2,3,3},
                      {2,4,5},{2,6,8},{3,4,7},{4,6,11},
                      {4,5,9},{5,6,16}};
    mst head,ptr,newnode;
    head=NULL;

    cout<<"Create the graph's linked list£º"<<endl;

    for (int i=0; i<10; i++) {  
        for (int j=1; j<=VERTS; j++) {  
            if (data[i][0]==j) {  
                newnode = new node;
                newnode->from=data[i][0];
                newnode->to=data[i][1];
                newnode->val=data[i][2];
                newnode->find=0;
                newnode->next=NULL;
                if (head==NULL) {  
                    head=newnode;
                    head->next=NULL;
                    ptr=head;
                } else {  
                    ptr->next=newnode;
                    ptr=ptr->next;
                }
            }
        }
    }

    ptr=head;

    while (ptr!=NULL) {  
        cout<<"Starting Vertices ["<<ptr->from<<"]\tEnding Vertices ["
        <<ptr->to<<"]\tLength of the Path ["<<ptr->val<<"]";
        cout<<endl;
        ptr=ptr->next;
    }

    cout<<"Create the minimum spanning tree£º"<<endl;
    mintree(head); 
    delete newnode;
}

mst findmincost(mst head) {                       /* Search the minimum edge */
    int minval=100;
    mst ptr,retptr;
    ptr=head;
    while (ptr!=NULL) {
        if (ptr->val<minval && ptr->find==0) {    /* If ptr£­>vale < minval */
            minval=ptr->val;                      /* Set ptr->val as a minimum value */
            retptr=ptr;                           /* Record the ptr */
        }
        ptr=ptr->next;
    }
    retptr->find=1;                               /* Set retptr as a found edge*/
    return retptr;     
}

void mintree(mst head) {                          /* Minimum spanning tree*/
    mst ptr,mceptr;
    int result=0;
    ptr=head;

    for (int i=0; i<=VERTS; i++)
        v[i]=0;

    while (ptr!=NULL) {
        mceptr=findmincost(head);
        v[mceptr->from]++;
        v[mceptr->to]++;
        if (v[mceptr->from]>1 && v[mceptr->to]>1) {
            v[mceptr->from]--;
            v[mceptr->to]--;
            result=1;
        } else {
            result=0;
        }
        if (result==0) {
            cout<<"Starting Vertice ["<<mceptr->from
            <<"]\tEnding Vertice ["<<mceptr->to<<"]\tLength of the Path ["
            <<mceptr->val<<"]"<<endl;
        }
        ptr=ptr->next;
    }
}


/* Output */

/*
Create the graph's linked list£º
Starting Vertice [1]    Ending Vertice [2]      Length of the Path [6]
Starting Vertice [1]    Ending Vertice [6]      Length of the Path [12]
Starting Vertice [1]    Ending Vertice [5]      Length of the Path [10]
Starting Vertice [2]    Ending Vertice [3]      Length of the Path [3]
Starting Vertice [2]    Ending Vertice [4]      Length of the Path [5]
Starting Vertice [2]    Ending Vertice [6]      Length of the Path [8]
Starting Vertice [3]    Ending Vertice [4]      Length of the Path [7]
Starting Vertice [4]    Ending Vertice [6]      Length of the Path [11]
Starting Vertice [4]    Ending Vertice [5]      Length of the Path [9]
Starting Vertice [5]    Ending Vertice [6]      Length of the Path [16]
Create the minimum spanning tree£º
Starting Vertice [2]    Ending Vertice [3]      Length of the Path [3]
Starting Vertice [2]    Ending Vertice [4]      Length of the Path [5]
Starting Vertice [1]    Ending Vertice [2]      Length of the Path [6]
Starting Vertice [2]    Ending Vertice [6]      Length of the Path [8]
Starting Vertice [4]    Ending Vertice [5]      Length of the Path [9]
 */