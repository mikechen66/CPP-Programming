
/* Heap Sorting */

#include <iostream>
#include <iomanip>
using namespace std;

void heap(int*, int);
void ad_heap(int*, int, int);

int main(void) {  
    int data[9]={0,5,6,4,8,3,2,7,1};    
    int size=9;

    cout<<"Original Array: ";
    for(int i=1; i<size; i++)
        cout<<"["<<setw(2)<<data[i]<<"] ";
    heap(data, size);                         /* Create the heap tree */                      
    cout<<"\nSorting Result: ";
    for(int i=1;i<size;i++)
        cout<<"["<<setw(2)<<data[i]<<"] ";
    cout<<endl;
    return 0;
}

void heap(int *data, int size) {  
    int i, j, tmp;
    for (i=(size/2); i>0; i--)                /* Build nodes of the heap tree */           
        ad_heap(data,i,size-1);

    cout<<"\nHeap content: ";

    for (i=1; i<size; i++)                 
        cout<<"["<<setw(2)<<data[i]<<"] ";

    cout<<endl;

    for (i=size-2; i>0; i--) {  
        tmp = data[i+1];                      /* Swap the head and the tail*/                 
        data[i+1] = data[1];
        data[1] = tmp;
        ad_heap(data,1,i);             
        cout<<"\nProcessing: ";
        for (j=1; j<size; j++)
            cout<<"["<<setw(2)<<data[j]<<"] ";
    }
}

void ad_heap(int *data, int i, int size) {  
    int j, tmp, post;
    j = 2*i;
    tmp = data[i];
    post = 0;
    while (j<=size && post==0) {  
        if (j<size) {
            if (data[j]<data[j+1])      
                j++;
        }
        if (tmp>=data[j]) {                   /* End the comparing if the root node is bigger */    
            post = 1;
        } else {  
            data[j/2] = data[j];      
            j = 2*j;
        }   
   }
   data[j/2] = tmp;                   
}


/* Output */

/*
Original Array: [ 5] [ 6] [ 4] [ 8] [ 3] [ 2] [ 7] [ 1] 
Heap content: [ 8] [ 6] [ 7] [ 5] [ 3] [ 2] [ 4] [ 1] 

Processing: [ 7] [ 6] [ 4] [ 5] [ 3] [ 2] [ 1] [ 8] 
Processing: [ 6] [ 5] [ 4] [ 1] [ 3] [ 2] [ 7] [ 8] 
Processing: [ 5] [ 3] [ 4] [ 1] [ 2] [ 6] [ 7] [ 8] 
Processing: [ 4] [ 3] [ 2] [ 1] [ 5] [ 6] [ 7] [ 8] 
Processing: [ 3] [ 1] [ 2] [ 4] [ 5] [ 6] [ 7] [ 8] 
Processing: [ 2] [ 1] [ 3] [ 4] [ 5] [ 6] [ 7] [ 8] 
Processing: [ 1] [ 2] [ 3] [ 4] [ 5] [ 6] [ 7] [ 8] 
Sorting Result: [ 1] [ 2] [ 3] [ 4] [ 5] [ 6] [ 7] [ 8] 
 */