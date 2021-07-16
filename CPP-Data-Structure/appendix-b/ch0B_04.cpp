
/* Judge an even or odd number with using condition operation*/

#include<iostream>
using namespace std;

int main() {
    int num;
    cout<<"Please input an integer:";
    cin>>num;
    //Condition operator 
    num%2==0 ? cout<<num<<" is an even number"<<endl:cout<<num<<" is an odd number"<<endl;
    return 0;
}


/* Output */

/* 
Please input an integer:13
13 is an odd number
 */
