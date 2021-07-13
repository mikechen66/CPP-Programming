#include <iostream>
#include <string>

using namespace std;

void f(char c) {
    cout << "f called with " << (int)c << endl;
}

void g(char& c) {
    cout << "g called with " << (int)c << endl;
}

void h(const char& c) {
    cout << "h called with " << (int)c << endl;
}

int main() {
    char c = 'a';
    unsigned char uc = 'b';
    signed char sc = 'c';

    f('a');
    f(49);
    f(3300); // overflow warning, but legal
    f(c);
    f(uc);
    f(sc);

    //  g('a'); // Illegal, can't pass constant to non-const reference
    //  g(49); // Illegal, can't pass constant to non-const reference
    //  g(3300); // Illegal, can't pass constant to non-const reference
    g(c);
    //  g(uc); // Illegal, type must match reference
    //  g(sc); // Illegal, type must match reference

    h('a'); // temp variable created
    h(49); // temp variable created
    h(3300); // temp variable created, overflow warning
    h(c);
    h(uc); // temp var created only if char is signed
    h(sc); // temp var created only if char is unsigned
}



/* Output */

/*
$g++ -o main *.cpp
main.cpp: In function ‘int main()’:
main.cpp:25:11: warning: overflow in implicit constant conversion [-Woverflow]
     f(3300); // overflow warning, but legal
           ^
main.cpp:39:11: warning: overflow in implicit constant conversion [-Woverflow]
     h(3300); // temp variable created, overflow warning
           ^
$main
f called with 97
f called with 49
f called with -28
f called with 97
f called with 98
f called with 99
g called with 97
h called with 97
h called with 49
h called with -28
h called with 97
h called with 98
h called with 99
 */