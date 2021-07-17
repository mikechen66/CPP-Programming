#include <iostream>
#include <cstdlib>

using namespace std;

int main(){  
    char arr2[50];   
    int i,sum;   
    cout << "Please input a string: ";   
    cin >> arr2;              /* Get the string inputted by a user */    
    for (i=0; i<50; i++) {     
        if (arr2[i]=='\0') {   
            break;            /* Interupt the loop if the last character of  a string input by a user */   
        }       
        sum=i;                /* Record the subscript of the character prior to the empty string */    
    }
   
    for (i=sum; i>=0; i--) {     
        cout << arr2[i];      /* Output the inverted string */
    }   
    cout << endl;   
        
    return 0;
}


/* Output */

/* 
Please input a string: Steve
evetS
 */