/*
CH01_03.cpp
Hanoi function for dish moving procedure
*/

#include <iostream>
using namespace std;

void hanoi(int, int, int, int); 
int main(void) {  
    int j;
    cout<<"Please input the number of dishes: ";
    cin>>j;
    hanoi(j,1, 2, 3);
    /* system("pause"); */   
    return 0;
}

void hanoi(int n, int p1, int p2, int p3) {  
    if (n==1)
        cout<<"Dish is moved from "<<p1<<" to "<<p3<<endl;
    else {  
        hanoi(n-1, p1, p3, p2);
        cout<<"Dish is moved from "<<p1<<" to "<<p3<<endl;
        hanoi(n-1, p2, p1, p3);
    }
}


/* Output */

/*
Please input the number of dishes: 6
Dish is moved from 1 to 2
Dish is moved from 1 to 3
Dish is moved from 2 to 3
Dish is moved from 1 to 2
Dish is moved from 3 to 1
Dish is moved from 3 to 2
Dish is moved from 1 to 2
Dish is moved from 1 to 3
Dish is moved from 2 to 3
Dish is moved from 2 to 1
Dish is moved from 3 to 1
Dish is moved from 2 to 3
Dish is moved from 1 to 2
Dish is moved from 1 to 3
Dish is moved from 2 to 3
Dish is moved from 1 to 2
Dish is moved from 3 to 1
Dish is moved from 3 to 2
Dish is moved from 1 to 2
Dish is moved from 3 to 1
Dish is moved from 2 to 3
Dish is moved from 2 to 1
Dish is moved from 3 to 1
Dish is moved from 3 to 2
Dish is moved from 1 to 2
Dish is moved from 1 to 3
Dish is moved from 2 to 3
Dish is moved from 1 to 2
Dish is moved from 3 to 1
Dish is moved from 3 to 2
Dish is moved from 1 to 2
Dish is moved from 1 to 3
Dish is moved from 2 to 3
Dish is moved from 2 to 1
Dish is moved from 3 to 1
Dish is moved from 2 to 3
Dish is moved from 1 to 2
Dish is moved from 1 to 3
Dish is moved from 2 to 3
Dish is moved from 2 to 1
Dish is moved from 3 to 1
Dish is moved from 3 to 2
Dish is moved from 1 to 2
Dish is moved from 3 to 1
Dish is moved from 2 to 3
Dish is moved from 2 to 1
Dish is moved from 3 to 1
Dish is moved from 2 to 3
Dish is moved from 1 to 2
Dish is moved from 1 to 3
Dish is moved from 2 to 3
Dish is moved from 1 to 2
Dish is moved from 3 to 1
Dish is moved from 3 to 2
Dish is moved from 1 to 2
Dish is moved from 1 to 3
Dish is moved from 2 to 3
Dish is moved from 2 to 1
Dish is moved from 3 to 1
Dish is moved from 2 to 3
Dish is moved from 1 to 2
Dish is moved from 1 to 3
Dish is moved from 2 to 3
 */