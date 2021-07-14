#include <iostream>
using namespace std;

class tree {  
    public:
    int data; 
    class tree *left,*right; 
};

typedef class tree node;
typedef node *btree;
void Inorder(btree ptr);

int main(void) {  
    int i,level;
    int data[]={0,6,3,5,9,7,8,4,2}; 
    int btree[16]={0}; 
    cout<<"Original array: "<<endl;
    for (i=1; i<9; i++)
        cout<<"["<<data[i]<<"] ";

    cout<<endl;

    for (i=1; i<9; i++) {  
        for (level=1; btree[level]!=0;) {  
            if (data[i]>btree[level]) 
                level=level*2+1;
            else  
                level=level*2;
        }         
        btree[level]=data[i];       
    }
    cout<<"Binary tree: "<<endl;

    for (i=1;i<16;i++)
        cout<<"["<<btree[i]<<"] ";
    cout<<endl;
    return 0;
}

void Inorder(btree ptr) {
    if (ptr!=NULL) {
        Inorder(ptr->left); 
        cout<<"["<<ptr->data<<"]"; 
        Inorder(ptr->right); 
    }
}


/* Output */

/*
Original array: 
[6] [3] [5] [9] [7] [8] [4] [2] 
Binary tree: 
[6] [3] [9] [2] [5] [7] [0] [0] [0] [4] [0] [0] [8] [0] [0] 
 */