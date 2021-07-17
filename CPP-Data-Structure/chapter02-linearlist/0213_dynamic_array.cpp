#include <iostream>
using namespace std;

int main() {
    int M,N,row,col;
    cout<<"[Input the dimensions of a M x N matrix]"<<endl;
    cout<<"Please input M: ";
    cin>>M;
    cout<<"Please input N: ";
    cin>>N;
    
    int *arrA = new int[M*N];   /* Declare a dynamic array */
    int *arrB = new int[M*N];
    cout<<"[Please input the di matrix]"<<endl;
    for (row=1;row<=M;row++) {
        for (col=1;col<=N;col++) {
            cout<<"a"<<row<<col<<"=";
            cin>>arrA[(row-1)*N+(col-1)];
        }
    }
    cout<<"[Output the original matrix]"<<endl;
    for (row=1;row<=M;row++) {
        for (col=1;col<=N;col++) {
            cout<<arrA[(row-1)*N+(col-1)]<<"\t";
        }
        cout<<endl;
    }
    // Tranpose the matrix
    for (row=1;row<=N;row++)
        for (col=1;col<=M;col++)
            arrB[(col-1)*N+(row-1)]=arrA[(row-1)+(col-1)*N];

    cout<<"[Output the transposed matrix]"<<endl;
    for (row=1;row<=N;row++) {
        for (col=1;col<=M;col++) {
            cout<<arrB[(col-1)*N+(row-1)]<<"\t";
        }
        cout<<endl;
    }
}