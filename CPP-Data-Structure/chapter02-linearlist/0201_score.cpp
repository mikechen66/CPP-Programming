#include <iostream>
using namespace std;

int main() {
    /* Define the interger array of Score[5] while setting five scores */
    int Score[5]={ 87,66,90,65,70 };    
    int count, Total_Score=0;
    for (count=0; count < 5; count++) {   
        cout<<"The score of the "<<count+1<<"th student:"<<Score[count]<<endl;  
        Total_Score+=Score[count];       
    }
      cout<<"-------------------------"<<endl;
      cout<<"the total scores of five students:"<<Total_Score<<endl;  
     
     system("pause");
     return 0;
}


/* Output */

/* 
The score of the 3th student:90
The score of the 4th student:65
The score of the 5th student:70
-------------------------
the total scores of five students:378
sh: 1: pause: not found
 */