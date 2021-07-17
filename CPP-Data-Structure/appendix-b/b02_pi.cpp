
/* State the global constant */

#include<iostream>
using namespace std;
const double PI=3.14159; //Describe the global constant PI
int main(void){
    cout<<"Please inpout the radium of the circle(centimeters): ";
    int r;
    cin>>r;
    cout<<"radius = "<<r<<" the circle's area is: "<<r*r*PI<<" square centimeters"<<endl; 
    return 0;
}

/* Output */

/*
Please inpout the radium of the circle(centimeters): 20
radius = 20 the circle's area is: 1256.64 square centimeters
 */
