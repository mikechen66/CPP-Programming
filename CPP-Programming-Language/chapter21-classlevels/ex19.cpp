#include <iostream>
#include <string>
#include <termios.h>

// This isn't portable and it's also a bit crude because it only works for stdin.
// Using it with anything but cin will have no effect.
namespace classlevels {
    void set_echo(bool enable) {
        termios tty;
        tcgetattr(STDIN_FILENO, &tty);
        if (enable)
            tty.c_lflag |= ECHO;
        else
            tty.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &tty);
    }

    std::istream& echo_on(std::istream& in) {
        if (in == std::cin)
            set_echo(true);
        return in;
    }

    std::istream& echo_off(std::istream& in) {
        if (in == std::cin)
            set_echo(false);
        return in;
    }
}

int main() {
    using namespace std;
    using namespace classlevels;

    cout << "Enter hidden integer: ";
    string s;
    cin >> echo_off >> s;
    cout << "\nYou entered: " << s << endl;
    cout << "Enter shown integer: ";
    cin >> echo_on >> s;
}


/* Output */

/*
$g++ -o main *.cpp
main.cpp: In function ‘void classlevels::set_echo(bool)’:
main.cpp:10:19: error: ‘STDIN_FILENO’ was not declared in this scope
         tcgetattr(STDIN_FILENO, &tty);
                   ^~~~~~~~~~~~
main.cpp:10:19: note: suggested alternative: ‘_IO_FILE’
         tcgetattr(STDIN_FILENO, &tty);
                   ^~~~~~~~~~~~
                   _IO_FILE
main.cpp: In function ‘std::istream& classlevels::echo_on(std::istream&)’:
main.cpp:19:16: error: no match for ‘operator==’ (operand types are ‘std::istream {aka std::basic_istream<char>}’ and ‘std::istream {aka std::basic_istream<char>}’)
         if (in == std::cin)
             ~~~^~~~~~
main.cpp:19:16: note: candidate: operator==(int, int) <built-in>
main.cpp:19:16: note:   no known conversion for argument 2 from ‘std::istream {aka std::basic_istream<char>}’ to ‘int’
In file included from /usr/include/c++/7/bits/locale_facets.h:48:0,
                 from /usr/include/c++/7/bits/basic_ios.h:37,
                 from /usr/include/c++/7/ios:44,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/bits/streambuf_iterator.h:204:5: note: candidate: template<class _CharT, class _Traits> bool std::operator==(const std::istreambuf_iterator<_CharT, _Traits>&, const std::istreambuf_iterator<_CharT, _Traits>&)
     operator==(const istreambuf_iterator<_CharT, _Traits>& __a,
     ^~~~~~~~
/usr/include/c++/7/bits/streambuf_iterator.h:204:5: note:   template argument deduction/substitution failed:
main.cpp:19:24: note:   ‘std::istream {aka std::basic_istream<char>}’ is not derived from ‘const std::istreambuf_iterator<_CharT, _Traits>’
         if (in == std::cin)
                        ^~~
In file included from /usr/include/c++/7/bits/ios_base.h:46:0,
                 from /usr/include/c++/7/ios:42,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/system_error:311:3: note: candidate: bool std::operator==(const std::error_condition&, const std::error_condition&)
   operator==(const error_condition& __lhs,
   ^~~~~~~~
/usr/include/c++/7/system_error:311:3: note:   no known conversion for argument 1 from ‘std::istream {aka std::basic_istream<char>}’ to ‘const std::error_condition&’
/usr/include/c++/7/system_error:304:3: note: candidate: bool std::operator==(const std::error_condition&, const std::error_code&)
   operator==(const error_condition& __lhs, const error_code& __rhs) noexcept
   ^~~~~~~~
/usr/include/c++/7/system_error:304:3: note:   no known conversion for argument 1 from ‘std::istream {aka std::basic_istream<char>}’ to ‘const std::error_condition&’
/usr/include/c++/7/system_error:297:3: note: candidate: bool std::operator==(const std::error_code&, const std::error_condition&)
   operator==(const error_code& __lhs, const error_condition& __rhs) noexcept
   ^~~~~~~~
/usr/include/c++/7/system_error:297:3: note:   no known conversion for argument 1 from ‘std::istream {aka std::basic_istream<char>}’ to ‘const std::error_code&’
/usr/include/c++/7/system_error:292:3: note: candidate: bool std::operator==(const std::error_code&, const std::error_code&)
   operator==(const error_code& __lhs, const error_code& __rhs) noexcept
   ^~~~~~~~
/usr/include/c++/7/system_error:292:3: note:   no known conversion for argument 1 from ‘std::istream {aka std::basic_istream<char>}’ to ‘const std::error_code&’
In file included from /usr/include/c++/7/string:52:0,
                 from /usr/include/c++/7/bits/locale_classes.h:40,
                 from /usr/include/c++/7/bits/ios_base.h:41,
                 from /usr/include/c++/7/ios:42,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/bits/basic_string.h:5841:5: note: candidate: template<class _CharT, class _Traits, class _Alloc> bool std::operator==(const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>&, const _CharT*)
     operator==(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
     ^~~~~~~~
/usr/include/c++/7/bits/basic_string.h:5841:5: note:   template argument deduction/substitution failed:
main.cpp:19:24: note:   ‘std::istream {aka std::basic_istream<char>}’ is not derived from ‘const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>’
         if (in == std::cin)
                        ^~~
In file included from /usr/include/c++/7/string:52:0,
                 from /usr/include/c++/7/bits/locale_classes.h:40,
                 from /usr/include/c++/7/bits/ios_base.h:41,
                 from /usr/include/c++/7/ios:42,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/bits/basic_string.h:5829:5: note: candidate: template<class _CharT, class _Traits, class _Alloc> bool std::operator==(const _CharT*, const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>&)
     operator==(const _CharT* __lhs,
     ^~~~~~~~
/usr/include/c++/7/bits/basic_string.h:5829:5: note:   template argument deduction/substitution failed:
main.cpp:19:24: note:   mismatched types ‘const _CharT*’ and ‘std::basic_istream<char>’
         if (in == std::cin)
                        ^~~
In file included from /usr/include/c++/7/string:52:0,
                 from /usr/include/c++/7/bits/locale_classes.h:40,
                 from /usr/include/c++/7/bits/ios_base.h:41,
                 from /usr/include/c++/7/ios:42,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/bits/basic_string.h:5815:5: note: candidate: template<class _CharT> typename __gnu_cxx::__enable_if<std::__is_char<_Tp>::__value, bool>::__type std::operator==(const std::__cxx11::basic_string<_CharT>&, const std::__cxx11::basic_string<_CharT>&)
     operator==(const basic_string<_CharT>& __lhs,
     ^~~~~~~~
/usr/include/c++/7/bits/basic_string.h:5815:5: note:   template argument deduction/substitution failed:
main.cpp:19:24: note:   ‘std::istream {aka std::basic_istream<char>}’ is not derived from ‘const std::__cxx11::basic_string<_CharT>’
         if (in == std::cin)
                        ^~~
In file included from /usr/include/c++/7/string:52:0,
                 from /usr/include/c++/7/bits/locale_classes.h:40,
                 from /usr/include/c++/7/bits/ios_base.h:41,
                 from /usr/include/c++/7/ios:42,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/bits/basic_string.h:5807:5: note: candidate: template<class _CharT, class _Traits, class _Alloc> bool std::operator==(const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>&, const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>&)
     operator==(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
     ^~~~~~~~
/usr/include/c++/7/bits/basic_string.h:5807:5: note:   template argument deduction/substitution failed:
main.cpp:19:24: note:   ‘std::istream {aka std::basic_istream<char>}’ is not derived from ‘const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>’
         if (in == std::cin)
                        ^~~
In file included from /usr/include/c++/7/string:41:0,
                 from /usr/include/c++/7/bits/locale_classes.h:40,
                 from /usr/include/c++/7/bits/ios_base.h:41,
                 from /usr/include/c++/7/ios:42,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/bits/allocator.h:152:5: note: candidate: template<class _Tp> bool std::operator==(const std::allocator<_CharT>&, const std::allocator<_CharT>&)
     operator==(const allocator<_Tp>&, const allocator<_Tp>&)
     ^~~~~~~~
/usr/include/c++/7/bits/allocator.h:152:5: note:   template argument deduction/substitution failed:
main.cpp:19:24: note:   ‘std::istream {aka std::basic_istream<char>}’ is not derived from ‘const std::allocator<_CharT>’
         if (in == std::cin)
                        ^~~
In file included from /usr/include/c++/7/string:41:0,
                 from /usr/include/c++/7/bits/locale_classes.h:40,
                 from /usr/include/c++/7/bits/ios_base.h:41,
                 from /usr/include/c++/7/ios:42,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/bits/allocator.h:146:5: note: candidate: template<class _T1, class _T2> bool std::operator==(const std::allocator<_CharT>&, const std::allocator<_T2>&)
     operator==(const allocator<_T1>&, const allocator<_T2>&)
     ^~~~~~~~
/usr/include/c++/7/bits/allocator.h:146:5: note:   template argument deduction/substitution failed:
main.cpp:19:24: note:   ‘std::istream {aka std::basic_istream<char>}’ is not derived from ‘const std::allocator<_CharT>’
         if (in == std::cin)
                        ^~~
In file included from /usr/include/c++/7/bits/stl_algobase.h:67:0,
                 from /usr/include/c++/7/bits/char_traits.h:39,
                 from /usr/include/c++/7/ios:40,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/bits/stl_iterator.h:1124:5: note: candidate: template<class _Iterator> bool std::operator==(const std::move_iterator<_IteratorL>&, const std::move_iterator<_IteratorL>&)
     operator==(const move_iterator<_Iterator>& __x,
     ^~~~~~~~
/usr/include/c++/7/bits/stl_iterator.h:1124:5: note:   template argument deduction/substitution failed:
main.cpp:19:24: note:   ‘std::istream {aka std::basic_istream<char>}’ is not derived from ‘const std::move_iterator<_IteratorL>’
         if (in == std::cin)
                        ^~~
In file included from /usr/include/c++/7/bits/stl_algobase.h:67:0,
                 from /usr/include/c++/7/bits/char_traits.h:39,
                 from /usr/include/c++/7/ios:40,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/bits/stl_iterator.h:1118:5: note: candidate: template<class _IteratorL, class _IteratorR> bool std::operator==(const std::move_iterator<_IteratorL>&, const std::move_iterator<_IteratorR>&)
     operator==(const move_iterator<_IteratorL>& __x,
     ^~~~~~~~
/usr/include/c++/7/bits/stl_iterator.h:1118:5: note:   template argument deduction/substitution failed:
main.cpp:19:24: note:   ‘std::istream {aka std::basic_istream<char>}’ is not derived from ‘const std::move_iterator<_IteratorL>’
         if (in == std::cin)
                        ^~~
In file included from /usr/include/c++/7/bits/stl_algobase.h:67:0,
                 from /usr/include/c++/7/bits/char_traits.h:39,
                 from /usr/include/c++/7/ios:40,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/bits/stl_iterator.h:337:5: note: candidate: template<class _IteratorL, class _IteratorR> bool std::operator==(const std::reverse_iterator<_Iterator>&, const std::reverse_iterator<_IteratorR>&)
     operator==(const reverse_iterator<_IteratorL>& __x,
     ^~~~~~~~
/usr/include/c++/7/bits/stl_iterator.h:337:5: note:   template argument deduction/substitution failed:
main.cpp:19:24: note:   ‘std::istream {aka std::basic_istream<char>}’ is not derived from ‘const std::reverse_iterator<_Iterator>’
         if (in == std::cin)
                        ^~~
In file included from /usr/include/c++/7/bits/stl_algobase.h:67:0,
                 from /usr/include/c++/7/bits/char_traits.h:39,
                 from /usr/include/c++/7/ios:40,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/bits/stl_iterator.h:299:5: note: candidate: template<class _Iterator> bool std::operator==(const std::reverse_iterator<_Iterator>&, const std::reverse_iterator<_Iterator>&)
     operator==(const reverse_iterator<_Iterator>& __x,
     ^~~~~~~~
/usr/include/c++/7/bits/stl_iterator.h:299:5: note:   template argument deduction/substitution failed:
main.cpp:19:24: note:   ‘std::istream {aka std::basic_istream<char>}’ is not derived from ‘const std::reverse_iterator<_Iterator>’
         if (in == std::cin)
                        ^~~
In file included from /usr/include/c++/7/bits/stl_algobase.h:64:0,
                 from /usr/include/c++/7/bits/char_traits.h:39,
                 from /usr/include/c++/7/ios:40,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/bits/stl_pair.h:443:5: note: candidate: template<class _T1, class _T2> constexpr bool std::operator==(const std::pair<_T1, _T2>&, const std::pair<_T1, _T2>&)
     operator==(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
     ^~~~~~~~
/usr/include/c++/7/bits/stl_pair.h:443:5: note:   template argument deduction/substitution failed:
main.cpp:19:24: note:   ‘std::istream {aka std::basic_istream<char>}’ is not derived from ‘const std::pair<_T1, _T2>’
         if (in == std::cin)
                        ^~~
In file included from /usr/include/c++/7/iosfwd:40:0,
                 from /usr/include/c++/7/ios:38,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/bits/postypes.h:216:5: note: candidate: template<class _StateT> bool std::operator==(const std::fpos<_StateT>&, const std::fpos<_StateT>&)
     operator==(const fpos<_StateT>& __lhs, const fpos<_StateT>& __rhs)
     ^~~~~~~~
/usr/include/c++/7/bits/postypes.h:216:5: note:   template argument deduction/substitution failed:
main.cpp:19:24: note:   ‘std::istream {aka std::basic_istream<char>}’ is not derived from ‘const std::fpos<_StateT>’
         if (in == std::cin)
                        ^~~
main.cpp: In function ‘std::istream& classlevels::echo_off(std::istream&)’:
main.cpp:25:16: error: no match for ‘operator==’ (operand types are ‘std::istream {aka std::basic_istream<char>}’ and ‘std::istream {aka std::basic_istream<char>}’)
         if (in == std::cin)
             ~~~^~~~~~
main.cpp:25:16: note: candidate: operator==(int, int) <built-in>
main.cpp:25:16: note:   no known conversion for argument 2 from ‘std::istream {aka std::basic_istream<char>}’ to ‘int’
In file included from /usr/include/c++/7/bits/locale_facets.h:48:0,
                 from /usr/include/c++/7/bits/basic_ios.h:37,
                 from /usr/include/c++/7/ios:44,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/bits/streambuf_iterator.h:204:5: note: candidate: template<class _CharT, class _Traits> bool std::operator==(const std::istreambuf_iterator<_CharT, _Traits>&, const std::istreambuf_iterator<_CharT, _Traits>&)
     operator==(const istreambuf_iterator<_CharT, _Traits>& __a,
     ^~~~~~~~
/usr/include/c++/7/bits/streambuf_iterator.h:204:5: note:   template argument deduction/substitution failed:
main.cpp:25:24: note:   ‘std::istream {aka std::basic_istream<char>}’ is not derived from ‘const std::istreambuf_iterator<_CharT, _Traits>’
         if (in == std::cin)
                        ^~~
In file included from /usr/include/c++/7/bits/ios_base.h:46:0,
                 from /usr/include/c++/7/ios:42,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/system_error:311:3: note: candidate: bool std::operator==(const std::error_condition&, const std::error_condition&)
   operator==(const error_condition& __lhs,
   ^~~~~~~~
/usr/include/c++/7/system_error:311:3: note:   no known conversion for argument 1 from ‘std::istream {aka std::basic_istream<char>}’ to ‘const std::error_condition&’
/usr/include/c++/7/system_error:304:3: note: candidate: bool std::operator==(const std::error_condition&, const std::error_code&)
   operator==(const error_condition& __lhs, const error_code& __rhs) noexcept
   ^~~~~~~~
/usr/include/c++/7/system_error:304:3: note:   no known conversion for argument 1 from ‘std::istream {aka std::basic_istream<char>}’ to ‘const std::error_condition&’
/usr/include/c++/7/system_error:297:3: note: candidate: bool std::operator==(const std::error_code&, const std::error_condition&)
   operator==(const error_code& __lhs, const error_condition& __rhs) noexcept
   ^~~~~~~~
/usr/include/c++/7/system_error:297:3: note:   no known conversion for argument 1 from ‘std::istream {aka std::basic_istream<char>}’ to ‘const std::error_code&’
/usr/include/c++/7/system_error:292:3: note: candidate: bool std::operator==(const std::error_code&, const std::error_code&)
   operator==(const error_code& __lhs, const error_code& __rhs) noexcept
   ^~~~~~~~
/usr/include/c++/7/system_error:292:3: note:   no known conversion for argument 1 from ‘std::istream {aka std::basic_istream<char>}’ to ‘const std::error_code&’
In file included from /usr/include/c++/7/string:52:0,
                 from /usr/include/c++/7/bits/locale_classes.h:40,
                 from /usr/include/c++/7/bits/ios_base.h:41,
                 from /usr/include/c++/7/ios:42,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/bits/basic_string.h:5841:5: note: candidate: template<class _CharT, class _Traits, class _Alloc> bool std::operator==(const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>&, const _CharT*)
     operator==(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
     ^~~~~~~~
/usr/include/c++/7/bits/basic_string.h:5841:5: note:   template argument deduction/substitution failed:
main.cpp:25:24: note:   ‘std::istream {aka std::basic_istream<char>}’ is not derived from ‘const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>’
         if (in == std::cin)
                        ^~~
In file included from /usr/include/c++/7/string:52:0,
                 from /usr/include/c++/7/bits/locale_classes.h:40,
                 from /usr/include/c++/7/bits/ios_base.h:41,
                 from /usr/include/c++/7/ios:42,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/bits/basic_string.h:5829:5: note: candidate: template<class _CharT, class _Traits, class _Alloc> bool std::operator==(const _CharT*, const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>&)
     operator==(const _CharT* __lhs,
     ^~~~~~~~
/usr/include/c++/7/bits/basic_string.h:5829:5: note:   template argument deduction/substitution failed:
main.cpp:25:24: note:   mismatched types ‘const _CharT*’ and ‘std::basic_istream<char>’
         if (in == std::cin)
                        ^~~
In file included from /usr/include/c++/7/string:52:0,
                 from /usr/include/c++/7/bits/locale_classes.h:40,
                 from /usr/include/c++/7/bits/ios_base.h:41,
                 from /usr/include/c++/7/ios:42,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/bits/basic_string.h:5815:5: note: candidate: template<class _CharT> typename __gnu_cxx::__enable_if<std::__is_char<_Tp>::__value, bool>::__type std::operator==(const std::__cxx11::basic_string<_CharT>&, const std::__cxx11::basic_string<_CharT>&)
     operator==(const basic_string<_CharT>& __lhs,
     ^~~~~~~~
/usr/include/c++/7/bits/basic_string.h:5815:5: note:   template argument deduction/substitution failed:
main.cpp:25:24: note:   ‘std::istream {aka std::basic_istream<char>}’ is not derived from ‘const std::__cxx11::basic_string<_CharT>’
         if (in == std::cin)
                        ^~~
In file included from /usr/include/c++/7/string:52:0,
                 from /usr/include/c++/7/bits/locale_classes.h:40,
                 from /usr/include/c++/7/bits/ios_base.h:41,
                 from /usr/include/c++/7/ios:42,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/bits/basic_string.h:5807:5: note: candidate: template<class _CharT, class _Traits, class _Alloc> bool std::operator==(const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>&, const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>&)
     operator==(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
     ^~~~~~~~
/usr/include/c++/7/bits/basic_string.h:5807:5: note:   template argument deduction/substitution failed:
main.cpp:25:24: note:   ‘std::istream {aka std::basic_istream<char>}’ is not derived from ‘const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>’
         if (in == std::cin)
                        ^~~
In file included from /usr/include/c++/7/string:41:0,
                 from /usr/include/c++/7/bits/locale_classes.h:40,
                 from /usr/include/c++/7/bits/ios_base.h:41,
                 from /usr/include/c++/7/ios:42,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/bits/allocator.h:152:5: note: candidate: template<class _Tp> bool std::operator==(const std::allocator<_CharT>&, const std::allocator<_CharT>&)
     operator==(const allocator<_Tp>&, const allocator<_Tp>&)
     ^~~~~~~~
/usr/include/c++/7/bits/allocator.h:152:5: note:   template argument deduction/substitution failed:
main.cpp:25:24: note:   ‘std::istream {aka std::basic_istream<char>}’ is not derived from ‘const std::allocator<_CharT>’
         if (in == std::cin)
                        ^~~
In file included from /usr/include/c++/7/string:41:0,
                 from /usr/include/c++/7/bits/locale_classes.h:40,
                 from /usr/include/c++/7/bits/ios_base.h:41,
                 from /usr/include/c++/7/ios:42,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/bits/allocator.h:146:5: note: candidate: template<class _T1, class _T2> bool std::operator==(const std::allocator<_CharT>&, const std::allocator<_T2>&)
     operator==(const allocator<_T1>&, const allocator<_T2>&)
     ^~~~~~~~
/usr/include/c++/7/bits/allocator.h:146:5: note:   template argument deduction/substitution failed:
main.cpp:25:24: note:   ‘std::istream {aka std::basic_istream<char>}’ is not derived from ‘const std::allocator<_CharT>’
         if (in == std::cin)
                        ^~~
In file included from /usr/include/c++/7/bits/stl_algobase.h:67:0,
                 from /usr/include/c++/7/bits/char_traits.h:39,
                 from /usr/include/c++/7/ios:40,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/bits/stl_iterator.h:1124:5: note: candidate: template<class _Iterator> bool std::operator==(const std::move_iterator<_IteratorL>&, const std::move_iterator<_IteratorL>&)
     operator==(const move_iterator<_Iterator>& __x,
     ^~~~~~~~
/usr/include/c++/7/bits/stl_iterator.h:1124:5: note:   template argument deduction/substitution failed:
main.cpp:25:24: note:   ‘std::istream {aka std::basic_istream<char>}’ is not derived from ‘const std::move_iterator<_IteratorL>’
         if (in == std::cin)
                        ^~~
In file included from /usr/include/c++/7/bits/stl_algobase.h:67:0,
                 from /usr/include/c++/7/bits/char_traits.h:39,
                 from /usr/include/c++/7/ios:40,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/bits/stl_iterator.h:1118:5: note: candidate: template<class _IteratorL, class _IteratorR> bool std::operator==(const std::move_iterator<_IteratorL>&, const std::move_iterator<_IteratorR>&)
     operator==(const move_iterator<_IteratorL>& __x,
     ^~~~~~~~
/usr/include/c++/7/bits/stl_iterator.h:1118:5: note:   template argument deduction/substitution failed:
main.cpp:25:24: note:   ‘std::istream {aka std::basic_istream<char>}’ is not derived from ‘const std::move_iterator<_IteratorL>’
         if (in == std::cin)
                        ^~~
In file included from /usr/include/c++/7/bits/stl_algobase.h:67:0,
                 from /usr/include/c++/7/bits/char_traits.h:39,
                 from /usr/include/c++/7/ios:40,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/bits/stl_iterator.h:337:5: note: candidate: template<class _IteratorL, class _IteratorR> bool std::operator==(const std::reverse_iterator<_Iterator>&, const std::reverse_iterator<_IteratorR>&)
     operator==(const reverse_iterator<_IteratorL>& __x,
     ^~~~~~~~
/usr/include/c++/7/bits/stl_iterator.h:337:5: note:   template argument deduction/substitution failed:
main.cpp:25:24: note:   ‘std::istream {aka std::basic_istream<char>}’ is not derived from ‘const std::reverse_iterator<_Iterator>’
         if (in == std::cin)
                        ^~~
In file included from /usr/include/c++/7/bits/stl_algobase.h:67:0,
                 from /usr/include/c++/7/bits/char_traits.h:39,
                 from /usr/include/c++/7/ios:40,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/bits/stl_iterator.h:299:5: note: candidate: template<class _Iterator> bool std::operator==(const std::reverse_iterator<_Iterator>&, const std::reverse_iterator<_Iterator>&)
     operator==(const reverse_iterator<_Iterator>& __x,
     ^~~~~~~~
/usr/include/c++/7/bits/stl_iterator.h:299:5: note:   template argument deduction/substitution failed:
main.cpp:25:24: note:   ‘std::istream {aka std::basic_istream<char>}’ is not derived from ‘const std::reverse_iterator<_Iterator>’
         if (in == std::cin)
                        ^~~
In file included from /usr/include/c++/7/bits/stl_algobase.h:64:0,
                 from /usr/include/c++/7/bits/char_traits.h:39,
                 from /usr/include/c++/7/ios:40,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/bits/stl_pair.h:443:5: note: candidate: template<class _T1, class _T2> constexpr bool std::operator==(const std::pair<_T1, _T2>&, const std::pair<_T1, _T2>&)
     operator==(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
     ^~~~~~~~
/usr/include/c++/7/bits/stl_pair.h:443:5: note:   template argument deduction/substitution failed:
main.cpp:25:24: note:   ‘std::istream {aka std::basic_istream<char>}’ is not derived from ‘const std::pair<_T1, _T2>’
         if (in == std::cin)
                        ^~~
In file included from /usr/include/c++/7/iosfwd:40:0,
                 from /usr/include/c++/7/ios:38,
                 from /usr/include/c++/7/ostream:38,
                 from /usr/include/c++/7/iostream:39,
                 from main.cpp:1:
/usr/include/c++/7/bits/postypes.h:216:5: note: candidate: template<class _StateT> bool std::operator==(const std::fpos<_StateT>&, const std::fpos<_StateT>&)
     operator==(const fpos<_StateT>& __lhs, const fpos<_StateT>& __rhs)
     ^~~~~~~~
/usr/include/c++/7/bits/postypes.h:216:5: note:   template argument deduction/substitution failed:
main.cpp:25:24: note:   ‘std::istream {aka std::basic_istream<char>}’ is not derived from ‘const std::fpos<_StateT>’
         if (in == std::cin)
                        ^~~
 */