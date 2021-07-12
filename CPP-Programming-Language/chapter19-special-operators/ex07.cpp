#include <iostream>
#include <vector>

// Validation checks must be more frequent because the
// container may have changed at any point (for example,
// elements may have been erased). For that reason, the
// valid() function must be called much more frequently.
// This will add a lot of overhead for non-random-access
// iterators.
namespace ch19 {
    using namespace std;

    class out_of_bounds { };

    template<class Cont, class Iter = typename Cont::iterator>
    class Checked_iter : public iterator_traits<Iter> {
        Iter curr;
        Cont* c;
    public:
        typedef iterator_traits<Iter> traits_type;
        typedef typename traits_type::reference reference;
        typedef typename traits_type::pointer pointer;
        typedef typename traits_type::difference_type difference_type;

        void valid(Iter p, random_access_iterator_tag) const {
            if (p > c->end() || p < c->begin())
                throw out_of_bounds();
        }

        void valid(Iter p, forward_iterator_tag) const {
            if(c->end() == p)
                return;
            for(Iter pp = c->begin(); pp != c->end(); ++pp) {
                if(pp == p)
                    return;
            }
            throw out_of_bounds();
        }

        void valid(Iter p) const {
            valid(p, typename traits_type::iterator_category());
        }

        friend bool operator==(const Checked_iter& i, const Checked_iter& j) {
            return i.c==j && i.curr==j.curr;
        }

        Checked_iter(Cont& x, Iter p) : c(&x), curr(p) { valid(p); }
        Checked_iter(Cont& x) : c(&x), curr(x.begin()) { }

        reference operator*() const {
            valid(curr);
            if(curr==c->end()) throw out_of_bounds();
            return *curr;
        }

        pointer operator->() const {
            valid(curr);
            if(curr==c->end()) throw out_of_bounds();
            return &*curr;
        }

        Checked_iter operator+(difference_type d) const {
            Iter newCurr = curr + d;
            valid(newCurr);
            return Checked_iter(*c,newCurr);
        }

        reference operator[](difference_type d) const {
            Iter newCurr = curr + d;
            valid(newCurr);
            if(newCurr == c->end()) throw out_of_bounds();
            return curr[d];
        }

        Checked_iter& operator++() {
            Iter newCurr = curr;
            ++newCurr;
            valid(newCurr);
            curr = newCurr;
            return *this;
        }

        Checked_iter operator++(int) {
            Checked_iter tmp = *this;
            ++*this;
            return tmp;
        }

        Checked_iter& operator--() {
            Iter newCurr = curr;
            --newCurr;
            valid(newCurr);
            curr = newCurr;
            return *this;
        }

        Checked_iter operator--(int) {
            Checked_iter tmp = *this;
            --*this;
            return tmp;
        }

        difference_type index() const { return curr - c->begin(); }
        Iter unchecked() const { return curr; }

        Checked_iter operator-(difference_type d) const {
            return *this + -d;
        }

        difference_type operator-(const Checked_iter& x) const {
            return this->curr - x.curr;
        }

        bool operator<(const Checked_iter& x) const {
            return this->curr < x.curr;
        }

        friend bool operator!=(const Checked_iter& i, const Checked_iter& j) {
            return i.c!=j || i.curr!=j.curr;
        }

        bool operator>(const Checked_iter& x) const {
            return !(*this < x) && *this != x;
        }

        bool operator<=(const Checked_iter& x) const {
            return *this < x || *this == x;
        }

        bool operator>=(const Checked_iter& x) const {
            return !(*this < x);
        }
    };

    template<class Cont, class Iter>
    Checked_iter<Cont,typename Cont::iterator> make_checked(Cont& c, Iter i) {
        return Checked_iter<Cont,typename Cont::iterator>(c, i);
    }

    template<class Cont>
    Checked_iter<Cont,typename Cont::iterator> make_checked(Cont& c) {
        return Checked_iter<Cont,typename Cont::iterator>(c, c.begin());
    }
}

int main() {
    using namespace ch19;

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    Checked_iter<vector<int> > ci = make_checked(v);
    ci++;
    ci++;
    v.erase(ci.unchecked());
    try {
        *ci;
    }
    catch (out_of_bounds) {
        cout << "caught out_of_bounds" << endl;
    }
}
