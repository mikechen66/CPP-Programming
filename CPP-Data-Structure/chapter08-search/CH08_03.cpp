#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;

int bin_search(int*,int);
int main(void) {  
    int i,j,val=1,num,data[50]={0};
    for (i=0;i<50;i++) {  
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
    for (i=0; i<5; i++) { 
        for (j=0; j<10; j++)
            cout<<setw(3)<<i*10+j+1<<"-"<<setw(3)<<data[i*10+j];
        cout<<endl;
    }
    return 0;
}

int bin_search(int data[50],int val) {  
    int low,mid,high;
    low=0;
    high=49;
    cout<<"It is looking up......"<<endl;
    while (low<= high && val !=-1) {  
        mid=low+((val-data[low])*(high-low)/(data[high]-data[low])); 
        if (val==data[mid]) {
            return mid;
        } else if (val < data[mid]) {  
            cout<<val<<" It is between "<<low+1<<"["<<setw(3)<<data[low]<<"]and the middle value  "<<mid+1<<"["<<setw(3)<<data[mid]<<"]£¬please find the left side"<<endl;
            high=mid-1;      
        } else if(val > data[mid]) {  
            cout<<val<<" It is between "<<mid+1<<"["<<setw(3)<<data[mid]<<"]and"<<high+1<<"["<<setw(3)<<data[high]<<"]£¬please find the right side"<<endl;
            low=mid+1;           
        }
    }
    return -1;
}



/* Output */

/*
Please look up the pair of key-value (1-150) while ending with -1: -1
Data content: 
  1-  1  2-  5  3-  7  4- 10  5- 11  6- 15  7- 16  8- 18  9- 21 10- 26
 11- 28 12- 31 13- 34 14- 35 15- 40 16- 44 17- 46 18- 47 19- 49 20- 52
 21- 54 22- 56 23- 60 24- 63 25- 68 26- 71 27- 72 28- 75 29- 79 30- 82
 31- 83 32- 88 33- 91 34- 94 35- 98 36-103 37-106 38-110 39-112 40-114
 41-117 42-122 43-126 44-128 45-133 46-138 47-141 48-145 49-150 50-151
  */
