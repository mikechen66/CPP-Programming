#include <iostream>
#include <map>
#include <string>

namespace ch13 {
    // The type T must have a default constructor that initializes it to zero.
    // T must also implement the += operator with another T.
    // K must have a compare operator (<) and equality (==).
    // Both types must have stream input operators (>>).
    // In this enhancement, key must have an explicit conversion from std::string.
    template<class K,class T> void sum_inputs() {
        using namespace std;

        map<K,T> store;

        cout << "Enter key value pairs, one per line, in the form key=value. Type a single `.' when done." << endl;
        K key;
        T val;

        string tmp;
        for (;;) {
            char ch;
            tmp.clear();
            while (cin.get(ch) && ch == '\n') 
                continue;
            cin.putback(ch);
            while (cin.get(ch) && ch != '=' && ch != '.') 
                tmp.push_back(ch);
            if (ch=='.') 
                break;
            key = K(tmp);
            cin >> val;
            store[key] += val;
        }

        cout << "Here are the sums:" << endl;
        for (typename map<K,T>::const_iterator i = store.begin(); i != store.end(); i++) {
            cout << i->first << ": " << i->second << endl;
        }
    }
}

int main() {
    using namespace std;
    using namespace ch13;

    sum_inputs<string,int>();

    return 0;
}



/* Output */

/*
$g++ -o main *.cpp
$main
Enter key value pairs, one per line, in the form key=value. Type a single `.' when done.
 */