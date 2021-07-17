
/* Execute the goto instruction */

#include<iostream>
using namespace std;

int main(void){ 
    for (int i=1;i<10; i++){
        for (int j=1; j<10; j++){
            cout<<j<<"*"<<i<<"="<<i*j<<"\t";
            if (i==5)
                goto down; //goto to down
        }cout<<endl;
    } 
    down: 
    cout<<"Ending"<<endl;
    return 0;
}


/* Output */

/*
1*1=1   2*1=2   3*1=3   4*1=4   5*1=5   6*1=6   7*1=7   8*1=8   9*1=9
1*2=2   2*2=4   3*2=6   4*2=8   5*2=10  6*2=12  7*2=14  8*2=16  9*2=18
1*3=3   2*3=6   3*3=9   4*3=12  5*3=15  6*3=18  7*3=21  8*3=24  9*3=27
1*4=4   2*4=8   3*4=12  4*4=16  5*4=20  6*4=24  7*4=28  8*4=32  9*4=36
1*5=5   Ending
 */