#include <cctype>
#include <iostream>
#include <functional>
#include <limits>

namespace classlevels {
    template<class Out, class Pred>
    void print_all_chars(const char* category, Pred pred, char delim = 0) {
        std::cout << category;
        bool first = true;
        for (unsigned int i = 0; i < std::numeric_limits<unsigned char>::max(); i++) {
            if (pred(i)) {
                if (!first && delim)
                    std::cout << delim;
                first = false;
                Out c = static_cast<Out>(i);
                std::cout << c;
            }
        }
        std::cout << std::endl;
    }

    // $ is a valid identifier char for extensions on some compilers, but we'll stick
    // to standards here.
    // The question asked which chars can appear in an identifier, not how an identifier
    // must begin, so numbers are included.
    bool isidentifier(int c) {
        return isalnum(c) || c == '_';
    }
}

int main() {
    using namespace std;
    using namespace classlevels;

    print_all_chars<char>("All lowercase: ", ::islower);
    print_all_chars<char>("All letters: ", ::isalpha);
    print_all_chars<char>("All letters and digits: ", ::isalnum);
    print_all_chars<char>("All chars from C++ identifers: ", classlevels::isidentifier);
    print_all_chars<char>("All punctuation: ", ::ispunct);
    print_all_chars<int>("All control: ", ::iscntrl, ',');
    // commenting out because some whitespace chars screw up the terminal output
    // print_all_chars<char>("All whitespace (char): ", ::isspace, ',');
    print_all_chars<int>("All whitespace (int): ", ::isspace, ',');
    print_all_chars<char>("All printable: ", ::isprint);
}




/* Output */

/*
$g++ -o main *.cpp
$main
All lowercase: abcdefghijklmnopqrstuvwxyz
All letters: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
All letters and digits: 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
All chars from C++ identifers: 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz
All punctuation: !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
All control: 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,127
All whitespace (int): 9,10,11,12,13,32
All printable:  !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
 */