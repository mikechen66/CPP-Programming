
/* Self-defined data type */

#include<iostream>
#include<string>
using namespace std;

typedef double weight, tall; //Self-defined data type

struct student{ //Give the elements of the struct             
    int number;
    int score;
    string name; 
    weight w;   //Declare the sefl-defined data type
    tall t;
};

int main(void){
    student s[4] = {{1,100,"Mike Lee"},  //Declare and initialize the struct array
                    {2,98,"Jeff Dean"},
                    {3,95,"Steve jobs"},
                    {4,92,"Dennis Ritchie"}}; 
    cout<<"Health Check Sheet:"<<endl;
    for (int j=0; j<4; j++){
        cout<<s[j].name<<"\t["<<j+1<<"]: Height=";
        cin>>s[j].t;
        cout<<"\t      Weight=";
        cin>>s[j].w;
    }
    return 0;
}