#include <iostream>

// This was a 2.5 point exercise, but it was really easy; did I miss something in the question?
namespace classlevels {
    std::ios_base& general(std::ios_base& s) {
        s.unsetf(std::ios_base::floatfield);
    }
}

int main() {
    using namespace std;
    using namespace classlevels;

    cout << 12.345 << ' ' << scientific << 12.345 << ' ' << fixed << 12.345 << ' ' << general << 12.345 << endl;
}


/* Output */

/*
$g++ -o main *.cpp
$main
12.345 1.234500e+01 12.345000 12.345
 */