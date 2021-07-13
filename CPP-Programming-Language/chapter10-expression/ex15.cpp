#include <iostream>

class AppInit {
public:
    AppInit();
    ~AppInit();
} oAppInit;

AppInit::AppInit() {
    std::cout << "Initialize" << std::endl;
}

AppInit::~AppInit() {
    std::cout << "Clean up" << std::endl;
}

int main() {
     std::cout << "Hello, world!\n";
}



/* Output */

/*
$g++ -o main *.cpp
$main
Initialize
Hello, world!
Clean up
 */