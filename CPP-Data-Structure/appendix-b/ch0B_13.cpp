
/* ����:ch0B_13.cpp
 * ˵��:�ṹ�����Ӧ�� 
 */

#include<iostream>
#include<string>
using namespace std;
//�ṹ����
struct student{              
    int number;
    int score;
    string name; 
}; 
int main(void){
    student s[4]={{1,100,"����ʫ"},     //�����ṹ���鲢��ʼ�� 
                  {2,98,"������"},
                  {3,95,"��ǫ"},
                  {4,92,"лܲ��"},
        }; 
    for(int i=0; i<4; i++){
        cout<<"����:"<<s[i].number<<endl;
        cout<<"����:"<<s[i].name<<"\t"<<"�ɼ�:"<<s[i].score<<endl;
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
