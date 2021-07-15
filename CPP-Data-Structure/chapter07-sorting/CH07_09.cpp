
/* Merging Sort: before merging: data1.txt,data2.txt£¬after merging: data.txt */

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

void merge(ofstream& fp, ifstream& fp1, ifstream& fp2) {
    char n1,n2;
    char txt1[40];
    char txt2[40];
    fp1>>n1;
    fp2>>n2;
    while(fp1.eof()==0 && fp2.eof()==0) {  
        if (n1 <= n2) {  
            fp.put(n1);   
            fp1>>n1;    
        } else {  
            fp.put(n2);
            fp2>>n2;  
        }
    }

    if (fp1.eof()) { 
        while (!fp2.eof()) {  
            fp2>>n2;
            fp.put(n2);
        }
    } else if (fp2.eof()) { 
        while(!fp1.eof()) {             
            fp1>>n1;
            fp.put(n1);
        }
    }    
}

int main(void) {  
    char txt[40];;
    ofstream fp;
    ifstream fp1,fp2;
    ifstream f,f1,f2;
    fp.open("data.txt",ios::out);
    fp1.open("data1.txt",ios::in);
    fp2.open("data2.txt",ios::in);

    if (!fp.is_open()) {
        cout<<"Fails while opening a fule"<<endl;
    } else if (!fp1.is_open()) {
        cout<<"Fails to open the data file 1"<<endl;
    } else if (!fp2.is_open()) {
        cout<<"Fails to open the data file 2"<<endl;
    } else {  
        cout<<"Data sorting......"<<endl;
        merge(fp,fp1,fp2);
        cout<<"Complete the data processing!!"<<endl;
    }

    fp.close();
    fp1.close();
    fp2.close();
    cout<<"data1.txt content£º"<<endl;
    f1.open("data1.txt",ios::in);

    while (!f1.eof()) {  
        f1>>txt;
        cout<<txt<<endl;
    }

    cout<<"data2.txt content: "<<endl;
    f2.open("data2.txt",ios::in);

    while (!f2.eof()) {  
        f2>>txt;
        cout<<txt<<endl;
    }

    cout<<"data.txt content£º"<<endl;
    f.open("data.txt",ios::in);

    while (!f.eof()) {  
        f>>txt;
        cout<<txt<<endl;
    }

    cout<<endl;
    f.close();
    f1.close();
    f2.close();

    return 0;
}
