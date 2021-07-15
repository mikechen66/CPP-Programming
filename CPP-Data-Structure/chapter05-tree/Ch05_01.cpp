
/* A simple example of binary tree */

#include <iostream>
using namespace std;

class tree {  
    public:
    int data;                              /* the data of the node */
    class tree *left, *right;              /* the left and right pointer of the node */
};

typedef class tree node;
typedef node *btree;
void Inorder(btree ptr);

int main(void) {  
    int i,level;
    int data[]={0,6,3,5,9,7,8,4,2};        /* Give the original array */
    int btree[16]={0};                     /* the array saves a binary tree */
    cout<<"Original array: "<<endl;
    for (i=1; i<9; i++)
        cout<<"["<<data[i]<<"] ";

    cout<<endl;

    for (i=1; i<9; i++) {  
        for (level=1; btree[level]!=0;) {  /* compare the root node and the elements of the array */
            if (data[i]>btree[level])         
                level=level*2+1;
            else  
                level=level*2;
        }         
        btree[level]=data[i];              /* Put the elements of the array into the binary tree */
    }
    cout<<"Output the binary tree: "<<endl;

    for (i=1; i<16; i++)
        cout<<"["<<btree[i]<<"] ";
    cout<<endl;
    return 0;
}

void Inorder(btree ptr) {                  /* Execute the in-order traversal */
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