#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
const int _ROWS = 8;        
const int _COLS = 9;        
const int _NOTZERO = 8;           

int main () {  
    int i,j,tmpRW,tmpCL,tmpNZ;
    int temp=1;
    int Sparse[_ROWS][_COLS];       
    int Compress[_NOTZERO][3];      
    srand(time(NULL));
    for (i=0; i<_ROWS; i++)           
        for (j=0; j<_COLS; j++)
            Sparse[i][j]=0;
    tmpNZ=_NOTZERO;
    for (i=1;i<tmpNZ+1;i++) {
        tmpRW = rand()%_ROWS;
        tmpCL = rand()%_COLS;
        if (Sparse[tmpRW][tmpCL]!=0) 
            tmpNZ++;
        Sparse[tmpRW][tmpCL]=i; 
    }
    cout<<"[All elements of a sparse matrix]"<<endl; 
    for (i=0; i<_ROWS; i++) {  
        for (j=0; j<_COLS; j++)
            cout<<"["<<Sparse[i][j]<<"] ";
        cout<<endl;
    }
    /* Start to compress the sparse matrix */
    Compress[0][0] = _ROWS;
    Compress[0][1] = _COLS;
    Compress[0][2] = _NOTZERO;

    for (i=0; i<_ROWS; i++)
        for (j=0; j<_COLS; j++)
            if (Sparse[i][j] != 0) {  
                Compress[temp][0]=i;
                Compress[temp][1]=j;
                Compress[temp][2]=Sparse[i][j];
                temp++;
            }
    cout<<"[Output the sparse matrix after compressing]"<<endl; 
    for (i=0; i<_NOTZERO+1; i++) {  
        for (j=0; j<3; j++)
            cout<<"["<<Compress[i][j]<<"] ";
        cout<<endl;
    }
}



/* Output */

/*

[All elements of a sparse matrix]
[0] [0] [0] [0] [1] [0] [0] [0] [0] 
[0] [0] [0] [0] [0] [0] [0] [0] [0] 
[0] [0] [0] [0] [0] [0] [0] [0] [0] 
[0] [0] [8] [0] [3] [0] [0] [0] [0] 
[0] [5] [0] [0] [0] [0] [6] [0] [0] 
[0] [0] [4] [0] [2] [0] [0] [0] [0] 
[0] [0] [0] [0] [0] [0] [7] [0] [0] 
[0] [0] [0] [0] [0] [0] [0] [0] [0] 
[Output the sparse matrix after compressing]
[8] [9] [8] 
[0] [4] [1] 
[3] [2] [8] 
[3] [4] [3] 
[4] [1] [5] 
[4] [6] [6] 
[5] [2] [4] 
[5] [4] [2] 
[6] [6] [7] 
 */