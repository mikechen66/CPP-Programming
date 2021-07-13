#include <iostream>
#include <bitset>
#include <limits>

void print_bits(int n) {
    std::bitset<sizeof(int)*8> b(n);
    std::cout << n << " = " << b << std::endl;
}

int main() {
    using namespace std;

    print_bits(0);
    print_bits(1);
    print_bits(-1);
    print_bits(18);
    print_bits(-18);
    print_bits(numeric_limits<int>::max());
}



/* Output */

/*
$g++ -o main *.cpp
$main
0 = 00000000000000000000000000000000
1 = 00000000000000000000000000000001
-1 = 11111111111111111111111111111111
18 = 00000000000000000000000000010010
-18 = 11111111111111111111111111101110
2147483647 = 01111111111111111111111111111111
 */ 