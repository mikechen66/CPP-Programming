#include <iostream>
using namespace std;

void MatrixMultiply(int*,int*,int*,int,int,int);

int main() {
    int M,N,P;
    int i,j;
    /* Matrix A */ 
    cout<<"Please input the A matrix's dimension (M,N): "<<endl;
    cout<<"M= ";
    cin>>M;
    cout<<"N= ";
    cin>>N;
    int *A = new int[M*N];
    cout<<"[Please input all elements of Matrix A]"<<endl;
    for (i=0; i<M; i++)
        for (j=0; j<N; j++) {
            cout<<"a"<<i<<j<<"=";
            cin>>A[i*N+j];
        }

    // Matrix B 
    cout<<"Please input the Matrix B's dimension (N,P): "<<endl;
    cout<<"N= ";
    cin>>N;
    cout<<"P= ";
    cin>>P;
    int *B = new int [N*P];
    cout<<"[Please input all elements of the Matrix B]"<<endl;

    for (i=0; i<N; i++)
        for (j=0; j<P; j++){
            cout<<"b"<<i<<j<<"=";
            cin>>B[i*P+j];
        }   
    int *C = new int [M*P];
    MatrixMultiply(A,B,C,M,N,P); //µ÷ÓÃº¯Êı 
    cout<<"[AxB is resulted as follow]"<<endl;

    for (i=0; i<M; i++) {
        for (j=0; j<P; j++)
            cout<<C[i*P+j]<<"\t";
        cout<<endl;
    }
}

/* Matrix multiplication */ 
void MatrixMultiply(int* arrA,int* arrB,int* arrC,int M,int N,int P) {
    if (M<=0||N<=0||P<=0) {
        cout<<"[Error: the dimension M, N orP must be larger than 0]"<<endl;
        return;
    }
    for (int i=0;i<M;i++)
        for (int j=0;j<P;j++) {
            int Temp;
            Temp = 0;
            for (int k=0;k<N;k++)
                Temp = Temp + arrA[i*N+k]*arrB[k*P+j];
            arrC[i*P+j] = Temp;
        }
}



/* Output */

/* 
Please input the A matrix's dimension (M,N): 
M= 4
N= 4
[Please input all elements of Matrix A]
a00=
...
 */
