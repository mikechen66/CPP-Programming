
/* Push and Pop Operation with the Stack */

#include <iostream>
#include <cstdlib>

using namespace std;

template <class Type = int, int size = 5>       

class Stack {
    private:
        Type st[size];        /* Declare a 1D array as storage for the stack */
        int top;              /* Index of the top of the stack */
    public:
        Stack(){
            top = -1;
        }
        void push(Type data); /* Push the data on the stack */
        Type pop();           /* Pop up the data item from the stack */ 
};

template < class Type, int size >

void Stack< Type, size > :: push ( Type data ) {
    st[ ++top ] = data;
}

template < class Type, int size > Type Stack<Type, size> :: pop() {
    return st[ top-- ];
}

int main() {
    Stack<> stk_1;           /* Declare a stack object with using its default */
    Stack<char*, 4> stk_2;   /* Declare a stack object with its type as string and size as 4 */
    stk_1.push( 11 );
    stk_1.push( 22 );
    stk_1.push( 33 );
    cout << "stack_1 [1] = " << stk_1.pop() << endl;
    cout << "stack_1 [2] = " << stk_1.pop() << endl;
    cout << "stack_1 [3] = " << stk_1.pop() << endl;
    cout << endl;
    stk_2.push( "the first" );
    stk_2.push( "the second" );
    stk_2.push( "the third" );
    cout << "stack_2 [1] = " << stk_2.pop() << endl;
    cout << "stack_2 [2] = " << stk_2.pop() << endl;  
    cout << "stack_2 [3] = " << stk_2.pop() << endl;
    cout << endl;
    return 0;  
}


/* Output */

/*
main.cpp:43:29: warning: ISO C++ forbids converting a string constant to ¡®char*¡¯ [-Wwrite-strings]
     stk_2.push( "the first" );
                             ^
main.cpp:44:30: warning: ISO C++ forbids converting a string constant to ¡®char*¡¯ [-Wwrite-strings]
     stk_2.push( "the second" );
                              ^
main.cpp:45:29: warning: ISO C++ forbids converting a string constant to ¡®char*¡¯ [-Wwrite-strings]
     stk_2.push( "the third" );
                             ^
stack_1 [1] = 33
stack_1 [2] = 22
stack_1 [3] = 11

stack_2 [1] = the third
stack_2 [2] = the second
stack_2 [3] = the first
 */