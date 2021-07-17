#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;

int main(void) {  
    int i,j,val=0,data[80]={0};
    for (i=0; i<80; i++)
        data[i]=(rand()%150+1);
    while (val!=-1) {  
        int find=0;
        cout<<"Please look up the pair of key-value (1-150) ending with -1: ";
        cin>>val;
        for (i=0; i<80; i++) {  
            if (data[i]==val) {  
                cout<<"Find out it in "<<setw(3)<<i+1<<"th the location ["<<data[i]<<"]"<<endl;
                find++;
            }
        }
        if (find==0 && val !=-1)
            cout<<"######Do not find it ["<<val<<"]######"<<endl;
    }
    cout<<"Content data: "<<endl;
    for (i=0; i<10; i++) { 
        for (j=0; j<8; j++)
            cout<<setw(2)<<i*8+j+1<<"["<<setw(3)<<data[i*8+j]<<"]  ";
        cout<<endl;
    }
    return 0;
}



/* Output */


/* 
Please look up the pair of key-value (1-150)£¬ending with -1: 15
Find out it in  75th the location [15]
Find out it in  78th the location [15]
Please look up the pair of key-value (1-150)£¬ending with -1: 
 */