#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

namespace overloading {
    template<class C, class T>
    void remove(C& c, typename C::iterator first, typename C::iterator last, const T& value) {
        c.erase(std::remove(first, last, value));
    }
}

int main() {
    using namespace std;

    vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);

    overloading::remove(v, v.begin(), v.end(), 8);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}



/* Output */

/* 
$g++ -o main *.cpp
$main
0 1 2 3 4 5 6 7 9 
 */