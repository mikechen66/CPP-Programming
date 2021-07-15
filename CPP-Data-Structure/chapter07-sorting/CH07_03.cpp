#include <iostream>
#include <iomanip>
using namespace std;

void select (int *); 
void showdata (int *);
int main(void) {
    int data[6]={9,7,5,3,4,6};
    cout<<"Original data: ";
    showdata(data);
    select(data);
    return 0;
}

void showdata (int data[]) {
    for (int i=0; i<6; i++)
        cout<<setw(3)<<data[i];
    cout<<endl;
}

void select (int data[]) {
    for (int i=0;i<5;i++) {   
        for (int j=i+1; j<6; j++) {   
            if (data[i]>data[j]) {   
                int tmp;
                tmp=data[i];
                data[i]=data[j];
                data[j]=tmp;    
            }
        }
        cout<<"The "<<i+1<<"th sorting result£º";
        for (int k=0;k<6;k++)
            cout<<setw(3)<<data[k];   
        cout<<endl;
    }
    cout<<endl;
}


/* Output (/

/* 
Original data:   9  7  5  3  4  6
The 1th sorting result£º  3  9  7  5  4  6
The 2th sorting result£º  3  4  9  7  5  6
The 3th sorting result£º  3  4  5  9  7  6
The 4th sorting result£º  3  4  5  6  9  7
The 5th sorting result£º  3  4  5  6  7  9
 */
