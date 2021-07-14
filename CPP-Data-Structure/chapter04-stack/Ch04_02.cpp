
/* A Simple Poker Game */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;
void Swap(int*,int*);
void push(int statck[],int MAX,int val);
int pop(int stack[]);
int top=-1;

int main(void) {  
    int card[52],stack[52]={0};
    int i,j,k=0, ascVal;
    char suit[4][10]={"Club","Diamond","Hearts","Spade"};
    int style;
    srand((unsigned)time(NULL));
    for (i=0; i<52; i++)
        card[i]=i+1;
    cout<<"[Shuffle the cards...Please wait a minute!]"<<endl;
    while (k<30) {
        for (i=0;i<51;i++)
            for (j=i+1;j<52;j++)
                if (rand()%52==2)
                    Swap(&card[i],&card[j]);  //* Shuffle the cards */
        k++;
    }

    i=0;
    while (i!=52) {
        push(stack,52,card[i]); /* Push 52 cards onto the stack */
        i++;
    }
    cout<<"[Deal counter clockwise]"<<endl;
    cout<<"[Show the cards that each one gets]"<<endl;
    cout<<"\t\tEast\t North\t West\t South"<<endl;
    cout<<"========================================================="<<endl;

    while (top >=0) {  
        style = stack[top]/13;  /* Calculate the suits of cards */
        switch (style) {        /* The suits of cards corresponds to realted icons */
            case 0:             /* Club */
                ascVal=0;
                break;
            case 1:             /* Diamond */
                ascVal=1;
                break;
            case 2:             /* Hearts */
                ascVal=2;
                break;
            case 3:             /* Spade */
                ascVal=3;
                break;
        }

        cout<<"["<<suit[ascVal]<<setw(3)<<stack[top]%13+1<<"]\t";

        if (top%4==0)
            cout<<endl;
        top--;
    }
    return 0;
}

void push(int stack[],int MAX,int val) {
    if (top>=MAX-1) {
        cout<<"[The stack js full]"<<endl;
    } else {
        top++;
        stack[top]=val;
    }
}

int pop(int stack[]) {
    if (top<0)
        cout<<"[The stack is empty]"<<endl;
    else
        top--;
    return stack[top];
}

void Swap(int* a, int* b) {
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}



/* Output */

/* 
[Shuffle the cards...Please wait a minute!]
[Deal counter clockwise]
[Show the cards that each one gets]
                East     North   West    South
=========================================================
[Hearts  6]     [Diamond 10]    [Club  4]       [Spade 12]
[Spade  6]      [Spade  9]      [Hearts  7]     [Diamond  9]
[Club 11]       [Spade  2]      [Spade  7]      [Diamond  5]
[Diamond  8]    [Hearts  8]     [Hearts 10]     [Diamond  6]
[Spade  5]      [Club  7]       [Hearts  5]     [Club  6]
[Hearts  4]     [Diamond  4]    [Spade  1]      [Spade  8]
[Hearts  9]     [Hearts  1]     [Club  2]       [Club  8]
[Club  9]       [Club 10]       [Diamond 12]    [Club 12]
[Diamond 13]    [Hearts  3]     [Spade  4]      [Diamond  1]
[Diamond  2]    [Diamond 11]    [Spade  3]      [Diamond  7]
[Hearts 11]     [Club 13]       [Club  5]       [Spade 10]
[Spade 13]      [Hearts  2]     [Spade 11]      [Diamond  3]
[Hearts 12]     [Hearts 13]     [Club  3]       [Club  1]
 */