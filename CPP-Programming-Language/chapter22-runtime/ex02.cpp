#include <valarray>
#include <algorithm>
#include <iterator>
#include <iostream>

namespace runtime {
    using std::valarray;

    template<class T, class Op>
    void apply(valarray<T>& src, Op f) {
        std::transform(&src[0], &src[src.size()], &src[0], f);
    }

    template<class T>
    struct Incr {
        T operator()(const T& x) { return x + 1; }
    };
}

int main() {
    using namespace std;
    using namespace runtime;

    int arr[] = { 0, 1, 2, 3, 4 };
    valarray<int> va(arr, 5);
    apply(va, Incr<int>());
    copy(&va[0], &va[va.size()], ostream_iterator<int>(cout, " "));
    cout << endl;
}



/* Output */

/*
$g++ -o main *.cpp
$main
1 2 3 4 5 
 */