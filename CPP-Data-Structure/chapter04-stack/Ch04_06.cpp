
/* Compute the path of labyrint */

#include <iostream>

#define EAST  MAZE[x][y+1]  
#define WEST  MAZE[x][y-1]  
#define SOUTH MAZE[x+1][y]  
#define NORTH MAZE[x-1][y]  

using namespace std;
const int ExitX = 8;                               
const int ExitY = 10;                              

struct list {
    int x,y;
    struct list* next;
};
typedef struct list node;
typedef node* link;
int MAZE[10][12] = { 1,1,1,1,1,1,1,1,1,1,1,1,      /* Declare the array for labyrinth */
                     1,0,0,0,1,1,1,1,1,1,1,1,
                     1,1,1,0,1,1,0,0,0,0,1,1,
                     1,1,1,0,1,1,0,1,1,0,1,1,
                     1,1,1,0,0,0,0,1,1,0,1,1,
                     1,1,1,0,1,1,0,1,1,0,1,1,
                     1,1,1,0,1,1,0,1,1,0,1,1,
                     1,1,1,1,1,1,0,1,1,0,1,1,
                     1,1,0,0,0,0,0,0,1,0,0,1,
                     1,1,1,1,1,1,1,1,1,1,1,1};
link push(link stack,int x,int y);
link pop(link stack,int* x,int* y);
int chkExit(int ,int ,int,int);

int main(void) {
    int i,j;
    link path = NULL;
    int x=1;                                        /* x coordinate at the entrance */
    int y=1;                                        /* y coordinate at the entrance */
    cout<<"[The path of labyrinth (part of them is 0)]"<<endl;  /* Print the roadmap of the labyrint */
    
    for (i=0; i<10; i++) {
        for (j=0; j<12; j++)
            cout<<MAZE[i][j]<<" ";
        cout<<endl;
    }

    while (x<=ExitX&&y<=ExitY) {
        MAZE[x][y]=2;
        if (NORTH==0) {
            x -= 1;
            path=push(path,x,y);
        } else if (SOUTH==0) {
            x+=1;
            path=push(path,x,y);
        } else if (WEST==0) {
            y-=1;
            path=push(path,x,y);
        } else if (EAST==0) {
            y+=1;
            path=push(path,x,y);
        } else if (chkExit(x,y,ExitX,ExitY)==1) {    /* Check whether it arrives at the exit */
            break;
        } else {
            MAZE[x][y]=2;
            path=pop(path,&x,&y);
        }
    }

    cout<<"[The path of mouse walking (part of them is 2)]"<<endl;            
    for (i=0; i<10; i++) {
        for (j=0; j<12; j++)
            cout<<MAZE[i][j]<<" ";
        cout<<endl;
    }  
    return 0;
}

link push(link stack, int x, int y) {
    link newnode;
    newnode = new node;
    if (!newnode) {
        cout<<"Error!Memory allocation is failed!"<<endl;
        return NULL;
    }
    newnode->x=x;
    newnode->y=y;
    newnode->next=stack;
    stack=newnode;
    return stack;
}

link pop(link stack, int* x, int* y) {
    link top;
    if (stack!=NULL) {
        top=stack;
        stack=stack->next;
        *x=top->x;
        *y=top->y;
        delete top;
        return stack;
    } else {
        *x=-1;
    }
    return stack;
}

int chkExit(int x,int y,int ex,int ey) {
    if (x==ex&&y==ey) {
        if (NORTH==1||SOUTH==1||WEST==1||EAST==2)
            return 1;
        if (NORTH==1||SOUTH==1||WEST==2||EAST==1)
            return 1;
        if (NORTH==1||SOUTH==2||WEST==1||EAST==1)
            return 1;
        if (NORTH==2||SOUTH==1||WEST==1||EAST==1)
            return 1;
    }
    return 0;
}



/* Output */

/* 
[The path of labyrinth (part of them is 0)]
1 1 1 1 1 1 1 1 1 1 1 1 
1 0 0 0 1 1 1 1 1 1 1 1 
1 1 1 0 1 1 0 0 0 0 1 1 
1 1 1 0 1 1 0 1 1 0 1 1 
1 1 1 0 0 0 0 1 1 0 1 1 
1 1 1 0 1 1 0 1 1 0 1 1 
1 1 1 0 1 1 0 1 1 0 1 1 
1 1 1 1 1 1 0 1 1 0 1 1 
1 1 0 0 0 0 0 0 1 0 0 1 
1 1 1 1 1 1 1 1 1 1 1 1 
[The path of mouse walking (part of them is 2)]
1 1 1 1 1 1 1 1 1 1 1 1 
1 2 2 2 1 1 1 1 1 1 1 1 
1 1 1 2 1 1 2 2 2 2 1 1 
1 1 1 2 1 1 2 1 1 2 1 1 
1 1 1 2 2 2 2 1 1 2 1 1 
1 1 1 2 1 1 0 1 1 2 1 1 
1 1 1 2 1 1 0 1 1 2 1 1 
1 1 1 1 1 1 0 1 1 2 1 1 
1 1 0 0 0 0 0 0 1 2 2 1 
1 1 1 1 1 1 1 1 1 1 1 1 
 */