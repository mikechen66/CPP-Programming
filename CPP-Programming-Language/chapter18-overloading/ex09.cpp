#include <algorithm>
#include <vector>
#include <iostream>
#include <bitset>

namespace overloading {
    using namespace std;

    template<class T>
    class Op_and : binary_function<T,T,T> {
    public:
        T operator()(const T& x, const T& y) const { return x & y; }
    };

    template<class T>
    class Op_or : binary_function<T,T,T> {
    public:
        T operator()(const T& x, const T& y) const { return x | y; }
    };

    template<class T>
    class Op_xor : binary_function<T,T,T> {
    public:
        T operator()(const T& x, const T& y) const { return x ^ y; }
    };

    template<class T>
    class Op_not : unary_function<T,T> {
    public:
        T operator()(const T& x) const { return ~x; }
    };

    template<class T>
    void print_result(char op, const T& first, const T& second, const T& third) {
        cout << first << ' ' << op << ' ' << second << " = " << third << endl;
    }

    void print_result(char op, const char first, const char second, const char third) {
        cout << (int)first << ' ' << op << ' ' << (int)second << " = " << (int)third << endl;
    }

    template<class T>
    void print_result(char op, const T& first, const T& second) {
        cout << op << first << " = " << second << endl;
    }

    void print_result(char op, const char first, const char second) {
        cout << op << (int)first << " = " << (int)second << endl;
    }

    template<class T>
    void do_tests() {
        vector<T> v1;
        vector<T> v2;
        v1.push_back(1);
        v2.push_back(3);
        vector<T> v3;

        transform(v1.begin(), v1.end(), v2.begin(), back_inserter(v3), Op_and<T>());
        print_result('&', v1[0], v2[0], v3[0]);
        v3.clear();
        transform(v1.begin(), v1.end(), v2.begin(), back_inserter(v3), Op_or<T>());
        print_result('|', v1[0], v2[0], v3[0]);
        v3.clear();
        transform(v1.begin(), v1.end(), v2.begin(), back_inserter(v3), Op_xor<T>());
        print_result('^', v1[0], v2[0], v3[0]);
        v3.clear();
        transform(v1.begin(), v1.end(), back_inserter(v3), Op_not<T>());
        print_result('~', v1[0], v3[0]);
        v3.clear();
    }
}

int main() {
    using namespace overloading;
    using namespace std;

    cout << "char: " << endl;
    do_tests<char>();
    cout << "int: " << endl;
    do_tests<int>();
    cout << "bitset<67>: " << endl;
    do_tests<bitset<67> >();
}



/* Output */

/*
$g++ -o main *.cpp
$main
char: 
1 & 3 = 1
1 | 3 = 3
1 ^ 3 = 2
~1 = -2
int: 
1 & 3 = 1
1 | 3 = 3
1 ^ 3 = 2
~1 = -2
bitset<67>: 
0000000000000000000000000000000000000000000000000000000000000000001 & 0000000000000000000000000000000000000000000000000000000000000000011 = 0000000000000000000000000000000000000000000000000000000000000000001
0000000000000000000000000000000000000000000000000000000000000000001 | 0000000000000000000000000000000000000000000000000000000000000000011 = 0000000000000000000000000000000000000000000000000000000000000000011
0000000000000000000000000000000000000000000000000000000000000000001 ^ 0000000000000000000000000000000000000000000000000000000000000000011 = 0000000000000000000000000000000000000000000000000000000000000000010
~0000000000000000000000000000000000000000000000000000000000000000001 = 1111111111111111111111111111111111111111111111111111111111111111110
 */