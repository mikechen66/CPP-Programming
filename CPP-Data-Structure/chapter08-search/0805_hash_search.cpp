#include <iostream>
#include <iomanip>
#include <ctime>
#include<cstdlib>

using namespace std;
const int INDEXBOX = 10;   
const int MAXNUM = 7;    

int print_data(int *,int);
int creat_table(int ,int *);

int main(void) {  
    int i, index[INDEXBOX], data[MAXNUM];
    srand(time(NULL));     
    cout<<"Original Array: \n";

    for (i=0; i<MAXNUM; i++)      
        data[i]=rand()%20+1;

    for (i=0; i<INDEXBOX; i++)     
        index[i]=-1;

    print_data(data,MAXNUM);    
    cout<<"Hash table content: "<<endl;

    for (i=0; i<MAXNUM; i++) {  
        creat_table(data[i],index);
        cout<<data[i]<<" =>";  
        print_data(index,INDEXBOX);
    }

    cout<<"Complete the hash table: "<<endl;     
    print_data(index,INDEXBOX); 
    return 0;
}

int print_data(int *data,int max) {  
    cout<<"\t";
    for (int i=0; i<max; i++)
        cout<<"["<<setw(2)<<data[i]<<"] ";
    cout<<endl;
}
int creat_table(int num,int *index) {  
    int tmp;
    tmp=num%INDEXBOX;    
    while (1) {  
        if (index[tmp]==-1) {  
            index[tmp]=num;     
            break;
        } else
            tmp=(tmp+1)%INDEXBOX;    
    }
}


/* Output */

/*
Original Array: 
        [ 8] [15] [ 2] [ 5] [13] [12] [ 9] 
Hash table content: 
8 =>    [-1] [-1] [-1] [-1] [-1] [-1] [-1] [-1] [ 8] [-1] 
15 =>   [-1] [-1] [-1] [-1] [-1] [15] [-1] [-1] [ 8] [-1] 
2 =>    [-1] [-1] [ 2] [-1] [-1] [15] [-1] [-1] [ 8] [-1] 
5 =>    [-1] [-1] [ 2] [-1] [-1] [15] [ 5] [-1] [ 8] [-1] 
13 =>   [-1] [-1] [ 2] [13] [-1] [15] [ 5] [-1] [ 8] [-1] 
12 =>   [-1] [-1] [ 2] [13] [12] [15] [ 5] [-1] [ 8] [-1] 
9 =>    [-1] [-1] [ 2] [13] [12] [15] [ 5] [-1] [ 8] [ 9] 
Complete the hash table: 
        [-1] [-1] [ 2] [13] [12] [15] [ 5] [-1] [ 8] [ 9] 
 */
