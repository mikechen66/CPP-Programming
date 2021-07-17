#include <iostream>
using namespace std;

int main() {    
    int i,j,sum,max=0,no=1;
    int sale[3][6]={{112,76,95,120,98,68},
                   {90,120,88,112,108,120},
                   {108,99,126,90,76,98}};
   

    for(i=0;i<3;i++) {
        sum=0;
        for(j=0;j<6;j++)
            sum+=sale[i][j];  /* Accumulate the volumes in the first half of the year */ 
        cout<<"In the first half of the year, the No."<<i+1<<" salesman achieved the sales volume: "<<sum<<endl; 
        cout<<"-------------------------------------------------------------------------------"<<endl;  
    }
    
    for(i=0;i<6;i++) {
        sum=0;
        for(j=0;j<3;j++)
            sum+=sale[j][i];  /* Accumulate all the salesmen's sales volume in the current month */  
        cout<<"All the samesmen on the "<<i+1<<"th month achieved the sales volume: "<<sum<<endl;
        cout<<"----------------------------------------------------------------"<<endl;  
    }  
   
   /* system("pause"); */
   return 0;
}



/* Output */
/* Ignore the oddinal month expression such as 1st, 2nd and 3rd. 
/*
In the first half of the year, the No.1 salesman achieved the sales volume: 569
-------------------------------------------------------------------------------
In the first half of the year, the No.2 salesman achieved the sales volume: 638
-------------------------------------------------------------------------------
In the first half of the year, the No.3 salesman achieved the sales volume: 597
-------------------------------------------------------------------------------
All the samesmen on the 1th month achieved the sales volume: 310
----------------------------------------------------------------
All the samesmen on the 2th month achieved the sales volume: 295
----------------------------------------------------------------
All the samesmen on the 3th month achieved the sales volume: 309
----------------------------------------------------------------
All the samesmen on the 4th month achieved the sales volume: 322
----------------------------------------------------------------
All the samesmen on the 5th month achieved the sales volume: 282
----------------------------------------------------------------
All the samesmen on the 6th month achieved the sales volume: 286
----------------------------------------------------------------
 */