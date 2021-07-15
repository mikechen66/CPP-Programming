
/* Floyd Algorithm (the shortest distance between any two adjacency vertices) */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#define SIZE   7  
#define INFINITE  99999 
#define NUMBER 6
using namespace std;
int Graph_Matrix[SIZE][SIZE];
int distance[SIZE][SIZE];       

void BuildGraph_Matrix(int *Path_Cost) {
    int Start_Point; 
    int End_Point;   
    int i, j;
    for (i=1; i<SIZE; i++)
        for (j = 1; j < SIZE; j++)
            if (i==j)
            Graph_Matrix[i][j] = 0; 
            else
                Graph_Matrix[i][j] = INFINITE;  
    i=0;

    while (i<SIZE) {
        Start_Point = Path_Cost[i*3]; 
        End_Point = Path_Cost[i*3+1]; 
        Graph_Matrix[Start_Point][End_Point]=Path_Cost[i*3+2];
        i++;
   }
}

void printGraph_Matrix() {
    int i, j;
    for (i = 1; i < SIZE; i++) {
        cout<<"vex%d"<<i;
        for (j = 1; j < SIZE; j++)
            if (Graph_Matrix[i][j] == INFINITE)
                cout<<setw(5)<<'x';
            else
                cout<<setw(5)<<Graph_Matrix[i][j];
        cout<<endl;
   }
}

void shortestPath(int vertex_total) {       
    int i,j,k;
    extern int distance[SIZE][SIZE];     

    for (i=1;i<=vertex_total;i++ )
        for (j=i; j<=vertex_total; j++) {
            distance[i][j]=Graph_Matrix[i][j]; 
            distance[j][i]=Graph_Matrix[i][j];        
        }

    for (k=1;k<=vertex_total;k++ ) 
        for (i=1;i<=vertex_total;i++ )
            for (j=1;j<=vertex_total;j++ )
                if (distance[i][k]+distance[k][j]<distance[i][j])
                    distance[i][j] = distance[i][k] + distance[k][j];   
}

int main(void) {
    extern int distance[SIZE][SIZE];     
    int Path_Cost[7][3] = { {1, 2, 10}, 
                            {2, 3, 20},
                            {2, 4, 25},
                            {3, 5, 18},
                            {4, 5, 22},
                            {4, 6, 95},
                            {5, 6, 77} }; 
    int i,j;
    BuildGraph_Matrix(&Path_Cost[0][0]);
    cout<<"===================================================="<<endl;
    cout<<"The adjacency matrix: "<<endl;
    cout<<"===================================================="<<endl;
    cout<<"Vert: vex1 vex2 vex3 vex4 vex5 vex6"<<endl;
    printGraph_Matrix(); 
    cout<<"====================================================="<<endl;
    cout<<"the shortest distance between any adjacency vertices: "<<endl;
    cout<<"====================================================="<<endl;
    shortestPath(NUMBER); 

    cout<<"Vert vex1 vex2 vex3 vex4 vex5 vex6"<<endl;
    for (i = 1; i <= NUMBER; i++){
        cout<<"vex"<<i;
        for (j = 1; j<= NUMBER; j++) {
            cout<<setw(5)<<distance[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    return 0; 
}


/* Output */

/*
====================================================
The adjacency matrix: 
====================================================
Vert: vex1 vex2 vex3 vex4 vex5 vex6
vex%d1    0   10    x    x    x    x
vex%d2    x    0   20   25    x    x
vex%d3    x    x    0    x   18    x
vex%d4    x    x    x    0   22   95
vex%d5    x    x    x    x    0   77
vex%d6    x    x    x    x    x    0
=====================================================
the shortest distance between any adjacency vertices: 
=====================================================
Vert vex1 vex2 vex3 vex4 vex5 vex6
vex1    0   10   30   35   48  125
vex2   10    0   20   25   38  115
vex3   30   20    0   40   18   95
vex4   35   25   40    0   22   95
vex5   48   38   18   22    0   77
vex6  125  115   95   95   77    0
 */