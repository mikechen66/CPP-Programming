#include <iostream>
#include <limits>

using namespace std; /* Indicating the namespace */

template <class T> void printMax(const T max, const char *tName) {
    cout << "max " << tName << " = " << max << hex << " 0x" << max << dec << endl;
}

template <> void printMax<char>(const char max, const char *tName) {
    cout << "max " << tName << " = " << (short)max << hex << " 0x" << (short)max << dec << endl;
}

template <class T> void limit(const char* tName) {
    printMax<T>(std::numeric_limits<T>::max(), tName);
};

int main() {
    limit<char>("char");
    limit<short>("short");
    limit<int>("int");
    limit<long>("long");
    limit<float>("float");
    limit<double>("double");
    limit<long double>("long double");
    limit<unsigned>("unsigned");
}



/* Output */

/*
$g++ -o main *.cpp
$main
max char = 127 0x7f
max short = 32767 0x7fff
max int = 2147483647 0x7fffffff
max long = 9223372036854775807 0x7fffffffffffffff
max float = 3.40282e+38 0x3.40282e+38
max double = 1.79769e+308 0x1.79769e+308
max long double = 1.18973e+4932 0x1.18973e+4932
max unsigned = 4294967295 0xffffffff
 */ 