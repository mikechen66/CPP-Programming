
/* Traverse the binary tree with pre-order, in-order and post-order */ 

#include <iostream>
#include <iomanip>
using namespace std;

class tree {  
    public :
    int data; 
    class tree *left,*right; 
};

typedef class tree node;
typedef node *btree;
btree creat_tree(btree,int);
void pre(btree);
void in(btree);
void post(btree);

int main(void) {  
    int arr[]={7,4,1,5,16,8,11,12,15,9,2};              /* The original aarray */
    btree ptr=NULL; 
    cout<<"[The original array]"<<endl;
    for (int i=0; i<11; i++) {  
        ptr = creat_tree(ptr, arr[i]);
        cout<<"["<<setw(2)<<arr[i]<<"] ";
    }

    cout<<endl;
    cout<<"[The binary tree]"<<endl;
    cout<<"The result of pre-order traversal: "<<endl;  /* Print the result of pre-order */
    pre(ptr);
    cout<<endl;
    cout<<"The result of in-order traversal£º"<<endl;   /* the in-order loop */
    in(ptr);
    cout<<endl;
    cout<<"The result of post-order traversal£º"<<endl; /* the post-order loop */
    post(ptr);
    cout<<endl;
    return 0;
}

btree creat_tree(btree root, int val) {                 /* Create the ninary tree */
    btree newnode,current,backup;                       /* newnode saves the array */
    newnode = new node; 
    newnode->data=val;  
    newnode->left=NULL;
    newnode->right=NULL;
    if (root==NULL) {                                   /* If empty, return newnode as root */
        root=newnode;
        return root;
    } else {                                            /* Otherwise, create a binary tree */
        for (current=root; current!=NULL;) {            /* current copies root */
            backup=current;                             /* Retain the parent node */
            if (current->data > val)
                current=current->left;
            else
                current=current->right;
        }
        if (backup->data >val)                          /* Connect newnode and root */
            backup->left=newnode;
        else
            backup->right=newnode;
    }
    return root;                            
}

void pre(btree ptr) {  
    if (ptr != NULL) {  
        cout<<"["<<setw(2)<<ptr->data<<"] ";
        pre(ptr->left);
        pre(ptr->right);
    }
}

void in(btree ptr) {  
    if (ptr != NULL) {  
        in(ptr->left);
        cout<<"["<<setw(2)<<ptr->data<<"] ";
        in(ptr->right);
    }
}

void post(btree ptr) {  
    if (ptr != NULL) {  
        post(ptr->left);
        post(ptr->right);
        cout<<"["<<setw(2)<<ptr->data<<"] ";
    }
}



/* Output */

/*
[The original array]
[ 7] [ 4] [ 1] [ 5] [16] [ 8] [11] [12] [15] [ 9] [ 2] 
[The binary tree]
The result of pre-order traversal: 
[ 7] [ 4] [ 1] [ 2] [ 5] [16] [ 8] [11] [ 9] [12] [15] 
The result of in-order traversal£º
[ 1] [ 2] [ 4] [ 5] [ 7] [ 8] [ 9] [11] [12] [15] [16] 
The result of post-order traversal£º
[ 2] [ 1] [ 5] [ 4] [ 9] [15] [12] [11] [ 8] [16] [ 7] 
 */