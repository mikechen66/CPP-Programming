#include <iostream>
using namespace std;
#define ARRAY_SIZE 5             /* Define the dimension of a matrix */
int getValue(int ,int);
int A[ARRAY_SIZE][ARRAY_SIZE]={  /* Upper triangle matrix */
       {7, 8, 12, 21, 9}, 
       {0, 5, 14,  17, 6}, 
       {0, 0, 7, 23, 24}, 
       {0, 0, 0,  32, 19}, 
       {0, 0, 0,  0,  8}};  

/* Declare the 1D array */
int B[ARRAY_SIZE*(1+ARRAY_SIZE)/2];  
int main() {
    int i=0,j=0;
    int index;    
        cout<<"=========================================="<<endl;
        cout<<"Upper triangle matrix: "<<endl;
        for (i=0 ; i<ARRAY_SIZE; i++) {
            for (j=0 ; j<ARRAY_SIZE ; j++) 
                cout<<"\t"<<A[i][j];
            cout<<endl;    
        }
        /* Compress the right upper triangle matrix to a 1D array */
        index=0;
        for (i=0 ; i<ARRAY_SIZE; i++) {
            for (j=0; j<ARRAY_SIZE; j++) {
                if (A[i][j]!=0) B[index++]=A[i][j];
            }
        }
        cout<<"=========================================="<<endl;
        cout<<"Denote it with a 1D array£º"<<endl;
        cout<<"\t[";
        for (i=0; i<ARRAY_SIZE; i++) {
            for (j=i ; j<ARRAY_SIZE; j++) 
                cout<<" "<<getValue(i,j);
        }
        cout<<" ]";
        cout<<endl;    
}
int getValue(int i, int j) {
        int index = ARRAY_SIZE*i - i*(i+1)/2 + j;
        return B[index];
}



/* Output */

/*
==========================================
Upper triangle matrix: 
        7       8       12      21      9
        0       5       14      17      6
        0       0       7       23      24
        0       0       0       32      19
        0       0       0       0       8
==========================================
Denote it with a 1D array£º
        [ 7 8 12 21 9 5 14 17 6 7 23 24 32 19 8 ]
 */
