
/* ����:ch0B_15.cpp
 * ˵��:���������Ӧ�� 
 */

#include<iostream>
#include<ctime>
using namespace std;
class myclock{
    public :            //����Ϊ���÷���Ȩ�� 
    int sec,min,time;   //���ݳ�Ա 
    int setclock(int t,int m,int s){    //��Ա���� 
        sec=s;
        min=m;
        time=t;
    }
}; 

int main(void){
    myclock clock1; //����һ������ 
    cout<<"����ʱ��="<<__TIME__<<endl;
    cout<<"����������ʱ��:";
    clock1.setclock(6,50,32);       //ѡ�ó�Ա���� 
    cout<<clock1.time<<":"<<clock1.min<<":"<<clock1.sec<<endl;  //ѡ�����ݳ�Ա 
    cout<<"���ӽ�����"<<clock1.time<<":"<<clock1.min<<":"<<clock1.sec<<"����"<<endl;
    return 0;
}


/* Declaration and usage of class */

#include<iostream>
#include<ctime>
using namespace std;

class myclock{
    public :            //����Ϊ���÷���Ȩ�� 
    int sec,min,time;   //���ݳ�Ա 
    int setclock(int t,int m,int s){    //��Ա���� 
        sec=s;
        min=m;
        time=t;
    }
}; 

int main(void){
    myclock clock1; //����һ������ 
    cout<<"Current time = "<<__TIME__<<endl;
    cout<<"Please set ringing time: ";
    clock1.setclock(6,50,32);       //ѡ�ó�Ա���� 
    cout<<clock1.time<<":"<<clock1.min<<":"<<clock1.sec<<endl;  //ѡ�����ݳ�Ա 
    cout<<"The alarm clock will ring on "<<clock1.time<<":"<<clock1.min<<":"<<clock1.sec<<endl;
    return 0;
}


/* Output */

/*
$g++ -o main *.cpp
$main
Current time=15:14:47
Please set ringing time: 6:50:32
The alarm clock will ring on 6:50:32
 */