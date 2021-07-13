#include <iostream>
using namespace std;

int main() {
    int arr[2][2];
    int sum;
    cout<<"|a1 b1|"<<endl;
    cout<<"|a2 b2|"<<endl;
    cout<<"Please input a1:";
    cin>>arr[0][0];
    cout<<"Please input b1:";
    cin>>arr[0][1];
    cout<<"Please input a2:";
    cin>>arr[1][0];
    cout<<"Please input b2:";
    cin>>arr[1][1];
     /* Find the value of the 2nd order determinant */
    sum = arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0]; 
    cout<<"|"<<arr[0][0]<<" "<<arr[0][1]<<"|"<<endl;
    cout<<"|"<<arr[1][0]<<" "<<arr[1][1]<<"|"<<endl;

    cout<<"sum="<<sum<<endl;

    return 0;
}


/* Output */

/*
|a1 b1|
|a2 b2|
Please input a1:3
Please input b1:4
Please input a2:5
Please input b2:6
|3 4|
|5 6|
sum=-2
 */