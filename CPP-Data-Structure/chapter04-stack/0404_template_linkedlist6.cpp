
/* Input an digit */

#include <iostream>
#include <cstdlib>
using namespace std;

template <class Type>   

struct Node {
    Type data;    
    Node* next;
};

template <class Type>

class LinkedList {
    private:
        Node<Type>* first;                  /* The ptr points to the first node */
    public:
        LinkedList() {
            first = NULL;
        }
    void addNode(Type data); 
    void display();             
};

template<class Type>

void LinkedList<Type>::addNode(Type data) {
    Node<Type>* newNode = new Node<Type>;   /* Addd a new node */
    newNode->data = data;           
    newNode->next = first;      
    first = newNode;            
}

template<class Type>

void LinkedList<Type>::display() {
    Node<Type>* currentNode = first;        /* Show the data item from the 1st node */
    while (currentNode != NULL){
        cout << currentNode->data << " -> ";
    currentNode = currentNode->next;
    }
}

int main() {
    LinkedList<double> dblList;     
    double num;                 
    char ch;   

    do {
        cout << endl <<"Please input a digit:  ";
        cin >> num;
        dblList.addNode( num );
        cout << "Continue inputting(y / n)?";
        cin >> ch;
    } while(ch != 'n');

    cout << endl;
    dblList.display();                       /* Show all the data */ 
    cout << endl << endl;
    return 0;
}


/* Output */

/*

Please input a digit:  8
Continue inputting(y / n)?9

Please input a digit:  9
Continue inputting(y / n)?10

Please input a digit:  Continue inputting(y / n)?20

Please input a digit:  Continue inputting(y / n)?21

Please input a digit:  Continue inputting(y / n)?22

Please input a digit:  Continue inputting(y / n)?36

Please input a digit:  Continue inputting(y / n)?39

Please input a digit:  Continue inputting(y / n)?42

Please input a digit:  Continue inputting(y / n)?n

2 -> 9 -> 6 -> 2 -> 1 -> 0 -> 0 -> 9 -> 8 -> 
 */