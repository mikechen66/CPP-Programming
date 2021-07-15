
/* Breadth First Search Algorithm */

#include <iostream>
#include <cstdlib>
#define MAXSIZE 10  
using namespace std;

int front = -1;   
int rear = -1;    

struct list {
    int x;       
    struct list *next;   
};

typedef struct list node;
typedef node *link;
struct GraphLink {
    link first;
    link last;       
};

int run[9]; 
int queue[MAXSIZE];
struct GraphLink Head[9];

void print(struct GraphLink temp) {
    link current = temp.first;
    while (current!=NULL) {
        cout<<"["<<current->x<<"]";
        current=current->next;
    }
    cout<<endl;
}

void insert(struct GraphLink *temp, int x) {
    link newNode;
    newNode=new node;
    newNode->x=x;
    newNode->next=NULL;  
    if (temp->first==NULL) { 
        temp->first=newNode;
        temp->last=newNode;
    } else {
        temp->last->next=newNode;
        temp->last=newNode;
    }
}

void enqueue(int value) {               /* Define the function of enqueue() */
    if (rear>=MAXSIZE) 
        return;
    rear++;
    queue[rear]=value;
}

int dequeue() {                         /* Define the fucntion of dequeue() */
    if (front==rear) 
        return -1;
    front++;
    return queue[front];
}

void bfs(int current) {                 /* Define the bfs() function */
    link tempnode;       
    enqueue(current);    
    run[current]=1;      
    cout<<"["<<current<<"]";     
    while (front!=rear) {               /* Judge whether it is a empty queue */    
        current=dequeue();        
        tempnode=Head[current].first;   /* tempnode record the posotion of Head */
        while (tempnode!=NULL) {        
            if (run[tempnode->x]==0){
                enqueue(tempnode->x);
                run[tempnode->x]=1;     /* The record has been iterated */
                cout<<"["<<tempnode->x<<"]";
            }
        tempnode=tempnode->next;
        }
    }
} 

/* Declare the array for the edges of the graph */
int main(void) {
    int Data[20][2] =  
    {{1,2},{2,1},{1,3},{3,1},{2,4},{4,2},{2,5},{5,2},{3,6},{6,3},
     {3,7},{7,3},{4,5},{5,4},{6,7},{7,6},{5,8},{8,5},{6,8},{8,6}};
    int DataNum;         
    int i,j; 

    cout<<"THe graph's adjacency list��"<<endl; 

    for (i=1; i<9; i++) {               /* 8 vertices totally */
        run[i]=0;                       /* Set all vertices as not visited */
        cout<<"Vertices"<<i<<"=>";
        Head[i].first=NULL;
        Head[i].last=NULL;                 
        for (j=0; j<20; j++) {
            if (Data[j][0]==i) {        /* If the begining == the head. add the vertice */
                DataNum = Data[j][1];          
                insert(&Head[i],DataNum);
            }
        }
        print(Head[i]);
    }   
    cout<<"BFS traverse vertices��"<<endl;
    bfs(1);
    cout<<endl;
    return 0;
}



/* Output */

/* 
THe graph's adjacency list��
Vertices1=>[2][3]
Vertices2=>[1][4][5]
Vertices3=>[1][6][7]
Vertices4=>[2][5]
Vertices5=>[2][4][8]
Vertices6=>[3][7][8]
Vertices7=>[3][6]
Vertices8=>[5][6]
BFS traverse vertices��
[1][2][3][4][5][6][7][8]
 */