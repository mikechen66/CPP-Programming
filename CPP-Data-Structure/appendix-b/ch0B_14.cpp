/* 范例:ch0B_14.cpp
 * 说明:自定义数据类型 
 */

#include<iostream>
#include<string>
using namespace std;

typedef double weight, tall; //自定义数据类型
//结构内容
struct student{              
    int number;
    int score;
    string name; 
    weight w;   //声明自定义数据类型
    tall t;
};

int main(void){
    student s[4]={{1,100,"李奕诗"},    //声明结构数组并初始化 
                  {2,98,"李奕萱"},
                  {3,95,"罗谦"},
                  {4,92,"谢懿柔"}}; 
    cout<<"身体检查表:"<<endl;
    for(int j=0; j<4; j++){
        cout<<s[j].name<<"\t["<<j+1<<"]号 身高=";
        cin>>s[j].t;
        cout<<"\t      体重=";
        cin>>s[j].w;
    }
    return 0;
}

/* Self-defined data type */

#include<iostream>
#include<string>
using namespace std;

typedef double weight, tall; //Self defined data type

struct student{ //the elements of the struct             
    int number;
    int score;
    string name; 
    weight w;   //Declare the sefl-defined data type
    tall t;
};

int main(void){
    student s[4]={{1,100,"Mike Lee"},  //Declare and initialize the struct array
                  {2,98,"Jeff Dean"},
                  {3,95,"Steve jobs"},
                  {4,92,"Dennis Ritchie"}}; 
    cout<<"Health Check Sheet:"<<endl;
    for(int j=0; j<4; j++){
        cout<<s[j].name<<"\t["<<j+1<<"]: Height=";
        cin>>s[j].t;
        cout<<"\t      Weight=";
        cin>>s[j].w;
    }
    return 0;
}


/* Output */

/*
$g++ -o main *.cpp
$main
Health Check Sheet:
Mike Lee    [1]: Height=          Weight=Jeff Dean  [2]: Height=          Weight=Steve jobs [3]: Height=          Weight=Dennis Ritchie [4]: Height=          Weight=
 */