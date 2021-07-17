
/* radix sort */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

void radix (int *, int);                 /* Cardinal sort*/
void showdata (int *, int);
void inputarr (int *, int);

int main(void) { 
    int size,data[100]={0};
    cout<<"Please input the size of array(<100): ";
    cin>>size;
    cout<<"Generate the random data: "<<endl;
    inputarr (data, size);
    showdata (data, size);
    radix (data, size);
    return 0;
}

void inputarr(int data[], int size) {
    srand(time(NULL));
    for (int i=0; i<size; i++)
        data[i]=(rand()%999)+1;          /* Set the data value as 999*/ 
}

void showdata(int data[], int size) {  
    for (int i=0; i<size; i++)
        cout<<setw(5)<<data[i];
    cout<<endl;
}

void radix(int data[], int size) {  
    for (int n=1; n<=100; n=n*10) {      /* n is a cardinal */
        int tmp[10][100]={0};   
        for (int i=0; i<size; i++) {  
            int m=(data[i]/n)%10;        /* %: 36/10 == 3 */  
            tmp[m][i]=data[i];      
        }
        int k = 0;
        for (int i=0; i<10; i++) {  
            for (int j=0; j<size; j++) {  
                if (tmp[i][j] != 0) {  
                    data[k]=tmp[i][j]; 
                    k++;               
                }
            }
        }
        cout<<"After"<<setw(3)<<n<<"sorting: ";
        showdata(data, size);
    } 
}



/* Output */

/*
Please input the size of array(<100): 6
Generate the random data: 
  877   34  700  192  272  961
After  1sorting:   700  961  192  272   34  877
After 10sorting:   700   34  961  272  877  192
After100sorting:    34  192  272  700  877  961
 */