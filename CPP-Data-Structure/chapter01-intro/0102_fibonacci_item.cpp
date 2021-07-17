/*
CH01_02.cpp
Fibonacci recursion 
*/

#include<iostream>
using namespace std;

int fib(int);               // declare the fib function

int main() {
   int i,n;
   printf("Please input which Fibonacci series:");
   scanf("%d",&n); 
   for (i=0; i<=n; i++)     // compute the Fibonacci series 
      printf("fib(%d)=%d\n", i, fib(i));

   system("pause");
   return 0;
}

int fib(int n) {            // define the fib() function 
   if (n==0)
      return 0;         
   else if (n==1 || n==2)  
      return 1;
   else              
      return (fib(n-1)+fib(n-2));
}


/* Output */

/*
Please input which Fibonacci series:20
fib(0)=0
fib(1)=1
fib(2)=1
fib(3)=2
fib(4)=3
fib(5)=5
fib(6)=8
fib(7)=13
fib(8)=21
fib(9)=34
fib(10)=55
fib(11)=89
fib(12)=144
fib(13)=233
fib(14)=377
fib(15)=610
fib(16)=987
fib(17)=1597
fib(18)=2584
fib(19)=4181
fib(20)=6765
sh: 1: pause: not found
 */