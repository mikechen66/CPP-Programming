
/* Use the neighbor matrix to create an undirected graph*/

#include <iostream>
using namespace std;

int  main(void) {  
    int arr[5][5],i,j; 
    int data[5][2]={{1,2},{2,1},{2,3},{2,4},{4,3}};
    for (i=0; i<5; i++)
        for (j=0; j<5; j++)
            arr[i][j]=0;
    for (i=0; i<5; i++) 
        for (j=0; j<5; j++) {  
            int tmpi,tmpj;
            tmpi=data[i][0];
            tmpj=data[i][1];
            arr[tmpi][tmpj]=1;
        }
    cout<<"Directed Graph Matrix: "<<endl;
    for (i=1; i<5; i++) {  
        for (j=1; j<5; j++)
        cout<<"["<<arr[i][j]<<"] ";
        cout<<endl;
    }
}


/* Outpout */

/*
Directed Graph Matrix: 
[0] [1] [0] [0] 
[1] [0] [1] [1] 
[0] [0] [0] [0] 
[0] [0] [1] [0] 
 */