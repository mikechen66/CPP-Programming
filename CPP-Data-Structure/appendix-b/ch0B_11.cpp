
/* ����:ch0B_11.cpp
 * ˵��:���ָ������ĵ�ַ��ȡֵ 
 */

#include<iostream>
using namespace std;

int main(void){
    int x=100;
    int* y;
    y=&x;                              //��x�ĵ�ַ��ֵ��ָ�����y 
    cout<<"x="<<x<<endl;;
    cout<<"x's addres="<<&x<<endl;     //����&���x�ĵ�ַ 
    cout<<"y����¼="<<y<<endl;       
    cout<<"y��ָ���ַ��ֵ="<<*y<<endl;  //�����*������Ŵ�������ֵ
    return 0;
}


#include<iostream>
using namespace std;

int main(void){
    int x=100;
    int* y;
    y=&x;                              //Assign the address of x to the ptr variable y  
    cout<<"x="<<x<<endl;;
    cout<<"x's addres="<<&x<<endl;     //Use & to output the address of x 
    cout<<"y����¼="<<y<<endl;       
    cout<<"y��ָ���ַ��ֵ="<<*y<<endl;  //Add the operator of * */
    return 0;
}
