
/* Create a binary tree */

#include <iostream>
#include <cstdlib>
#include <iomanip>

#define ArraySize 10
using namespace std;

class Node {
    public:
    int value;
    struct Node *left_Node;
    struct Node *right_Node;
};

typedef class Node TreeNode; 
typedef TreeNode *BinaryTree;
BinaryTree rootNode;


void Add_Node_To_Tree(int value) {
    BinaryTree currentNode;
    BinaryTree newnode;
    int flag=0;
    newnode=(BinaryTree) malloc(sizeof(TreeNode));

    newnode->value=value;
    newnode->left_Node=NULL;
    newnode->right_Node=NULL;

    if (rootNode==NULL) {
          rootNode=newnode;
    } else {
        currentNode=rootNode;//指定一个指针指向根节点
        while (!flag) {
            if (value<currentNode->value) { 
                if (currentNode->left_Node==NULL) {
                    currentNode->left_Node=newnode;
                    flag=1;
                } else {
                    currentNode=currentNode->left_Node;
                }
            } else { 
                if (currentNode->right_Node==NULL) {
                    currentNode->right_Node=newnode;
                    flag=1;
                } else {
                    currentNode=currentNode->right_Node;
                }
            }
        }
    }
}

int main(void) {
    int tempdata;
    int content[ArraySize];
    int i=0;
    rootNode=(BinaryTree) malloc(sizeof(TreeNode));
    rootNode=NULL;
    cout<<"Please input 10 data items consecutively: "<<endl;
    for (i=0; i<ArraySize; i++) {
        cout<<"Please input the "<<setw(1)<<(i+1)<<"th data item: ";
        cin>>tempdata;       
        content[i]=tempdata;
    }
    for (i=0; i<ArraySize; i++) {
         Add_Node_To_Tree(content[i]);
    }

    cout<<"Create the binary tree with the link";
    cout<<endl;  

    return 0;
}



/* Output */

/*
Please input 10 data items consecutively: 
Please input the 1th data item: 1
Please input the 2th data item: 3
Please input the 3th data item: 5
Please input the 4th data item: 7
Please input the 5th data item: 9
Please input the 6th data item: 11
Please input the 7th data item: 13
Please input the 8th data item: 15
Please input the 9th data item: 17
Please input the 10th data item: 19
Create the binary tree with the link
 */