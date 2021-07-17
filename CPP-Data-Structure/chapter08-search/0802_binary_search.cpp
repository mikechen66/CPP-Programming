#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;

int bin_search(int data[50],int val);

int main(void) {  
    int num,val=1,data[50]={0};
    for (int i=0; i<50; i++) {  
        data[i]=val;
        val+=(rand()%5+1);
    }
    while (1) {  
        num=0;
        cout<<"Please look up the pair of key-value (1-150) while ending with -1: ";
        cin>>val;
        if (val==-1)
            break;
        num=bin_search(data,val);
        if (num==-1)
            cout<<"##### Do not find it["<<setw(3)<<val<<"] #####"<<endl;
        else
            cout<<"Find out it in "<<setw(2)<<num+1<<"th the location ["<<setw(3)<<data[num]<<"]"<<endl;
    }
    cout<<"Data content: "<<endl;
    for (int i=0; i<5; i++) { 
        for (int j=0; j<10; j++)
            cout<<setw(3)<<i*10+j+1<<"-"<<setw(3)<<data[i*10+j];
        cout<<endl;
    }
    cout<<endl;
    return 0;
}

int bin_search(int data[50],int val) {  
    int low, mid, high;
    low=0;
    high=49;
    cout<<"Is looking up......"<<endl;
    while (low <= high && val !=-1) {  
        mid=(low+high)/2;
        if (val<data[mid]) {  
            cout<<val<<" It is between "<<low+1<<"["<<setw(3)<<data[low]<<"]and the middle value "<<mid+1<<"["<<setw(3)<<data[mid]<<"]£¬find the left side"<<endl;
            high=mid-1;      
        } else if (val>data[mid]) {  
            cout<<val<<" It is between "<<mid+1<<"["<<setw(3)<<data[mid]<<"]and"<<high+1<<"["<<setw(3)<<data[high]<<"]£¬please find the left side"<<endl;         
            low=mid+1;           
        } else {
            return mid;
        }
    }
    return -1;
}



/* Output */

/* 
Please look up the pair of key-value (1-150) while ending with -1: 19
Is looking up......
19 It is between 1[  1]and the middle value 25[ 68]£¬find the left side
19 It is between 1[  1]and the middle value 12[ 31]£¬find the left side
19 It is between 6[ 15]and11[ 28]£¬please find the left side
19 It is between 7[ 16]and the middle value 9[ 21]£¬find the left side
19 It is between 7[ 16]and8[ 18]£¬please find the left side
19 It is between 8[ 18]and8[ 18]£¬please find the left side
##### Do not find it[ 19] #####
Please look up the pair of key-value (1-150) while ending with -1: 
 */
