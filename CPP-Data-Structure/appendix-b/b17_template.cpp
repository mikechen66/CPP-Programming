
/* Declare the template */ 

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

template <class T>     //Declare the template
void Swap(T* a,T* b);  //Change the original data type to the T type
template <class T>     //Declare the template
void push(T stack[],int MAX,int val);
template <class T>     //Declare the template
T pop(T stack[]);
int top=-1;

int main(void) {  
    int card[52],stack[52]={0};
    char suit[4][10]={"club","diamond","heart","spade"};
    int style, ascVal;
    srand(time(NULL));
    for (int i=0; i<52; i++)
        card[i]=i+1;
    cout<<"[Shuffle...Please wait a minute!]"<<endl;
    int k=0; 
    while (k<30) {
        for (int i=0; i<51; i++)
            for (int j=i+1; j<52; j++)
                if (rand()%52==2)
                    Swap(&card[i],&card[j]);  //Shuffle
        k++;
    }
    int m=0;
    while(m!=52) {
        push(stack,52,card[m]);  //Push back the 52 cards to stack
        m++;
    }
    cout<<"[Deal counter clock]"<<endl;
    cout<<"[Whow each one's cards]"<<endl;
    cout<<" East\t North\t West\t South"<<endl;
    cout<<"============================================================"<<endl;
    while (top >=0) {  
        style = stack[top]/13;  //Calculate suites of the cards
        switch (style) {         //cards corresponds to suites
            case 0:             //club
                ascVal=0;
                break;
            case 1:             //diamond
                ascVal=1;
                break;
            case 2:             //heart
                ascVal=2;
                break;
            case 3:             //spade
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

template <class T>
void push(T stack[],int MAX,int val) {
    if (top>=MAX-1) {
        cout<<"[The stack is full]"<<endl;
    }
    else {
        top++;
        stack[top]=val;
    }
}

template <class T>
T pop(T stack[]) {
    if (top<0)
        cout<<"[The stack is empty]"<<endl;
    else
        top--;
    return stack[top];
}

template <class T>
void Swap(T* a,T* b) {
    T temp;
    temp=*a;
    *a=*b;
    *b=temp;
}


/* $g++ -o main *.cpp
$main
[Shuffle...Please wait a minute!]
[Deal counter clock]
[Whow each one's cards]
 East    North   West    South
============================================================
[diamond  7]    [spade  5]  [club  2]   [club 11]   
[heart 12]  [heart  1]  [diamond  5]    [diamond 10]    
[heart  9]  [spade  2]  [spade  7]  [club  6]   
[spade 12]  [heart 10]  [heart 11]  [heart  1]  
[diamond 12]    [club  5]   [club 10]   [club  3]   
[heart  3]  [diamond  8]    [heart  8]  [heart 13]  
[spade  4]  [spade  9]  [spade  6]  [club  8]   
[spade 13]  [club 13]   [club  9]   [diamond  6]    
[heart  7]  [diamond 11]    [spade 10]  [heart  4]  
[spade 11]  [diamond 13]    [diamond  1]    [club  4]   
[diamond  3]    [diamond  4]    [club 12]   [diamond  9]    
[diamond  2]    [spade  1]  [spade  8]  [heart  5]  
[heart  2]  [heart  6]  [spade  3]  [club  7]   
 */