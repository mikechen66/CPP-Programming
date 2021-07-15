
/* Quick sorting */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

void inputarr(int*,int);
void showdata(int*,int);
void quick(int*,int,int,int);
int process = 0;

int main(void) {
    int size, data[100]={0};
    srand(time(NULL));
    cout<<"Please input the array (size<100): ";
    cin>>size;
    cout<<"Randomly generate the original data: ";
    inputarr (data,size);
    showdata (data,size);
    quick(data,size,0,size-1);
    cout<<"\nSorting Result: ";
    showdata(data,size);
    return 0;
}

void inputarr(int data[],int size) {
    for (int i=0;i<size;i++)
        data[i]=(rand()%99)+1;
}

void showdata(int data[],int size) {  
    int i;
    for (i=0; i<size; i++)
        cout<<setw(3)<<data[i];
    cout<<endl;
}

void quick(int d[], int size,int lf, int rg) {
    int tmp;
    int lf_idx;
    int rg_idx;
    int t;
    if (lf<rg) {
        lf_idx=lf+1;
        rg_idx=rg;
        while (1) {
            cout<<"[Processing"<<process++<<"]=> ";
            for (int t=0; t<size; t++)
                cout<<"["<<setw(2)<<d[t]<<"] ";

            cout<<endl;

            for (int i=lf+1; i<=rg; i++) {
                if (d[i]>=d[lf]) {
                    lf_idx=i;
                    break;
                }
                lf_idx++;
            }

            for (int j=rg; j>=lf+1; j--) {
                if (d[j]<=d[lf]) {
                    rg_idx=j;
                    break;
                }
                rg_idx--;
            }

            if (lf_idx<rg_idx) {                        
                tmp = d[lf_idx];       
                d[lf_idx] = d[rg_idx];
                d[rg_idx] = tmp;      
            } else {
                break;    
            } 
        }
        if (lf_idx>=rg_idx) {                    
            tmp = d[lf];
            d[lf] = d[rg_idx];
            d[rg_idx] = tmp;
            quick(d,size,lf,rg_idx-1);  
            quick(d,size,rg_idx+1,rg);  
        }
    }
}



/* Output */

/*
Please input the array (size<100): 6
Randomly generate the original data:  22 68 20 33 28  3
[Processing0]=> [22] [68] [20] [33] [28] [ 3] 
[Processing1]=> [22] [ 3] [20] [33] [28] [68] 
[Processing2]=> [20] [ 3] [22] [33] [28] [68] 
[Processing3]=> [ 3] [20] [22] [33] [28] [68] 

Sorting Result:   3 20 22 28 33 68
 */