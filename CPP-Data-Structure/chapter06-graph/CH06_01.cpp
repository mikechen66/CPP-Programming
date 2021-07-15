/* Undirected Graph Matrix */

#include <iostream>
using namespace std;

int main(void) {  
    int arr[6][6];
    int data[14][2] = {{1,2},{2,1},{1,5},{5,1}, /* Each edge's starting and ending value */
                      {2,3},{3,2},{2,4},{4,2},
                      {3,4},{4,3},{3,5},{5,3},
                      {4,5},{5,4}};
    for (int i=0; i<6; i++)
        for (int j=0; j<6; j++)
            arr[i][j] = 0;

    for (int i=0; i<14; i++)                    /* Iterate the data of the graph */
        for (int j=0; j<6; j++)                 /* Iterate the arr matrix */
            for (int k=0; k<6; k++) {           /* Iterate the element of k */
                int tmpi, tmpj;               
                tmpi = data[i][0];              /* tmpi is the starting vertice */
                tmpj = data[i][1];              /* tmpj is the ending vertice */
                arr[tmpi][tmpj] = 1;            /* Fill 1 if it has an edge */
            }

    cout<<"Undirected Graph Matrix£º"<<endl;

    for (int i=1; i<6; i++) {  
        for (int j=1; j<6; j++)
            cout<<"["<<arr[i][j]<<"] ";         /* Output the matrix  */
        cout<<endl;
    }
}


/* Output */

/*
Undirected Graph Matrix£º
[0] [1] [0] [0] [1] 
[1] [0] [1] [1] [0] 
[0] [1] [0] [1] [1] 
[0] [1] [1] [0] [1] 
[1] [0] [1] [1] [0]
 */