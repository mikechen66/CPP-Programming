
/* Dynamically allocate memory */

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main(void){
    int num;
    srand(time(NULL));
    cout<<"Please input the sized of array: ";   
    cin>>num;
    int *a=new int[num];        //Declare the ptr variable for dynamic memory
    for(int i=0; i<num; i++) {  //Use random numbers to initilizie values
        a[i]=rand()%101;
    }
    for(int i=0; i<num; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    delete []a;                 //Release the memory that the ptr points to
    return 0;
}