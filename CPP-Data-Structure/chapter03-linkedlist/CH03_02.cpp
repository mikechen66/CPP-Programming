#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int no,count=0, Total=0;   
    cout<<"Input numbers for computing:";
    cin>>no; 
    int *ptr=new int[no];       /* Dynamically allocate array with n elements */
    cout<<endl; 
    for (count=0; count < no; count++)   {    
        cout << "input ptr[" << count << "]:";
         cin >> ptr[count];     /* Adopt the subscript for inputting the elements of array */
    }
    for (count=0; count < no; count++) {
         Total+=*(ptr+count);   /* Adopt pointer variable to access to the elements of array */
    }
    cout<<"---------------------------------------"<<endl;
    cout << no<<" elements are summed = " << Total;    /* Show the result */
    cout << endl; 
    delete [] ptr;              /* Release the memory space that is allocated for the ptr */
    ptr=NULL;      
    return 0; 
 }



 /* Output */

 /*
 $g++ -o main *.cpp
$main
Input numbers for computing:
---------------------------------------
0 elements are summed = 0
 */