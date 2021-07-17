
/* A scenario of the binary tree */

#include <iostream>
#include<stdlib.h>
using namespace std;

struct tree {  
    int data;
    struct tree *left,*right;
};

typedef struct tree node;
typedef node *btree;                                        /* Define *btree node type */

btree creat_tree(btree root, int val) {  
    btree newnode, current, backup;
    newnode=(btree)malloc(sizeof(node));                    /* Assign memory sapce for the node */
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    if (root==NULL) {  
        root = newnode;
        return root;
    } else {  
        for (current=root; current!=NULL;) {  
            backup = current;
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

btree search(btree ptr, int val) {                          /* Search the btree */
    int i = 1;                    
    while (1) {  
        if (ptr==NULL)            
            return NULL;
        if (ptr->data==val) {                               /* The node's value is equal to val*/
            cout<<"Search for "<<i<<"times totally"<<endl;
            return ptr;
        } else if (ptr->data > val) {                       /* The node's value is larger than val*/
            ptr=ptr->left;
        } else {
            ptr=ptr->right;
        }
        i++;
    }   
}

int main() {  
    int i, data, arr[]={7,1,4,2,8,13,12,11,15,9,5};
    btree ptr = NULL;
    cout<<"[The original array]"<<endl;

    for (i=0; i<11; i++) {  
        ptr=creat_tree(ptr, arr[i]);                        /* Create the binary tree */
        cout<<"["<<arr[i]<<"] ";
    }

    cout<<endl;
    cout<<"Please iput the value for search: "<<endl;
    cin>>data;

    if ((search(ptr, data)) !=NULL)                         /* search for the binary tree */
        cout<<"It is the value you search ["<<data<<" ] Find out it!!"<<endl;
    else
        cout<<"Do not find out it!!"<<endl;
    
    return 0;
}



/* Output */

/*
[The original array]
[7] [1] [4] [2] [8] [13] [12] [11] [15] [9] [5] 
Please iput the value for search: 
31
Do not find out it!!
 */