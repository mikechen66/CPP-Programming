#include <iostream>

int main() {
    std::cout << "bool = " << sizeof(bool) << std::endl;
    std::cout << "signed char = " << sizeof(signed char) << std::endl;
    std::cout << "unsigned char = " << sizeof(unsigned char) << std::endl;
    std::cout << "signed short = " << sizeof(signed short) << std::endl;
    std::cout << "unsigned short = " << sizeof(unsigned short) << std::endl;
    std::cout << "signed int = " << sizeof(signed int) << std::endl;
    std::cout << "unsigned int = " << sizeof(unsigned int) << std::endl;
    std::cout << "signed long = " << sizeof(signed long) << std::endl;
    std::cout << "unsigned long = " << sizeof(unsigned long) << std::endl;
    std::cout << "signed long long = " << sizeof(signed long long) << std::endl;
    std::cout << "unsigned long long = " << sizeof(signed long long) << std::endl;
    std::cout << "float = " << sizeof(float) << std::endl;
    std::cout << "double = " << sizeof(double) << std::endl;
    std::cout << "long double = " << sizeof(long double) << std::endl;
    std::cout << "wchar_t = " << sizeof(wchar_t) << std::endl;
    std::cout << "char * = " << sizeof(char *) << std::endl;
    std::cout << "int * = " << sizeof(int *) << std::endl;

    enum Enum1 { a };
    enum Enum2 { b, c, d, e };

    std::cout << "Enum1 = " << sizeof(Enum1) << std::endl;
    std::cout << "Enum2 = " << sizeof(Enum2) << std::endl;
}



/* Output */

/* 
$g++ -o main *.cpp
$main
bool = 1
signed char = 1
unsigned char = 1
signed short = 2
unsigned short = 2
signed int = 4
unsigned int = 4
signed long = 8
unsigned long = 8
signed long long = 8
unsigned long long = 8
float = 4
double = 8
long double = 16
wchar_t = 4
char * = 8
int * = 8
Enum1 = 4
Enum2 = 4
 */