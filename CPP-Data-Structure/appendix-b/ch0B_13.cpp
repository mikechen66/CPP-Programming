
/* 范例:ch0B_13.cpp
 * 说明:结构数组的应用 
 */

#include<iostream>
#include<string>
using namespace std;
//结构内容
struct student{              
    int number;
    int score;
    string name; 
}; 
int main(void){
    student s[4]={{1,100,"李奕诗"},     //声明结构数组并初始化 
                  {2,98,"李奕萱"},
                  {3,95,"罗谦"},
                  {4,92,"谢懿柔"},
        }; 
    for(int i=0; i<4; i++){
        cout<<"座号:"<<s[i].number<<endl;
        cout<<"姓名:"<<s[i].name<<"\t"<<"成绩:"<<s[i].score<<endl;
    }
    return 0;
}


#include<iostream>
#include<string>
using namespace std;

struct student{                        // the elements of the structs      
    int number;
    int score;
    string name; 
}; 
int main(void){
    student s[4]={{1, 100, "Mike Luo"},     //Declare and initialize the struct array
                  {2, 98,  "Jeff Dean"},
                  {3, 95,  "Steve Jobs"},
                  {4, 92,  "Dennis Ritchie"},
        }; 
    for(int i=0; i<4; i++){
        cout<<"No.:"<<s[i].number<<endl;
        cout<<"Name:"<<s[i].name<<"\t"<<"Score:"<<s[i].score<<endl;
    }
    return 0;
}
