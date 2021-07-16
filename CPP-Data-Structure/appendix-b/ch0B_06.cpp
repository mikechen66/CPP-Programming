
/* do-while loop */

#include<iostream>
using namespace std;

int main(){
    cout<<"\tExecuute a do-while loop\t"<<endl;
    cout<<"================================================="<<endl;
    int number, sum2=0;
    do {
        sum2=0;
        cout<<"Please input numbers while 0 as ending: ";
        cin>>number;
        if (number==0){
            cout<<"End of the program"<<endl;
            break;
        }
        for (int k=1; k<=number; k++){
            cout<<k;
            if (k<number)cout<<"+";
            sum2+=k;
        }
        cout<<"\n1~"<<number<<" accumulated number="<<sum2<<endl;
    } while (number!=0);/* end the do-while loop */
    return 0;
}



/* Output */

/*
        Execuute a do-while loop
=================================================
Please input numbers while 0 as ending: 21
1+2+3+4+5+6+7+8+9+10+11+12+13+14+15+16+17+18+19+20+21
1~21 accumulated number=231
Please input numbers while 0 as ending: 0
End of the program
 */