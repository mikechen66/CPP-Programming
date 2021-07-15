
/* Dijkstra Algorithm */

#include <iostream>
#include <cstdlib>
#include <iomanip>

#define SIZE   7  
#define NUMBER 6
#define INFINITE  99999     
using namespace std;

int Graph_Matrix[SIZE][SIZE];       
int distance[SIZE];             

void BuildGraph_Matrix(int *Path_Cost) {
    int Start_Point;     
    int End_Point;       
    int i, j;
    for ( i = 1; i < SIZE; i++ )
        for ( j = 1; j < SIZE; j++ )
            if ( i == j )
                Graph_Matrix[i][j] = 0; 
            else
                Graph_Matrix[i][j] = INFINITE;   
    i=0;
    while(i<SIZE) {
        Start_Point = Path_Cost[i*3]; 
        End_Point = Path_Cost[i*3+1]; 
        Graph_Matrix[Start_Point][End_Point]=Path_Cost[i*3+2];
        i++;
   }
}

void printGraph_Matrix() {
    int i, j;
    for (i = 1; i < SIZE; i++) {
        cout<<"vex"<<i;
        for (j = 1; j<SIZE; j++)
            if (Graph_Matrix[i][j] == INFINITE)
                cout<<setw(5)<<'x';
            else
                cout<<setw(5)<<Graph_Matrix[i][j];
        cout<<endl;
    }
}

void shortestPath(int vertex1, int vertex_total) {       
    extern int distance[SIZE];       
    int shortest_vertex = 1;         
    int shortest_distance;           
    int goal[SIZE];              
    int i,j;
    
    for (i = 1; i <= vertex_total; i++) { 
        goal[i] = 0;    
        distance[i] = Graph_Matrix[vertex1][i]; 
    }

    goal[vertex1] = 1;  
    distance[vertex1] = 0;  
    cout<<endl; 

    for (i=1; i<=vertex_total-1; i++) {      
        shortest_distance = INFINITE;      
        for (j=1; j<=vertex_total; j++) {
            if (goal[j]==0&&shortest_distance>distance[j]) {
                shortest_distance=distance[j];                                              
                shortest_vertex=j;              
            }
        }
        goal[shortest_vertex] = 1;  

        for (j=1; j<=vertex_total; j++) {
            if (goal[j] == 0 && 
                    distance[shortest_vertex]+Graph_Matrix[shortest_vertex][j]
                    <distance[j]) {
                distance[j]=distance[shortest_vertex]
                +Graph_Matrix[shortest_vertex][j];
            }       
        }
    }
}

int main(void) {
    extern int distance[SIZE];       
    int Path_Cost[7][3] = { {1, 2, 10}, 
                            {2, 3, 20},
                            {2, 4, 25},
                            {3, 5, 18},
                            {4, 5, 22},
                            {4, 6, 95},
                            {5, 6, 77} }; 
    int j;
    BuildGraph_Matrix(&Path_Cost[0][0]);
    cout<<"==========================================="<<endl;
    cout<<"The adjacency matrix: "<<endl;
    cout<<"==========================================="<<endl;
    cout<<"Vert¡¡vex1 vex2 vex3 vex4 vex5 vex6"<<endl;
    printGraph_Matrix();  
    shortestPath(1,NUMBER); 
    cout<<"==========================================="<<endl;
    cout<<"Vertice 1 to others - shortest distance"<<endl;
    cout<<"==========================================="<<endl;
    for (j=1;j<SIZE;j++) 
        cout<<"Vertice 1 to Vertice"<<setw(2)<<j<<"shortest distance="
        <<setw(3)<<distance[j]<<endl;
    cout<<endl;
    return 0; 
}


/* Output */

/*
===========================================
The adjacency matrix: 
===========================================
Vert¡¡vex1 vex2 vex3 vex4 vex5 vex6
vex1    0   10    x    x    x    x
vex2    x    0   20   25    x    x
vex3    x    x    0    x   18    x
vex4    x    x    x    0   22   95
vex5    x    x    x    x    0   77
vex6    x    x    x    x    x    0

===========================================
Vertice 1 to others - shortest distance
===========================================
Vertice 1 to Vertice 1shortest distance=  0
Vertice 1 to Vertice 2shortest distance= 10
Vertice 1 to Vertice 3shortest distance= 30
Vertice 1 to Vertice 4shortest distance= 35
Vertice 1 to Vertice 5shortest distance= 48
Vertice 1 to Vertice 6shortest distance=125
 */