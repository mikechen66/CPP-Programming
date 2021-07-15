#include <iostream>
#include <cstdlib>
#include <iomanip>
#define MAX 20
using namespace std;

int fib(int n) {
    if (n==1 || n==0) {
        return n;
    } else {
        return fib(n-1)+fib(n-2);
    }
}

int fib_search(int data[MAX],int SearchKey) {
    int index=2; 
    while (fib(index)<=MAX)
        index++;
    index--;
    int RootNode=fib(index);
    int diff1=fib(index-1); 
    int diff2=RootNode-diff1;
    RootNode--; 

    while (1) {
        if (SearchKey==data[RootNode]){
            return RootNode;
        } else {
            if (index==2) {
                return MAX; 
            }
            if (SearchKey<data[RootNode]) {
                RootNode=RootNode-diff2;
                int temp=diff1;
                diff1=diff2;
                diff2=temp-diff2;
                index=index-1;
            } else {
                if (index==3) 
                    return MAX;
                RootNode=RootNode+diff2;
                diff1=diff1-diff2;
                diff2=diff2-diff1;
                index=index-2;
           }         
       }
    }
}

int main(void) {  
    int data[]={5,7,12,23,25,37,48,54,68,77,
                91,99,102,110,118,120,130,135,136,150};
    int val;
    int i=0;
    int j=0;

    while (1) {  
        cout<<"Please look up the pair of key-value (1-150) while ending with -1: ";
        cin>>val;
        if (val==-1)
            break;
        int RootNode=fib_search(data,val);
        if (RootNode==MAX)
            cout<<"##### Do not find it["<<setw(3)<<val<<"] #####"<<endl;
        else
            cout<<"Find out it in "<<setw(2)<<RootNode+1<<"th location ["<<setw(3)<<data[RootNode]<<"]"<<endl;
    }
    cout<<"Data content: "<<endl;
    for (i=0; i<2; i++) { 
        for (j=0; j<10; j++)
            cout<<setw(3)<<i*10+j+1<<"-"<<setw(3)<<data[i*10+j];
        cout<<endl;
    }
    return 0;
}



/* Output */

/*
Please look up the pair of key-value (1-150) while ending with -1: 6
##### Do not find it[  6] #####
Please look up the pair of key-value (1-150) while ending with -1: 18
##### Do not find it[ 18] #####
Please look up the pair of key-value (1-150) while ending with -1: 9
##### Do not find it[  9] #####
Please look up the pair of key-value (1-150) while ending with -1: 4
##### Do not find it[  4] #####
Please look up the pair of key-value (1-150) while ending with -1: 4
##### Do not find it[  4] #####
Please look up the pair of key-value (1-150) while ending with -1: 3
##### Do not find it[  3] #####
Please look up the pair of key-value (1-150) while ending with -1: 6
##### Do not find it[  6] #####
Please look up the pair of key-value (1-150) while ending with -1: 89
##### Do not find it[ 89] #####
Please look up the pair of key-value (1-150) while ending with -1: 90
##### Do not find it[ 90] #####
Please look up the pair of key-value (1-150) while ending with -1: 
 */
