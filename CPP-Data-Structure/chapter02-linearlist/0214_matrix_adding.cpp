#include <iostream>
using namespace std;

const int  ROWS = 3;
const int COLS = 3;

void MatrixAdd(int*, int*, int*, int, int);   /* Define a function */
int main() {
    int A[ROWS][COLS] = { {1,3,5},
                          {7,9,11},
                          {13,15,17}};
    int B[ROWS][COLS] = { {9,8,7},
                          {6,5,4},
                          {3,2,1}};

    int C[ROWS][COLS] = {0};

    cout<<"[All elements of the matrix A]"<<endl;  //输出矩阵A的内容
    for (int i=0; i<ROWS; i++) {
        for (int j=0;j<COLS;j++)
            cout<<A[i][j]<<"\t";
        cout<<endl;
    }
    cout<<"[All elements of the matrix B]"<<endl;   //输出矩阵B的内容
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++)
            cout<<B[i][j]<<"\t";
        cout<<endl;
    }
    MatrixAdd(&A[0][0],&B[0][0],&C[0][0],ROWS,COLS);
    cout<<"[Show the addition of A and B]"<<endl; //输出A+B的内容
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++)
            cout<<C[i][j]<<"\t";
        cout<<endl;
    }
}

void MatrixAdd(int* arrA,int* arrB,int* arrC,int dimX,int dimY) {
    if (dimX<=0||dimY<=0) {
        cout<<"the dimension must be larger than 0"<<endl;
        return;
    }
    for (int row=1;row<=dimX;row++)
        for (int col=1;col<=dimY;col++)
            arrC[(row-1)*dimY+(col-1)]=arrA[(row-1)*dimY+(col-1)]+arrB[(row-1)*dimY+(col-1)];
}



/* Output */

/*
[All elements of the matrix A]
1       3       5
7       9       11
13      15      17
[All elements of the matrix B]
9       8       7
6       5       4
3       2       1
[Show the addition of A and B]
10      11      12
13      14      15
16      17      18
 */