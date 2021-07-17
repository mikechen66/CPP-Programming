#include <iostream>
using namespace std;

int main(){
    /* Declare a 3D array */ 
    int num[2][3][3]={{{33,45,67},
                       {23,71,56},
                       {55,38,66}},
                       {{21,9,15 },
                        {38,69,18},
                        {90,101,89}}};       
    int i,j,k,min=num[0][0][0];            
    
    /* Found out the minimum value with the 3 level for loop*/
    for (i=0; i<2; i++)
        for(j=0; j<3; j++)    
            for (k=0; k<3; k++)   
                if (min>=num[i][j][k])
                    min=num[i][j][k];    
    
    cout<<"The minimum value = "<<min<<endl;
                           
    return 0;
}


/* Output *

/*
The minimum value = 9
 */