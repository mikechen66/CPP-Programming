

/* Execute a lottery game */

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main(){
    int num[6];  //Declare an array
    cout<<"Great Happiness Lottery Number Picking"<<endl;
    cout<<"Please select the numbers:(1~49)"<<endl;
    for (int i=1; i<=6; i++){  //Assign for the array 
        cout<<"Number["<<i<<"] = ";
        cin>>num[i];
    } 
    cout<<"You select the number: "<<endl;
    for (int i=1; i<=6; i++){  //Output the array     
        cout<<num[i]<<"\t";
    }
    cout<<endl;
    cout<<"The system select the numbers: "<<endl;
    srand(time(NULL));  
    for (int j=1; j<=6; j++){
        num[j]=1+rand()%49;
        cout<<num[j]<<"\t";
    }cout<<endl;
    cout<<"Wish you win the lottery"<<endl;
    return 0;
}


/* Output */

/*
Great Happiness Lottery Number Picking
Please select the numbers:(1~49)
Number[1] = 24
Number[2] = 25
Number[3] = 32
Number[4] = 12
Number[5] = 16
Number[6] = 11
You select the number: 
24      25      32      12      16      11
The system select the numbers: 
37      38      31      41      40      7
Wish you win the lottery
 */