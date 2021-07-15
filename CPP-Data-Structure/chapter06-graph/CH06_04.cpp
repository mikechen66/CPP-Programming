#include <iostream>
using namespace std;

class list {  
    public:
    int val;
    class list *next;
};

typedef class list node;
typedef node *link;
class list* head[9];
void dfs(int);
int run[9];

int main(void) {  
    link ptr,newnode;
    int data[20][2]={{1,2},{2,1},{1,3},{3,1},
                     {2,4},{4,2},{2,5},{5,2},
                     {3,6},{6,3},{3,7},{7,3},
                     {4,5},{5,4},{6,7},{7,6},
                     {5,8},{8,5},{6,8},{8,6}};
    for (int i=1;i<=8;i++) {  
        run[i]=0;       
        head[i]= new node;   
        head[i]->val=i;    
        head[i]->next=NULL;
        ptr=head[i];      
        for (int j=0;j<20;j++) {  
            if (data[j][0]==i) {  
                newnode =new node;
                newnode->val=data[j][1];
                newnode->next=NULL;
                do {
                    ptr->next=newnode;
                    ptr=ptr->next;
                } while (ptr->next!=NULL);
            }
        } 
    }

    cout<<"The graph's adjacency list: "<<endl;

    for(int i=1; i<=8; i++){
        ptr=head[i];
        cout<<"Vertices"<<i<<"=> ";
        ptr = ptr->next;
        while(ptr!=NULL) {
            cout<<"["<<ptr->val<<"] ";
            ptr=ptr->next;
        }
        cout<<endl;
    }

    cout<<"DFS traverses vertices: "<<endl;
    dfs(1);
    cout<<endl;
}

void dfs(int current) {  
    link ptr;
    run[current]=1;
    cout<<"["<<current<<"] ";
    ptr=head[current]->next;
    while (ptr!=NULL) {       
        if (run[ptr->val]==0) 
            dfs(ptr->val);   
        ptr=ptr->next;
    }
}



/* Output */

/*
The graph's adjacency list: 
Vertices1=> [2] [3] 
Vertices2=> [1] [4] [5] 
Vertices3=> [1] [6] [7] 
Vertices4=> [2] [5] 
Vertices5=> [2] [4] [8] 
Vertices6=> [3] [7] [8] 
Vertices7=> [3] [6] 
Vertices8=> [5] [6] 
DFS traverses vertices: 
[1] [2] [4] [5] [8] [6] [3] [7]
 */