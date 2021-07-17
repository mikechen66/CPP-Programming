
/* C++ Language String Format */

#include<iostream>
#include<string>
using namespace std;

int main(void){
    string str1="C++ Language String Format"; 
    char str2[]={"C Language String Format"};
    string str;
    str=str1+"+"+str2;
    cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str<<endl; 
    return 0;
}


/* Output */

/* 
C++ Language String Format
C Language String Format
C++ Language String Format+C Language String Format
 */