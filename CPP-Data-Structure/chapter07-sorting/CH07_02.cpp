#include <iostream>
#include <iomanip>
using namespace std;

void bubble (int *);   
void showdata (int *); 

int main(void) {
    int data[6]={4,6,2,7,8,9};    
    cout<<"Improve the bubble sorting\nOriginal data: \t";
    showdata(data);
    bubble(data);
    return 0;
}

void showdata (int data[]) {
    for (int i=0; i<6; i++)
        cout<<setw(3)<<data[i];
    cout<<endl;
}

void bubble (int data[]) {
    for (int i=5; i>=0; i--) {
        int flag=0;           
        for (int j=0; j<i; j++) {
            if (data[j+1]<data[j]) {
                int tmp;
                tmp=data[j];
                data[j]=data[j+1];
                data[j+1]=tmp;
                flag++;    
            }
        }
        if (flag==0)
            break;

        cout<<"The "<<6-i<<"th sorting: \t";
        for (int j=0;j<6;j++)
            cout<<setw(3)<<data[j];
        cout<<endl;         
    }
    cout<<"Sorting Result: \t";
    showdata (data);
}


/* Output */

/*
Improve the bubble sorting
Original data:    4  6  2  7  8  9
The 1th sorting:          4  2  6  7  8  9
The 2th sorting:          2  4  6  7  8  9
Sorting Result:           2  4  6  7  8  9
 */
