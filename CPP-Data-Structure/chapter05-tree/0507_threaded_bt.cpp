
/* Create a thread binary tree */

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

class Node {
    public:
    int value;
    int left_Thread;
    int right_Thread;
    class Node *left_Node;
    class Node *right_Node;
};

typedef class Node ThreadNode;
typedef ThreadNode *ThreadBinaryTree;
ThreadBinaryTree rootNode;

void Add_Node_To_Tree(int value) {        /* Add value into ThreadBinaryTree */
    ThreadBinaryTree newnode;              
    ThreadBinaryTree previous;
    newnode=new ThreadNode;     
    newnode->value=value;
    newnode->left_Thread=0;
    newnode->right_Thread=0;
    newnode->left_Node=NULL;
    newnode->right_Node=NULL;
    ThreadBinaryTree current;
    ThreadBinaryTree parent;
    previous=new ThreadNode;
    previous->value=value;
    previous->left_Thread=0;
    previous->right_Thread=0;
    previous->left_Node=NULL;
    previous->right_Node=NULL;
    int pos;

    if (rootNode==NULL) {                 /* Set a starting node */
        rootNode=newnode;
        rootNode->left_Node=rootNode;
        rootNode->right_Node=NULL;
        rootNode->left_Thread=0;
        rootNode->right_Thread=1;
        return;
    }

    current=rootNode->right_Node;

    if (current==NULL) {                 /* Set the node the starting node points to */                 
        rootNode->right_Node=newnode;
        newnode->left_Node=rootNode;
        newnode->right_Node=rootNode;
        return;
    }

    parent=rootNode;                     /* parent is a starting node */
    pos=0; 
      
    while (current!=NULL) {
        if (current->value>value) {
            if (pos!=-1) {
                pos=-1;
                previous = parent;
            }

            parent = current;

            if (current->left_Thread==1)
                current=current->left_Node;
            else
               current = NULL;
        } else {
            if (pos!=1) {
                pos=1;
                previous=parent;
            }

            parent = current;

            if (current->right_Thread==1) {
               current=current->right_Node;
            } else {
               current = NULL;
            }
        }
    }

    if (parent->value>value) {
        parent->left_Thread=1;
        parent->left_Node=newnode;
        newnode->left_Node=previous;
        newnode->right_Node=parent;
    } else {
        parent->right_Thread=1;
        parent->right_Node=newnode;
        newnode->left_Node=parent;
        newnode->right_Node=previous;
    }
    return;
}


void trace() {                          /* Traverse ThreadBinaryTree */
    ThreadBinaryTree tempNode;
    tempNode=rootNode;
    do {
        if (tempNode->right_Thread==0) {
            tempNode=tempNode->right_Node;
        } else {
            tempNode=tempNode->right_Node;
            while (tempNode->left_Thread!=0)
               tempNode=tempNode->left_Node;
        }
        if (tempNode!=rootNode) {
            cout<<"["<<setw(3)<<tempNode->value<<"]"<<endl;
        }
    } while (tempNode!=rootNode);
} 

int main(void) {
    int i = 0;
    int array_size = 11;
    cout<<"In-order sorting for a better effect"<<endl;
    cout<<"The first digit, as a starting node, is not sorted"<<endl;
    int data1[] = {0,10,20,30,100,399,453,43,237,373,655};
    for(i=0; i<array_size; i++)
        Add_Node_To_Tree(data1[i]);
    cout<<"===================================="<<endl;
    cout<<"Case 1 "<<endl;
    cout<<"The sorting result in order: "<<endl;
    trace();
    int data2[] = {0,101,118,87,12,765,65};
    rootNode = NULL;
    array_size = 7;
    for(i=0; i<array_size; i++)
        Add_Node_To_Tree(data2[i]);    
    cout<<"===================================="<<endl;
    cout<<"Case 2 "<<endl;
    cout<<"Get the sorting result in order: "<<endl;
    trace();
    cout<<endl;
    return 0;
}



/* Output */

/*
In-order sorting
The first digit is not sorted
====================================
Case 1 
The sorting result in order: 
[ 10]
[ 20]
[ 30]
[ 43]
[100]
[237]
[373]
[399]
[453]
[655]
====================================
Case 2 
The sorting result in order: 
[ 12]
[ 65]
[ 87]
[101]
[118]
[765]
 */