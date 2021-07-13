#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstring>

namespace exception {
    template<class T> class DefaultAllocator {
    public:
        static T allocate() { 
            return T(); 
        }
    };

    template<class Tkey,class Tval,class Talloc = DefaultAllocator<Tval> > class Map {
    public:
        struct Pair;
    private:
        // prevent copying
        Map(const Map&) {}
        void operator=(const Map&) {}

        typedef std::vector<Pair> ItemList;
        ItemList items;

    public:
        struct Pair {
            Tkey key;
            Tval val;
            Pair(const Tkey& key, const Tval& val) : key(key), val(val) {}
        };

        typedef typename ItemList::iterator iterator;
        typedef typename ItemList::const_iterator const_iterator;
        class MissingKeyError {};

        Map() {}
        Tval& operator[](const Tkey& key);
        const Tval& operator[](const Tkey& key) const;


        // The simplest possible iterator support...

        typename ItemList::iterator begin() { return items.begin(); }
        typename ItemList::iterator end() { return items.end(); }

        typename ItemList::const_iterator begin() const { return items.begin(); }
        typename ItemList::const_iterator end() const { return items.end(); }
    };

    template<class Tkey,class Tval,class Talloc> Tval& Map<Tkey,Tval,Talloc>::operator[](const Tkey& key) {
        for (typename ItemList::iterator i = items.begin(); i != items.end(); i++) {
            if (i->key == key) return i->val;
        }
        Tval v = Talloc::allocate();
        Pair p(key, v);
        items.push_back(p);
        return items.back().val;
    }

    template<class Tkey,class Tval,class Talloc> const Tval& Map<Tkey,Tval,Talloc>::operator[](const Tkey& key) const {
        for (typename ItemList::const_iterator i = items.begin(); i != items.end(); i++) {
            if(i->key == key) 
                return i->val;
        }
        throw MissingKeyError();
    }

    // For instances with char* as the key, just wrap an instance with string as the key.
    // The keys will be implicitly converted from char* to std::string. This saves us from
    // needing to allocate memory and keep copies of all the keys.
    //
    // In this way, if a char* is passed in as a key and then that memory is later modified,
    // the key remains the same (it is keyed off the underlying string, not the pointer).
    template<class Tval> class Map<char*,Tval> : public Map<std::string,Tval> {
    };

    struct NoDefaultCtor {
    private:
        NoDefaultCtor(){}

    public:
        int x;
        NoDefaultCtor(int xx) : x(xx) {}
    };

    class NoDefaultCtorAllocator {
    public:
        static NoDefaultCtor allocate() { return NoDefaultCtor(0); }
    };
}

int main() {
    using namespace std;
    using namespace exception;

    Map<string, int> m;
    m["hello"] = 1;
    m["world"] = 2;

    cout << m["hello"] << ' ' << m["world"] << endl;

    m["world"] = 3;
    cout << m["hello"] << ' ' << m["world"] << endl;

    Map<char*, int> m2;
    char* c = new char[6];
    strcpy(c,"abcde");
    m2[c] = 5;
    c[1] = 'x';
    cout << m2["abcde"] << endl; // Should print 5.

    Map<string, NoDefaultCtor, NoDefaultCtorAllocator> m3;
    m3["hello"] = NoDefaultCtor(1);
    m3["world"] = NoDefaultCtor(2);

    cout << m3["hello"].x << ' ' << m3["world"].x << ' ' << m3["!"].x << endl; // Should print 1 2 0

    // Test iterator
    for (Map<string, NoDefaultCtor, NoDefaultCtorAllocator>::iterator i = m3.begin(); i != m3.end(); i++)
        cout << i->val.x << ' ';
    cout << endl;

    return 0;
}



/* Output */

/* 
$g++ -o main *.cpp
$main
1 2
1 3
5
1 2 0
1 2 0 
 */