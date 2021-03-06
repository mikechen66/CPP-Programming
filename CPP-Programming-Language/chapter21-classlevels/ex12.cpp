#include <fstream>
#include <iostream>

namespace classlevels {
    class File_random_access {
        std::ifstream f;

    public:
        File_random_access(const char* file) : f(file) {
            f.exceptions(std::ios::failbit | std::ios::eofbit);
        }
        char operator[](std::streampos pos) {
            f.seekg(pos, std::ios::beg);
            return f.peek();
        }
    };
}

int main() {
    using namespace std;
    using namespace classlevels;

    ofstream out("ex12.txt");
    out << "abcdefghijklmnopqrstuvwxyz";
    out.close();

    File_random_access f("ex12.txt");
    cout << "char 5 = " << f[5] << endl;
    cout << "char 10 = " << f[10] << endl;
    cout << "char 0 = " << f[0] << endl;
    try {
        cout << "char 50 = " << f[50] << endl;
    }
    catch (ios::failure) {
        cout << "caught ios::failure" << endl;
    }
    try {
        cout << "char -1 = " << f[-1] << endl;
    }
    catch (ios::failure) {
        cout << "caught ios::failure" << endl;
    }
}



/* Output */

/*
$g++ -o main *.cpp
$main
char 5 = f
char 10 = k
char 0 = a
char 50 = caught ios::failure
char -1 = caught ios::failure
 */