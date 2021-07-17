#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

class Node {                                            /* Declare Node as a calss */
    public:
        int value;
        class Node *left_Node;                          /* The ptr points to left child tree */
        class Node *right_Node;                         /* The ptr points to right child tree */
};

typedef class Node TreeNode;                            /* Define a new TreeNode */
typedef TreeNode *BinaryTree;                           /* Define a new *BinaryTree as a ptr */
BinaryTree rootNode;
BinaryTree rootNode2;

void Add_Node_To_Tree(int value) {                      /* Add value into the binary tree */
    BinaryTree currentNode;
    BinaryTree newnode;
    int flag = 0;                                       /* Record whether insert a new node */
    newnode=(BinaryTree) new TreeNode;

    newnode->value=value;
    newnode->left_Node=NULL;
    newnode->right_Node=NULL;

    if (rootNode==NULL) {
        rootNode=newnode;
    } else {
        currentNode=rootNode;
        while (!flag) {
            if (value<currentNode->value) {             /* left child tree*/
                if (currentNode->left_Node==NULL) {
                    currentNode->left_Node=newnode;
                    flag = 1;                           /* Set flag = 1 */
                } else {
                    currentNode=currentNode->left_Node; 
                }
            } else {                                    /* right child tree*/
                if (currentNode->right_Node==NULL) {
                    currentNode->right_Node=newnode;
                    flag = 1;
                } else {
                    currentNode=currentNode->right_Node;
                }
            }
        }
    }
}


BinaryTree create(char sequence[100], int index, int ArraySize) {
    BinaryTree tempNode;                                /* Set a tempNode */       
    if (sequence[index]==0 ||index >= ArraySize) {
        return NULL;
    } else { 
        tempNode=(BinaryTree) new TreeNode;
        tempNode->value=(int)sequence[index];
        tempNode->left_Node=NULL;
        tempNode->right_Node=NULL;
        tempNode->left_Node = create(sequence, 2*index, ArraySize);
        tempNode->right_Node = create(sequence, 2*index+1, ArraySize);
        return tempNode;                                /* return tempNode */
    }
}

void preOrder(BinaryTree node) {                        /* pre-order traversal */
    if (node != NULL) {
        cout<<setw(1)<<(char)node->value;
        preOrder(node->left_Node);  
        preOrder(node->right_Node); 
    }
}


void inOrder(BinaryTree node) {                         /* in-order traversal */
    if (node != NULL) {
        inOrder(node->left_Node);  
        cout<<setw(1)<<(char)node->value;
        inOrder(node->right_Node); 
    }
}

void postOrder(BinaryTree node)  {                      /* post-order traversal */
    if (node != NULL) {
        postOrder(node->left_Node);  
        postOrder(node->right_Node); 
        cout<<setw(1)<<(char)node->value;
      }
}

int condition(char oprator, int num1, int num2) {       /* Expression for switch-case computation */
    switch (oprator) {
        case '*': return (num1 * num2); 
        case '/': return (num1 / num2); 
        case '+': return (num1 + num2); 
        case '-': return (num1 - num2); 
        case '%': return (num1 % num2); 
    }
    return -1;
}

int answer(BinaryTree node) {                           /* Compute values of the binary tree with recursion */
    int firstnumber = 0;       
    int secondnumber = 0;      

    if (node->left_Node == NULL && node->right_Node == NULL) {
        return node->value-48;
    } else {
        firstnumber = answer(node->left_Node);
        secondnumber = answer(node->right_Node); 
        return condition((char)node->value, firstnumber, secondnumber);
    }
}

int main(void) {
    char information1[] = {' ','+','*','%','6','3','9','5' }; 
    char information2[] = {' ','+','+','+','*','%','/','*',
                           '1','2','3','2','6','3','2','2' }; 
    rootNode=(BinaryTree)new TreeNode;                      
    rootNode2=(BinaryTree)new TreeNode;                     

    rootNode = create(information1, 1, 8);
    cout<<"====Binary tree numerical operation case 1: ===="<<endl;
    cout<<"============================================================="<<endl;
    cout<<"===Change it to the in-order expression===:  ";
    inOrder(rootNode);     
    cout<<endl<<"===Change it to the pre-order expression===:  ";
    preOrder(rootNode);    
    cout<<endl<<"===Change it to the post-order expression===:  ";
    postOrder(rootNode);   

    cout<<endl<<"Binary tree result: ";
    cout<<setw(1)<<answer(rootNode);

    rootNode2 = create(information2,1,16);
    cout<<endl;
    cout<<endl;
    cout<<"====Binary tree numerical operation case 2: ===="<<endl;
    cout<<"=============================================================="<<endl;
    cout<<"===Change it to the in-order expression===:  ";
    inOrder(rootNode2);     
    cout<<endl<<"===Change it to the pre-order expression===:  ";
    preOrder(rootNode2);    
    cout<<endl<<"===Change it to the post-order expression===:  ";
    postOrder(rootNode2);   

    cout<<endl<<"Binary Tree Result: ";
    cout<<setw(1)<<answer(rootNode2); 
    cout<<endl;
    
    delete rootNode;
    delete rootNode2;
    return 0;
}



/* Output */

/* 
====Binary tree numerical operation case 1: ====
=============================================================
===Change it to the in-order expression===:  6*3+9%5
===Change it to the pre-order expression===:  +*63%95
===Change it to the post-order expression===:  63*95%+
Binary Tree Result: 22

====Binary tree numerical operation case 2: ====
==============================================================
===Change it to the in-order expression===:  1*2+3%2+6/3+2*2
===Change it to the pre-order expression===:  ++*12%32+/63*22
===Change it to the post-order expression===:  12*32%+63/22*++
Binary Tree Result: 9
 */