 
 /* ����:ch0B_16.cpp
  * ˵��:�������������Ӧ�� 
  */

#include<iostream>
// #include<string>
using namespace std;
class student{   // student is base class
    int num;
    char name[20]; 
    public :
    void setdata(){
        cout<<"����:";cin>>num;
        cout<<"����:";cin>>name;
    } 
    void show(){
        cout<<name<<"������=\t"<<num<<endl; 
    } 
};
class s_health:public student{ //s_healthΪ������
    //û�ж��������� 
}; 
int main(void){
    s_health sh[5]; 
    for(int i=1; i<5; i++){
        sh[i].setdata();//ʹ�û���ķ��� 
    }cout<<endl;
    for(int j=1; j<5; j++){
        sh[j].show();//ʹ�û���ķ���
    }
    cout<<endl;
    return 0;
}

 
 /* Derived class's declaration and usage */

#include<iostream>
// #include<string>
using namespace std;
class student{   // student is base class
    int num;
    char name[20]; 
    public :
    void setdata(){
        cout<<"Seat_No:";cin>>num;
        cout<<"Name:";cin>>name;
    } 
    void show(){
        cout<<name<<"Seat_NO=\t"<<num<<endl; 
    } 
};

class s_health:public student{ //s_health is a derived class
}; 
int main(void){
    s_health sh[5]; 
    for(int i=1; i<5; i++){
        sh[i].setdata(); //Apply the base class's method
    }cout<<endl;
    for(int j=1; j<5; j++){
        sh[j].show();    //Apply the base class's method
    }
    cout<<endl;
    return 0;
}
