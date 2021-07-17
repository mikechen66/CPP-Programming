#include <iostream> 
#include <cstdlib>  
using namespace std;
                                        
int main() {
    /* Declare a pointer (targeted at integer) with inserting 50 */
    int *intptr = new int(50);
    /* Declare a pointer (targeted at float) withouting designating value */
    float *floatptr = new float;
    cout << "intptr is pointed to the value��" << *intptr << "\n\n";
    *floatptr = 0.5;
    cout << "floatptr is pointed to the value��" << *floatptr << "\n\n";

    delete intptr;
    delete floatptr;

    return 0;
}



/* Output */

/* 
$g++ -o main *.cpp
$main
intptr is pointed to the value��50

floatptr is pointed to the value��0.5
 */