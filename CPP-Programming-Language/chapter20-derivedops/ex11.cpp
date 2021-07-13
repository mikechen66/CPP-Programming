#include <iostream>
#include <cctype>

namespace derivedops {
    int isalpha(unsigned char c) {
        return std::isalpha(c);
    }

    int isalpha(signed char c) {
        return std::isalpha(static_cast<unsigned char>(c));
    }

    int isalpha(char c) {
        return std::isalpha(static_cast<unsigned char>(c));
    }

    int isdigit(unsigned char c) {
        return std::isdigit(c);
    }

    int isdigit(signed char c) {
        return std::isdigit(static_cast<unsigned char>(c));
    }

    int isdigit(char c) {
        return std::isdigit(static_cast<unsigned char>(c));
    }
}

int main() {
    using namespace std;

    signed char c = 255;

    int x = c, y = static_cast<unsigned char>(c);
    cout << x << ' ' << y << endl;
}




/* Output */

/*
$g++ -o main *.cpp
$main
-1 255
 */