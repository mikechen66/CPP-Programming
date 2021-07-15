#include <iostream>
#include <iomanip>
using namespace std;

int main(void) {
    int data[6]={6,5,9,7,2,8};  
    cout<<"Bubble Sort£º\nOriginal Data: ";
    for (int i=0; i<6; i++)
        cout<<setw(3)<<data[i];
    cout<<endl;

    for (int i=5; i>0; i--) {
        for (int j=0; j<i; j++) {
            if (data[j]>data[j+1]) {
                int tmp;
                tmp=data[j];
                data[j]=data[j+1];
                data[j+1]=tmp;
            }
        }
        cout<<"The "<<6-i<<"th sorting result: "; 
        for (int j=0; j<6; j++)
            cout<<setw(3)<<data[j];
        cout<<endl;
    }
    cout<<"Sorting Result: ";
    for (int i=0; i<6; i++)
        cout<<setw(3)<<data[i]; 
    cout<<endl;
    return 0;
}


/* Output */

/* 
Bubble Sort£º
Original Data£º  6  5  9  7  2  8
The 1th sorting result:   5  6  7  2  8  9
The 2th sorting result:   5  6  2  7  8  9
The 3th sorting result:   5  2  6  7  8  9
The 4th sorting result:   2  5  6  7  8  9
The 5th sorting result:   2  5  6  7  8  9
Sorting Result:   2  5  6  7  8  9
 *¡¢