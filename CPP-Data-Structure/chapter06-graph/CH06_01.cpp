#include <iostream>
using namespace std;

int main(void) {  
    int arr[6][6];
    int data[14][2]={{1,2},{2,1},{1,5},{5,1}, 
                    {2,3},{3,2},{2,4},{4,2},
                    {3,4},{4,3},{3,5},{5,3},
                    {4,5},{5,4}};
    for (int i=0;i<6;i++)
        for (int j=0;j<6;j++)
            arr[i][j]=0;
    for (int i=0;i<14;i++)
        for (int j=0;j<6;j++)
            for (int k=0;k<6;k++)
            {  
                int tmpi, tmpj;
                tmpi=data[i][0];
                tmpj=data[i][1];
                arr[tmpi][tmpj]=1;
            }
    cout<<"Undirected Graph Matrix£º"<<endl;
    for (int i=1;i<6;i++) {  
        for (int j=1;j<6;j++)
        cout<<"["<<arr[i][j]<<"] ";  
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