#include <iostream>
using namespace std;

int main() {
    int arrB[4][4],i,j;
    int arrA[4][4]={ {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
    cout<<"[Output the original matrix]"<<endl;
    
    for (i=0;i<4;i++) {
        for (j=0; j<4; j++) {
            cout<<arrA[i][j]<<"\t";
        }
        cout<<endl;
    }
    /* Tranpose the matrix */
    for (i=0; i<4; i++)
        for (j=0; j<4; j++)
            arrB[i][j]=arrA[j][i];

    cout<<"[Output the transposed matrix]"<<endl;
    
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            cout<<arrB[i][j]<<"\t";
        } 
        cout<<endl;  
    }
}


/* Output */

/*
[Output the original matrix]
1       2       3       4
5       6       7       8
9       10      11      12
13      14      15      16
[Output the transposed matrix]
1       5       9       13
2       6       10      14
3       7       11      15
4       8       12      16

 */