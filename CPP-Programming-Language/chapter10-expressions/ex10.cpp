#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>

namespace ch10
{
    using std::ostream;

    // A simple-minded, inefficient set class, specifically avoiding the use of std::set.
    // The values are stored in an ordered linked list.
    //
    // The only difference between this and the previous exercise is that instead of storing
    // integers, you can use any kind of type.
    template<class T> class IntSet
    {
        struct Node
        {
            T value;
            Node* next;
            Node(T value) : value(value), next(0) {}
            ~Node() { if(next) delete next; }
        };

        class DuplicateError {};

        Node* m_head;
        int m_count;

    public:
        IntSet() : m_head(new Node(0)), m_count(0) {}
        ~IntSet() { delete m_head; }
        int count() { return m_count; }
        void print(ostream& output) const;
        IntSet& insert(T n);
        IntSet* union_with(const IntSet& other) const;
        IntSet* intersect(const IntSet& other) const;
        IntSet* symmetric_difference(const IntSet& other) const;
    };

    template<class T> void IntSet<T>::print(ostream& output) const
    {
        Node* n = m_head->next;
        while(n)
        {
            output << n->value << " ";
            n = n->next;
        }
    }

    template<class T> IntSet<T>& IntSet<T>::insert(T n)
    {
        Node* cur = m_head;
        while(cur->next && cur->next->value < n) cur = cur->next;
        if(cur->next && cur->next->value == n) throw DuplicateError();
        Node* newNode = new Node(n);
        newNode->next = cur->next;
        cur->next = newNode;
        m_count++;
        return *this;
    }

    template<class T> IntSet<T>* IntSet<T>::union_with(const IntSet& other) const
    {
        IntSet<T>* set = new IntSet<T>();

        Node* a = this->m_head->next;
        Node* b = other.m_head->next;
        while(a && b)
        {
            if(a->value < b->value)
            {
                set->insert(a->value);
                a=a->next;
            }
            else if (b->value < a->value)
            {
                set->insert(b->value);
                b=b->next;
            }
            else
            {
                set->insert(a->value);
                a=a->next;
                b=b->next;
            }
        }
        while(a) { set->insert(a->value); a=a->next; }
        while(b) { set->insert(b->value); b=b->next; }

        return set;
    }

    template<class T> IntSet<T>* IntSet<T>::intersect(const IntSet<T>& other) const
    {
        IntSet<T>* set = new IntSet<T>();

        Node* a = this->m_head->next;
        Node* b = other.m_head->next;
        while(a && b)
        {
            if(a->value < b->value) { a=a->next; }
            else if (b->value < a->value) { b=b->next; }
            else { set->insert(a->value); a=a->next; b=b->next; }
        }
        return set;
    }

    template<class T> IntSet<T>* IntSet<T>::symmetric_difference(const IntSet<T>& other) const
    {
        IntSet<T>* set = new IntSet<T>();

        Node* a = this->m_head->next;
        Node* b = other.m_head->next;
        while(a && b)
        {
            if(a->value < b->value) { set->insert(a->value); a=a->next; }
            else if (b->value < a->value) { set->insert(b->value); b=b->next; }
            else { a=a->next; b=b->next; }
        }
        while(a) { set->insert(a->value); a=a->next; }
        while(b) { set->insert(b->value); b=b->next; }
        return set;
    }
}

int main(int argc, char* argv[])
{
    using namespace std;
    using namespace ch10;

    IntSet<int> set1;
    int i;
    for(i = 1; i < argc; i++)
    {
        if(argv[i][0] == '-') break;
        set1.insert(atoi(argv[i]));
    }

    IntSet<int> set2;
    i++;
    for(; i < argc; i++)
    {
        set2.insert(atoi(argv[i]));
    }

    cout << "Set 1: ";
    set1.print(cout);
    cout << endl;

    cout << "Set 2: ";
    set2.print(cout);
    cout << endl;

    cout << "Union: ";
    IntSet<int>* set = set1.union_with(set2);
    set->print(cout);
    cout << endl;
    delete set;

    cout << "intersection: ";
    set = set1.intersect(set2);
    set->print(cout);
    cout << endl;
    delete set;

    cout << "Symmetric Difference: ";
    set = set1.symmetric_difference(set2);
    set->print(cout);
    cout << endl;
    delete set;
}
