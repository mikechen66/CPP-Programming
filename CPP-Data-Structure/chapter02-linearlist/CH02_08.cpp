#include <iostream>
#include <cstdlib>
#include <cstring>  
#include <cctype>       

using namespace std;

int main() {
    int lower = 0;
    char string[40];
    
    cout<<"Please input the string:"; 
    cin.getline(string,40);            /* Input the string that has 40 characters */
    int len = strlen(string);
    for (int i = 0; i <= len; i++)  
        if (islower(string[i]) != 0)   /* Add one if it is a lower case character */
            lower++;
    cout <<string<<"The lower case letters have " << lower << " "<<endl;
    
    return 0;
}



/* Output */

/*
Please input the string:Pleaseinputthestring
PleaseinputthestringThe lower case letters have 19 
 */