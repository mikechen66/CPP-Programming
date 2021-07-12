#include <iostream>
using namespace std;

void print_char_vals (char start, char end) {
    for(char ch = start; ch <= end; ch++) {
        cout << ch << " = " << (int)ch << hex << " 0x" << (int)ch << dec << endl;
    }
}

int main() {
    print_char_vals('a', 'z');
    print_char_vals('0', '9');
}



/* Output */

/* 
$g++ -o main *.cpp
$main
a = 97 0x61
b = 98 0x62
c = 99 0x63
d = 100 0x64
e = 101 0x65
f = 102 0x66
g = 103 0x67
h = 104 0x68
i = 105 0x69
j = 106 0x6a
k = 107 0x6b
l = 108 0x6c
m = 109 0x6d
n = 110 0x6e
o = 111 0x6f
p = 112 0x70
q = 113 0x71
r = 114 0x72
s = 115 0x73
t = 116 0x74
u = 117 0x75
v = 118 0x76
w = 119 0x77
x = 120 0x78
y = 121 0x79
z = 122 0x7a
0 = 48 0x30
1 = 49 0x31
2 = 50 0x32
3 = 51 0x33
4 = 52 0x34
5 = 53 0x35
6 = 54 0x36
7 = 55 0x37
8 = 56 0x38
9 = 57 0x39
 */ 