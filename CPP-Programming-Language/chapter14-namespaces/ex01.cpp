#include <iostream>
#include <cstdlib>

namespace namespaces {
    template<class Tfunc, class Tset> class STC {
        // Made private to prevent instantiation of this template.
        STC();
    };

    template<class Tfunc,class Tset> class STC<Tfunc*,Tset*> {
        Tfunc* old;
        Tset* set;
    public:
        STC(Tset* set, Tfunc* f) : set(set), old(set(f)) { }
        ~STC() { set(old); }
    };
}

void f() {
    std::cout << "I got called!" << std::endl;
    abort();
}

int main() {
    using namespace std;
    using namespace namespaces;

    typedef std::new_handler (*SetNewHandler)(new_handler);
    STC<new_handler,SetNewHandler> stc(std::set_new_handler, f);

    for(;;) {
        void* p = new char[1000000000];
    }

    return 0;
}



/* Output */

/*
I got calles
 */