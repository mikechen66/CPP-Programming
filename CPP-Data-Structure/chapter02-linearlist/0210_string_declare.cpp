#include <iostream>
#include <cstdlib> 
#include <string>        

using namespace std;

int main() {
    char ch[]=", "; 
    string firstname;    
    string lastname;    
    string input1("Please input your family name: ");
    string input2="Please input your given name: ";
    
    cout<<input1;
    cin>>lastname;     /* input one string */
    cout<<input2;
    cin>>firstname;    /* input another string*/
    
    string fullname=firstname+ch+lastname;  /* Concatenate the string */
    cout<<"Your full name is: "<<fullname<<endl;
    
    return 0;   
 }

 /* Output */

 /*

Please input your family name: Stroustrup
Please input your given name: Bjarne
Your full name is: Bjarne, Stroustrup
 */