#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace ch13 {
    //
    // Start Qsort algorithm, borrowed from exercise 6 (with modifications).
    //
    template<class T,class Tcomparer>
    void qsort(std::vector<T>& list, int start, int end) {
        using std::swap;

        if (start >= end) 
            return;

        // For simplicity, use the middle element as the pivot
        int pivotIdx = start + (end - start) / 2;
        T pivot = list[pivotIdx];
        swap(list[pivotIdx], list[end]);

        int s = start;
        for (int i = start; i < end; i++) {
            if (Tcomparer::compare(list[i],pivot) < 0) {
                swap(list[i], list[s]);
                s++;
            }
        }
        swap(list[s], list[end]);

        qsort<T,Tcomparer>(list, start, s-1);
        qsort<T,Tcomparer>(list, s+1, end);
    }

    // Implements qsort for a vector of items of type T.
    template<class T,class Tcomparer>
    void qsort(std::vector<T>& list) {
        qsort<T,Tcomparer>(list, 0, list.size()-1);
    }

    // comparers strings in reverse-lexicographic order.
    template<class T, class Tcomparer>
    class ReverseLexStringcomparer {
    public:
        static int compare(const std::basic_string<T>& s1, const std::basic_string<T>& s2) {
            int l1 = s1.length();
            int l2 = s2.length();
            for (int i = 0; i <= std::min(l1,l2); i++) {
                int dif = Tcomparer::compare(s1[l1-i],s2[l2-i]);
                if (dif) 
                    return dif > 0 ? 1 : -1;
            }
            return l1 - l2;
        };
    };

    // Standard char comparer 
    class Charcomparer {
    public:
        // Always implicitly cast to unsigned char to handle implementations with
        // signed vs. unsigned char consistently. Chars that are "negative" will
        // never be sorted less than "positive" chars.
        //
        // It is unclear whether this was the intention of the exercise.
        static int compare(unsigned char c1, unsigned char c2) {
            return c1 - c2;
        }
    };

    //
    // Case-insensitive char comparer
    //
    class CaseInsensitiveCharcomparer {
    public:
        static int compare(unsigned char c1, unsigned char c2) {
            return toupper(c1) - toupper(c2);
        }
    };
}

int main() {
    using namespace std;
    using namespace ch13;

    vector<basic_string<char> > test;
    test.push_back("hello");
    test.push_back("abcde");
    test.push_back("abcdf");
    test.push_back("xbcde");
    test.push_back("hello1");
    test.push_back("hello2");
    test.push_back("XBCDe");
    test.push_back("abcdE");
    test.push_back("abcdd");

    cout << "Standard sort, case sensitive:" << endl;
    qsort<basic_string<char>,ReverseLexStringcomparer<char, Charcomparer> >(test);
    for (vector<basic_string<char> >::const_iterator i = test.begin(); i != test.end(); i++) {
        cout << *i << endl;
    }

    cout << "Standard sort, case insensitive:" << endl;
    qsort<basic_string<char>,ReverseLexStringcomparer<char, CaseInsensitiveCharcomparer> >(test);
    for (vector<basic_string<char> >::const_iterator i = test.begin(); i != test.end(); i++) {
        cout << *i << endl;
    }

    return 0;
}



/* Output */

/* 
$g++ -o main *.cpp
$main
Standard sort, case sensitive:
hello1
hello2
abcdE
abcdd
XBCDe
abcde
xbcde
abcdf
hello
Standard sort, case insensitive:
hello1
hello2
abcdd
abcdE
abcde
XBCDe
xbcde
abcdf
hello
 */