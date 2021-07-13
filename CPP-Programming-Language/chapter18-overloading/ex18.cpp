#include <iostream>
#include <algorithm>
#include <iterator>

namespace overloading {
    using std::less;
    using std::ostream_iterator;
    using std::iterator_traits;
    using std::cout;
    using std::endl;
    using std::swap;

    template<class Ran, class Cmp>
    void sort(Ran first, Ran last, Cmp cmp) {
        const size_t n = last - first;
        for (int gap = n/2; 0 < gap; gap /= 2) {
            for (int i = gap; i < n; i++) {
                for (int j = i-gap; 0 <= j; j -= gap) {
                    if (cmp(*(first + (j+gap)), *(first + j))) {
                        swap(*(first + j), *(first + (j+gap)));
                        copy(first, last, ostream_iterator<typename iterator_traits<Ran>::value_type>(cout, " "));
                        cout << endl;
                    }
                    else
                        break;
                }
            }
        }
    }

    template<class Ran>
    void sort(Ran first, Ran last) {
        overloading::sort(first, last, less<typename iterator_traits<Ran>::value_type>());
    }
}

int main() {
    using namespace overloading;

    int arr[] = { 4, 6, 3, 2, 5, 1 };
    overloading::sort(arr, arr + 6);
}




/* Output */

/*
$g++ -o main *.cpp
$main
2 6 3 4 5 1 
2 5 3 4 6 1 
2 5 1 4 6 3 
2 1 5 4 6 3 
1 2 5 4 6 3 
1 2 4 5 6 3 
1 2 4 5 3 6 
1 2 4 3 5 6 
1 2 3 4 5 6 
 */