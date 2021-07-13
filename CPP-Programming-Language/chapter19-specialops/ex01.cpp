#include <iterator>
#include <iostream>
#include <string>

namespace specialops {
    template<class Bi> void reverse(Bi first, Bi last) {
        // two checks necessary to handle even and odd lengths
        while((first != last) && (first != --last)) {
            std::swap(*first++, *last);
        }
    }
}

int main() {
    using namespace specialops;
    using namespace std;

    string s("Hello World!");
    specialops::reverse(s.begin(), s.end());
    cout << s << endl;
    string s1("Hello World");
    specialops::reverse(s1.begin(), s1.end());
    cout << s1 << endl;
}



/* Output */

/*
$g++ -o main *.cpp
$main
!dlroW olleH
dlroW olleH
 */