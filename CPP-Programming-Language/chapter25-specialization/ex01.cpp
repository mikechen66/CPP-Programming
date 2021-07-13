/* #include <istream> */
#include <map>
#include <string>
#include <sstream>
#include <iostream>

namespace specialization {
    using std::istream;
    using std::map;
    using std::string;

    // For regular objects
    class Io_obj {
    public:
        virtual Io_obj* clone() const = 0;
        virtual ~Io_obj() {}
    };

    template<class T>
    class Io : public T, public Io_obj {
    public:
        Io* clone() const { return new Io(*this); }
        Io(istream& s) : T(s) { }
        static Io_obj* new_io(istream& s) { return new Io(s); }
    };

    // Specialization for int (this would have to be repeated for each built-in type)
    template<>
    class Io<int> : public Io_obj {
        int x;
    public:
        Io_obj* clone() const { return new Io(*this); }
        Io(istream& s) { s >> x; }
        operator int() const { return x; }
        static Io_obj* new_io(istream& s) { return new Io(s); }
    };

    // Another way to do it; doesn't require specialization for every built-in type,
    // but requires the use of a different template.
    template<class T>
    class Io_scalar : public Io_obj {
        T x;
    public:
        Io_obj* clone() const { return new Io_scalar(*this); }
        Io_scalar(istream& s) { s >> x; }
        operator T() const { return x; }
        static Io_obj* new_io(istream& s) { return new Io_scalar(s); }
    };

    // Test regular object
    class Test {
        int x;
    public:
        Test(istream& s) { s >> x; }
        int get() const { return x; }
    };

    typedef Io_obj* (*PF) (istream&);
    map<string, PF> io_map;

    class No_class { };
    class Unknown_class { };

    bool get_word(istream& s, string& str) {
        return s >> str;
    }

    Io_obj* get_obj(istream& s) {
        string str;
        bool b = get_word(s, str);
        if (b == false) 
            throw No_class();

        PF f = io_map[str];
        if (f == 0) 
            throw Unknown_class();
        return f(s);
    }

    typedef Io<Test> Io_test;
    typedef Io<int> Io_int;
    typedef Io_scalar<int> Io_scalar_int;
}

int main() {
    using namespace std;
    using namespace specialization;

    io_map["Test"] = Io_test::new_io;
    io_map["int"] = Io_int::new_io;
    io_map["int_scalar"] = Io_scalar_int::new_io;

    string data = "Test 42 int 43 int_scalar 44";
    istringstream in(data);
    Io_obj* to = get_obj(in);
    Test* t = dynamic_cast<Test*>(to);
    if (t)
        cout << t->get() << endl;
    to = get_obj(in);
    int i = *dynamic_cast<Io<int>*>(to);
    cout << i << endl;
    to = get_obj(in);
    i = *dynamic_cast<Io_scalar<int>*>(to);
    cout << i << endl;
}



/* Output */

/*
$g++ -o main *.cpp
main.cpp:16:25: error: expected unqualified-id before ‘)’ token
         virtual Io_obj* ) const = 0;
                         ^
main.cpp:16:23: error: expected ‘;’ at end of member declaration
         virtual Io_obj* ) const = 0;
                       ^
main.cpp:16:25: error: expected unqualified-id before ‘)’ token
         virtual Io_obj* ) const = 0;
                         ^
main.cpp:23:13: error: expected unqualified-id before ‘)’ token
         Io* ) const { return new Io(*this); }
             ^
main.cpp:23:11: error: expected ‘;’ at end of member declaration
         Io* ) const { return new Io(*this); }
           ^
main.cpp:23:13: error: expected unqualified-id before ‘)’ token
         Io* ) const { return new Io(*this); }
             ^
main.cpp:33:17: error: expected unqualified-id before ‘)’ token
         Io_obj* ) const { return new Io(*this); }
                 ^
main.cpp:33:15: error: expected ‘;’ at end of member declaration
         Io_obj* ) const { return new Io(*this); }
               ^
main.cpp:33:17: error: expected unqualified-id before ‘)’ token
         Io_obj* ) const { return new Io(*this); }
                 ^
main.cpp:45:17: error: expected unqualified-id before ‘)’ token
         Io_obj* ) const { return new Io_scalar(*this); }
                 ^
main.cpp:45:15: error: expected ‘;’ at end of member declaration
         Io_obj* ) const { return new Io_scalar(*this); }
               ^
main.cpp:45:17: error: expected unqualified-id before ‘)’ token
         Io_obj* ) const { return new Io_scalar(*this); }
                 ^
main.cpp: In function ‘bool specialization::get_word(std::istream&, std::__cxx11::string&)’:
main.cpp:66:21: error: cannot convert ‘std::basic_istream<char>’ to ‘bool’ in return
         return s >> str;
                     ^~~
 */