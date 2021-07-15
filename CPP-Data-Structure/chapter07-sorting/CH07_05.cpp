
/* Shell sorting */

#include <iostream>
#include <iomanip>
#define SIZE 8      
using namespace std;

void shell (int *,int);     
void showdata (int *);  
void inputarr (int *,int);  

int main(void) { 
    int data[SIZE];
    inputarr(data,SIZE);
    cout<<"Input the original array: ";
    showdata(data);
    shell(data,SIZE);
    return 0;
}

void inputarr(int data[],int size) {
    for (int i=0;i<size;i++) { 
        cout<<"Please input the "<<i+1<<"th element: ";
        cin>>data[i];
    }
}

void showdata(int data[]) {   
    for (int i=0; i<SIZE; i++)
        cout<<setw(3)<<data[i];
    cout<<endl;
}

void shell(int data[],int size) {  
    int i;        
    int j;        
    int k=1;      
    int tmp;      
    int jmp;      
    jmp=size/2;

    while (jmp != 0) {  
        for (i=jmp; i<size; i++) {  
            tmp=data[i];
            j=i-jmp;
            while (tmp<data[j] && j>=0) {  
                data[j+jmp] = data[j];
                j=j-jmp;
            }   
            data[jmp+j]=tmp;
        }
        cout<<"The "<<k++<<"th sorting: ";
        showdata (data);
        jmp=jmp/2;    
    }
}



/* Output */

/* 
Please input the 1th element: 2
Please input the 2th element: 3
Please input the 3th element: 4
Please input the 4th element: 5
Please input the 5th element: 6
Please input the 6th element: 7
Please input the 7th element: 8
Please input the 8th element: 9
Input the original array:   2  3  4  5  6  7  8  9
The 1th sorting:   2  3  4  5  6  7  8  9
The 2th sorting:   2  3  4  5  6  7  8  9
The 3th sorting:   2  3  4  5  6  7  8  9
 */