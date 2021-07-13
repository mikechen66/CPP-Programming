#include <string>
#include <iostream>
#include <cstring>

namespace derivedops {
    using namespace std;

    template<class Ch>
    class Basic_substring {
    public:
        typedef typename basic_string<Ch>::size_type size_type;

        Basic_substring(basic_string<Ch>& s, size_type i, size_type n);
        Basic_substring(basic_string<Ch>& s, const basic_string<Ch>& s2);
        Basic_substring(basic_string<Ch>& s, const Ch* p);
        Basic_substring(const Basic_substring<Ch>& x);
        ~Basic_substring();

        Basic_substring& operator=(const basic_string<Ch>& s);
        Basic_substring& operator=(const Basic_substring<Ch>& x);
        Basic_substring& operator=(const Ch* p);
        Basic_substring& operator=(Ch c);

        operator basic_string<Ch>() const;
        operator const Ch* () const;
    private:
        basic_string<Ch>* ps;
        size_type pos;
        size_type n;
        mutable Ch* cstr;
    };

    template<class Ch>
    Basic_substring<Ch>::Basic_substring(basic_string<Ch>& s, size_type i, size_type n) : ps(&s), pos(i), n(n), cstr(0) {
    }

    template<class Ch>
    Basic_substring<Ch>::Basic_substring(basic_string<Ch>& s, const basic_string<Ch>& s2) : ps(&s), n(s2.size()), cstr(0) {
        pos = s.find(s2);
    }

    template<class Ch>
    Basic_substring<Ch>::Basic_substring(basic_string<Ch>& s, const Ch* p) : ps(&s), n(strlen(p)), cstr(0) {
        pos = s.find(p);
    }

    template<class Ch>
    Basic_substring<Ch>::Basic_substring(const Basic_substring<Ch>& x) : ps(x.ps), pos(x.pos), n(x.n), cstr(0) {
    }

    template<class Ch>
    Basic_substring<Ch>::~Basic_substring() {
        if (cstr)
            delete[] cstr;
    }

    template<class Ch>
    Basic_substring<Ch>& Basic_substring<Ch>::operator=(const basic_string<Ch>& s) {
        ps->replace(pos, n, s);
    }

    template<class Ch>
    Basic_substring<Ch>& Basic_substring<Ch>::operator=(const Basic_substring<Ch>& s) {
        ps->replace(pos, n, s);
    }

    template<class Ch>
    Basic_substring<Ch>& Basic_substring<Ch>::operator=(const Ch* p) {
        ps->replace(pos, n, p);
    }

    template<class Ch>
    Basic_substring<Ch>& Basic_substring<Ch>::operator=(Ch c) {
        ps->replace(pos, n, 1, c);
    }

    template<class Ch>
    Basic_substring<Ch>::operator basic_string<Ch>() const {
        return basic_string<Ch>(*ps, pos, n);
    }

    template<class Ch>
    Basic_substring<Ch>::operator const Ch*() const {
        if (!cstr) {
            cstr = new Ch[n + 1];
            strcpy(cstr, basic_string<Ch>(*ps, pos, n).c_str());
        }
        return cstr;
    }

    class String : public basic_string<char> {
    public:
        String(const String& str, size_t pos, size_t n = basic_string<char>::npos) :
            basic_string<char>(str, pos, n) { }
        String(const char* s, size_t n) :
            basic_string<char>(s, n) { }
        String(const char* s) :
            basic_string<char>(s) { }
        String(size_t n, char c) :
            basic_string<char>(n, c) { }
        template<class In>
        String(In first, In last) :
            basic_string<char>(first, last) { }

        Basic_substring<char> operator()(size_t pos, size_t n) {
            return Basic_substring<char>(*this, pos, n);
        }
    };
}

int main() {
    using namespace derivedops;

    String s("Hello foo world!");
    Basic_substring<char> sub = s(6, 4);
    cout << sub << endl;
    sub = "bar ";
    cout << s << endl;
    sub = "";
    cout << s << endl;
}



/* Output */

/*
$g++ -o main *.cpp
$main
foo 
Hello bar world!
Hello world!
 */