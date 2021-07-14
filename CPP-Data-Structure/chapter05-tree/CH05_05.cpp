#include <iostream>
#include <stdlib.h>
using namespace std;

struct tree{  
    int data;
    struct tree *left,*right;
};

typedef struct tree node;
typedef node *btree;

btree creat_tree(btree root,int val) {  
    btree newnode,current,backup;
    newnode=(btree)malloc(sizeof(node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;

    if (root==NULL) {  
        root=newnode;
        return root;
    } else {  
        for (current=root;current!=NULL;) {  
            backup=current;
            if (current->data > val)
                current=current->left;
            else
                current=current->right;
        }
        if (backup->data >val)
            backup->left=newnode;
        else
            backup->right=newnode;
    }

    return root;
}

btree search(btree ptr,int val) {  
    while (1) {  
        if (ptr==NULL)                        
            return NULL;
        if (ptr->data==val)      
            return ptr;
        else if (ptr->data > val)    
            ptr=ptr->left;
        else
            ptr=ptr->right;
    }   
}
void inorder(btree ptr) {  
    if (ptr!=NULL) {  
        inorder(ptr->left);
        cout<<"["<<ptr->data<<"]";
        inorder(ptr->right);
    }
}

int main() {  
    int i, data, arr[]={7,1,4,2,8,13,12,11,15,9,5};
    btree ptr=NULL;
    cout<<"[The original array]"<<endl;
    for (i=0;i<11;i++) {  
        ptr=creat_tree(ptr,arr[i]);  
        cout<<"["<<arr[i]<<"] ";
    }
    cout<<endl;
    cout<<"Please input the pair of key-value: "<<endl;
    cin>>data;
    if ((search(ptr,data))!=NULL) {
        cout<<"The binary tree includes the node!-"<<data<<endl;
    } else {
        ptr=creat_tree(ptr,data);  
        inorder(ptr);
    }
    
    return 0;
}



/* Output */

/* 
[The original array]
[7] [1] [4] [2] [8] [13] [12] [11] [15] [9] [5] 
Please input the pair of key-value: 
21 3
[1][2][4][5][7][8][9][11][12][13][15][21]
 */