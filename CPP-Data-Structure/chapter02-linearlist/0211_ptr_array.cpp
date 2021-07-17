#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    char *name[4] = { "Justinian", "Momo", "Becky", "Bush" };   
    char name1[4][10] = { "Justinian", "Momo", "Becky", "Bush" }; 
    int i;
    cout<<"---------- Storage method of 1D pointer array --------------"<<endl;
    for ( i = 0; i < 4; i++ ) {
        cout<<"name["<<i<<"] = \""<<name[i]<<"\"\t";
        cout<<"Occupied address: "<<(int *)name[i]<<endl;  
    }
    cout<<"------------ Storage method of 2D string array--------------"<<endl;
    for ( i = 0; i < 4; i++ ) {
        cout<<"name1["<<i<<"] = \""<<name1[i]<<"\"\t";
         cout<<"Occupied address: "<<(int *)name1[i]<<endl; 
    }    
    return 0;
}


/* Output */

/*
main.cpp:7:60: warning: ISO C++ forbids converting a string constant to ¡®char*¡¯ [-Wwrite-strings]
     char *name[4] = { "Justinian", "Momo", "Becky", "Bush" };
                                                            ^
main.cpp:7:60: warning: ISO C++ forbids converting a string constant to ¡®char*¡¯ [-Wwrite-strings]
main.cpp:7:60: warning: ISO C++ forbids converting a string constant to ¡®char*¡¯ [-Wwrite-strings]
main.cpp:7:60: warning: ISO C++ forbids converting a string constant to ¡®char*¡¯ [-Wwrite-strings]
---------- Storage method of 1D pointer array --------------
name[0] = "Justinian"   Occupied address: 0x400bd9
name[1] = "Momo"        Occupied address: 0x400be3
name[2] = "Becky"       Occupied address: 0x400be8
name[3] = "Bush"        Occupied address: 0x400bee
------------ Storage method of 2D string array--------------
name1[0] = "Justinian"  Occupied address: 0x7ffeb5f2c450
name1[1] = "Momo"       Occupied address: 0x7ffeb5f2c45a
name1[2] = "Becky"      Occupied address: 0x7ffeb5f2c464
name1[3] = "Bush"       Occupied address: 0x7ffeb5f2c46e
 */