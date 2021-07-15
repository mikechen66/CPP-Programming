
/* Inserted Sorting Algorithm */

#include <iostream>
#include <iomanip>
#define SIZE 6  
using namespace std;

void inser (int *);     
void showdata (int *);  
void inputarr (int *,int);  

int  main(void) { 
    int data[SIZE];
    inputarr(data,SIZE);    
    cout<<"Input the original array: ";
    showdata (data);
    inser(data);
    return 0;
}
void inputarr(int data[],int size) {
    for (int i=0; i<size; i++) { 
        cout<<"Please input the "<<i+1<<"th element: ";
        cin>>data[i];
    }
}

void showdata(int data[]) {  
    for (int i=0; i<SIZE; i++)
        cout<<setw(3)<<data[i]; 
    cout<<endl;
}

void inser(int data[]) {  
    int i;     
    int j;     
    for (i=1; i<SIZE; i++) {  
        int tmp;   
        tmp=data[i];
        j=i-1;
        while (j>=0 && tmp<data[j]) {                            
            data[j+1]=data[j];        
            j--;
        }
        data[j+1]=tmp;              
        cout<<"The "<<i<<"th scanning: ";
        showdata(data);
    }
}


/* Output */

/*
Please input the 1th element: 34
Please input the 2th element: 35
Please input the 3th element: 36
Please input the 4th element: 37
Please input the 5th element: 38
Please input the 6th element: 39
Input the original array:  34 35 36 37 38 39
The 1th scanning:  34 35 36 37 38 39
The 2th scanning:  34 35 36 37 38 39
The 3th scanning:  34 35 36 37 38 39
The 4th scanning:  34 35 36 37 38 39
The 5th scanning:  34 35 36 37 38 39
 */