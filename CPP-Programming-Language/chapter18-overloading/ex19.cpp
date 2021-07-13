#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <time.h>

// Build with:
// g++ -o ex19 ex19.cpp -lrt
namespace overloading {
    template<class Bi, class Cmp>
    void sort(Bi first, Bi last, Cmp cmp, size_t count) {
        if (count < 2)
            return;
        Bi i = first;
        int mid = count / 2;
        for (int j = 0; j < mid; j++)
            i++;
        overloading::sort(first, i, cmp, mid);
        overloading::sort(i, last, cmp, count - mid);
        std::inplace_merge(first, i, last, cmp);
    }

    template<class Bi, class Cmp>
    void sort(Bi first, Bi last, Cmp cmp) {
        Bi i = first;
        int count = 1;
        while (i++ != last)
            count++;
        overloading::sort(first, last, cmp, count);
    }

    template<class Bi>
    void sort(Bi first, Bi last) {
        overloading::sort(first, last, std::less<typename std::iterator_traits<Bi>::value_type>());
    }

    unsigned long diff(timespec start, timespec end) {
        timespec tmp;
        if ((end.tv_nsec-start.tv_nsec)<0) {
            tmp.tv_sec = end.tv_sec-start.tv_sec-1;
            tmp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
        } else {
            tmp.tv_sec = end.tv_sec-start.tv_sec;
            tmp.tv_nsec = end.tv_nsec-start.tv_nsec;
        }
        return tmp.tv_sec * 1000000000 + tmp.tv_nsec;
    }
}

int main() {
    using namespace overloading;
    using namespace std;

    list<int> l;
    srand(time(0));
    for (int i = 0; i < 1000; i++) {
        int r = rand();
        l.push_back(r);
    }

    timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);    
    overloading::sort(l.begin(), l.end());
    clock_gettime(CLOCK_REALTIME, &end);
    cout << "Bidirectional merge sort: " << diff(start, end) << endl;

    clock_gettime(CLOCK_REALTIME, &start);
    vector<int> v;
    copy(l.begin(), l.end(), back_inserter(v));
    std::sort(v.begin(), v.end());
    clock_gettime(CLOCK_REALTIME, &end);
    cout << "Copy then random-access sort: " << diff(start, end) << endl;
}



/* Output */

/*
$g++ -o main *.cpp
$main
Bidirectional merge sort: 1299304
Copy then random-access sort: 253854
 */