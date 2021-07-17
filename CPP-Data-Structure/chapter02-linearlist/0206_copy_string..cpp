#include<iostream>
#include<cstdlib>

using namespace std;

int main() {
    int i;               /* It is used to compute the length of string*/
    char str[30];
    char str1[30];
    cout<<"Please input the string:";
    cin>>str;
    cout<<"The string is:"<<str<<endl;
    
    for(i=0; str[i]!='\0'; i++) {
        str1[i]=str[i];  /* Copy the string one by one */
    }
    str1[i]='\0';        /* Exclude the ending letter */  
    cout<<"The string has "<<i<<"characters"<<endl;
    cout<<"The original str="<<str<<endl;
    cout<<"The copied str1="<<str1<<endl;
    
    return 0;
}



/* Output */

/*
Please input the string:Stroustrup
The string is:Stroustrup
The string has 10characters
The original str=Stroustrup
The copied str1=Stroustrup
 */