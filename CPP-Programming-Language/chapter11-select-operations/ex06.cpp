#include <iostream>
#include <limits>
#include <vector>
#include <cstdlib>

using std::ostream;

namespace ch11 {
    // Again, this is unlikely to be very efficient at all.
    class BIGINT {
        class IntRep;
        IntRep* rep;

        void clear();
        void bit_shift_left();
        void bit_shift_right();
        void invert();
        unsigned short safe_get_digit(unsigned int idx) const;
        int basic_compare(const BIGINT& x) const;
        void basic_add(const BIGINT& x);
        void basic_subtract(const BIGINT& x);
        void add(const BIGINT& x);
        void subtract(const BIGINT& x);
        void multiply(const BIGINT& m);
        void divide(const BIGINT& x, BIGINT& quotient, BIGINT& remainder);
        void divide(const BIGINT& x);
        void modulus(const BIGINT& x);

    public:
        class OverflowError {};
        class divideByZeroError {};

        BIGINT(int ii);
        BIGINT(const BIGINT& li);
        ~BIGINT();
        BIGINT operator+();
        BIGINT operator-();
        BIGINT operator-(const BIGINT& x);
        BIGINT operator+(const BIGINT& x);
        BIGINT operator*(const BIGINT& x);
        bool operator<(const BIGINT& x);
        bool operator>(const BIGINT& x);
        bool operator==(const BIGINT& x) const;
        bool operator==(int x) const;
        BIGINT& operator=(const BIGINT& x);
        BIGINT& operator=(const int i);
        BIGINT operator/(const BIGINT& x);
        BIGINT operator%(const BIGINT& x);
        friend ostream& operator<<(ostream& out, const BIGINT& x);
    };

    class BIGINT::IntRep {
        friend class BIGINT; 
        friend ostream& operator<<(ostream& out, const BIGINT& x);

        int n;
        bool neg;

        typedef std::vector<unsigned short> DigitList;
        DigitList d;

        IntRep() : n(1), neg(false) {
        }

        IntRep(bool neg, const DigitList& x) : n(1), neg(neg) {
            d.insert(d.begin(), x.begin(), x.end());
        }

        IntRep* copy() {
            if (n==1) 
                return this;
            n--;
            return new IntRep(neg, d);
        }

        void normalize() {
            while (d.size() > 0 && *(d.end()-1) == 0) 
                d.pop_back();
        }

    private:
        IntRep(const IntRep&);
        IntRep& operator=(const IntRep&);
    };

    void BIGINT::clear() {
        rep->d.clear();
        rep->neg = 0;
    }

    void BIGINT::bit_shift_left() {
        rep->d.push_back(0);
        for (int i = rep->d.size(); i > 0; i--) {
            rep->d[i-1] <<= 1;
            if (i > 1 && (rep->d[i-2] & 0x8000))
                rep->d[i-1] |= 1;
        }
        rep->normalize();
    }

    void BIGINT::bit_shift_right() {
        int sz = rep->d.size() - 1;

        for (int i = 0; i <= sz; i++) {
            rep->d[i] >>= 1;
            if (i < sz && (rep->d[i+1] & 1))
                rep->d[i] |= 0x8000;
        }
        rep->normalize();
    }

    void BIGINT::invert() {
        for (unsigned int i = 0; i <= rep->d.size()-1; i++)
            rep->d[i] = ~rep->d[i];
        rep->normalize();
    }

    unsigned short BIGINT::safe_get_digit(unsigned int idx) const {
        if (idx < 0 || idx+1 > rep->d.size()) 
            return 0;
        return rep->d[idx];
    }

    int BIGINT::basic_compare(const BIGINT& x) const {
        if (rep->d.size() > x.rep->d.size()) 
            return 1;
        else if (rep->d.size() < x.rep->d.size()) 
            return -1;

        for (int i = rep->d.size(); i > 0; i--) {
            if (rep->d[i-1] < x.rep->d[i-1]) 
                return -1;
            if (rep->d[i-1] > x.rep->d[i-1]) 
                return 1;
        }
        return 0;
    }

    void BIGINT::basic_add(const BIGINT& x) {
        int r = 0;
        while (rep->d.size() < x.rep->d.size()+1) 
            rep->d.push_back(0);
        for (unsigned int i = 0; i < rep->d.size(); i++) {
            r = rep->d[i] + x.safe_get_digit(i) + r;
            rep->d[i] = r % 0x10000;
            r = r / 0x10000;
        }
        if (r > 0)
            throw OverflowError();
        rep->normalize();
    }

    void BIGINT::basic_subtract(const BIGINT& x) {
        int r = 0;
        while (rep->d.size() < x.rep->d.size()) 
            rep->d.push_back(0);
        for (unsigned int i = 0; i < rep->d.size(); i++) {
            r = rep->d[i] - x.safe_get_digit(i) - r;
            if (r < 0) {
                rep->d[i] = static_cast<unsigned short>(0x10000 + r);
                r = 1;
            } else {
                rep->d[i] = static_cast<unsigned short>(r);
                r = 0;
            }
        }
        if (r > 0)
            throw OverflowError();
        rep->normalize();
    }

    void BIGINT::add(const BIGINT& x) {
        if (rep->neg == x.rep->neg) {
            basic_add(x);
        } else if (basic_compare(x) < 0) {
            BIGINT li = *this;
            *this = x;
            rep = rep->copy();
            basic_subtract(li);
            rep->neg = !li.rep->neg;
        } else if (basic_compare(x) > 0) {
            basic_subtract(x);
        } else {
            *this = 0; 
        }
        if (basic_compare(0)==0) rep->neg = false;
    }

    void BIGINT::subtract(const BIGINT& x) {
        if (rep->neg == x.rep->neg) {
            if (basic_compare(x) < 0) {
                BIGINT li = *this;
                *this = x;
                rep = rep->copy();
                basic_subtract(li);
                rep->neg = !li.rep->neg;
            } else if (basic_compare(x) > 0) {
                basic_subtract(x);
            } else {
                *this = 0;
            }
        } else {
            basic_add(x);
        }
        if (basic_compare(0)==0) rep->neg = false;
    }

    void BIGINT::multiply(const BIGINT& m) {
        unsigned int r = 0;
        BIGINT y(0), x(0);

        // Make sure the operand with the most digits is
        // processed in the outer loop.
        if (rep->d.size() > m.rep->d.size()) {
            y = m;
            x = *this;
        } else {
            x = m;
            y = *this;
        }
        rep = rep->copy();
        clear();

        BIGINT li(0);
        for (unsigned int i = 0; i < x.rep->d.size(); i++) {
            r = 0;
            li.clear();
            for (int k = 0; k < i; k++) 
                li.rep->d.push_back(0);
            for (unsigned int j = 0; j < y.rep->d.size(); j++) {
                r = x.rep->d[i] * y.rep->d[j] + r;

                li.rep->d.push_back(r % 0x10000);
                r = r / 0x10000;
            }
            if (r > 0) 
                li.rep->d.push_back(r);
            basic_add(li);
        }
        rep->neg = x.rep->neg != y.rep->neg;
        if (basic_compare(0)==0) 
            rep->neg = false;
        rep->normalize();
    }

    void BIGINT::divide(const BIGINT& x, BIGINT& quotient, BIGINT& remainder) {
        if (basic_compare(x) < 0) {
            remainder = x;
            return;
        } else if (basic_compare(x) == 0) {
            quotient = 1;
            quotient.rep->neg = rep->neg != x.rep->neg;
            return;
        } else if (x == 0) {
            throw divideByZeroError();
        }

        BIGINT dividend(*this);
        BIGINT divisor(x);
        dividend.rep = dividend.rep->copy();
        divisor.rep = divisor.rep->copy();

        quotient = remainder = 0;
        int zeroCount = 0;

        while (divisor.basic_compare(dividend) < 0) {
            divisor.bit_shift_left();
            zeroCount++;
        }
        if (divisor.basic_compare(dividend) > 0) {
            divisor.bit_shift_right();
            zeroCount--;
        }

        if (zeroCount >= 0) {
            for (int i = 0; i <= zeroCount; i++) {
                if (divisor.basic_compare(dividend) <= 0) {
                    dividend.basic_subtract(divisor);
                    divisor.bit_shift_right();
                    quotient.bit_shift_left();
                    quotient.basic_add(1);
                } else {
                    divisor.bit_shift_right();
                    quotient.bit_shift_left();
                }
            }
        }

        remainder = dividend;

        quotient.rep->neg = rep->neg != x.rep->neg;
        if (quotient.basic_compare(0)==0) 
            quotient.rep->neg = false;
        if (remainder.basic_compare(0)==0) 
            remainder.rep->neg = false;
    }

    void BIGINT::divide(const BIGINT& x) {
        BIGINT quotient(0), remainder(0);
        divide(x, quotient, remainder);
        *this = quotient;
    }

    void BIGINT::modulus(const BIGINT& x) {
        BIGINT quotient(0), remainder(0);
        divide(x, quotient, remainder);
        *this = remainder;
    }

    BIGINT::BIGINT(int ii) : rep(new IntRep) {
        rep->d.push_back(abs(ii) & 0xffff);
        rep->d.push_back(abs(ii) >> 16);
        rep->neg = ii < 0;
        rep->normalize();
    }

    BIGINT::BIGINT(const BIGINT& li) {
        rep = li.rep;
        rep->n++;
    }

    BIGINT::~BIGINT() {
        if (rep->n == 1)
            delete rep;
    }

    BIGINT BIGINT::operator+() { 
        return *this; 
    }

    BIGINT BIGINT::operator-() {
        BIGINT li = *this;
        li.rep = rep->copy();
        li.rep->neg = !li.rep->neg;
        return li;
    }

    BIGINT BIGINT::operator-(const BIGINT& x) {
        BIGINT li = *this;
        li.rep = li.rep->copy();
        li.subtract(x);
        return li;
    }

    BIGINT BIGINT::operator+(const BIGINT& x) {
        BIGINT li = *this;
        li.rep = li.rep->copy();
        li.add(x);
        return li;
    }

    BIGINT BIGINT::operator*(const BIGINT& x) {
        BIGINT li = *this;
        li.rep = li.rep->copy();
        li.multiply(x);
        return li;
    }

    bool BIGINT::operator<(const BIGINT& x) {
        if (rep->neg==x.rep->neg) 
            return basic_compare(x) < 0;
        else if (rep->neg && !x.rep->neg) 
            return true;
        else 
            return false;
    }

    bool BIGINT::operator>(const BIGINT& x) {
        if (rep->neg==x.rep->neg) 
            return basic_compare(x) > 0;
        else if (!rep->neg && x.rep->neg) 
            return true;
        else 
            return false;
    }

    bool BIGINT::operator==(const BIGINT& x) const {
        if (rep->neg != x.rep->neg) 
            return false;
        return basic_compare(x) == 0;
    }

    bool BIGINT::operator==(int x) const {
        return *this == BIGINT(x);
    }

    BIGINT& BIGINT::operator=(const BIGINT& x) {
        if (rep->n == 1) 
            delete rep;
        rep = x.rep;
        rep->n++;
        return *this;
    }

    BIGINT& BIGINT::operator=(const int i) {
        *this = BIGINT(i);
        return *this;
    }

    BIGINT BIGINT::operator/(const BIGINT& x) {
        BIGINT li = *this;
        li.rep = li.rep->copy();
        li.divide(x);
        return li;
    }

    BIGINT BIGINT::operator%(const BIGINT& x) {
        BIGINT li = *this;
        li.rep = li.rep->copy();
        li.modulus(x);
        return li;
    }

    ostream& operator<<(ostream& out, const BIGINT& x) {
        if (x.rep->neg) 
            out << '-';
        out.fill('0');
        out << std::hex;
        if (x.rep->d.size() < 1) 
            out << 0;
        for (int i = x.rep->d.size(); i > 0; i--) {
            out.width(4);
            out << x.rep->d[i-1];
        }
        return out;
    }
}

int main() {
    using namespace ch11;
    using namespace std;

    BIGINT bi(1000);
    for (int i = 999; i > 1; i--) {
        bi = bi * i;
    }
    cout << bi << endl;
}



/* Output */

/*
$g++ -o main *.cpp
$main
0002a2a773338969b740de6e2b291fd8dd6ee62a2b41525ab61cbe52489b6cf344c23231711b6d9f34e0f13ab50eaf1ad3dd92771ec26b4b9ea80411c866b1ccbd855f8326edab10832755e1682d3e7a91335e3670329bc1571b5208d72f7d6be81483a6e6708abf913b789f41838e9a73c1ba82e3a956570405a660a17e1125838bc810c8d2c63915481914ea202867a563a41b6aefef5feac300a78803a30eb995208842ebeba8729397a8cd9087e28fb155a3de0f18dd90e64a9293af6487a5aabdab855fa254fcbdc9f1116060bc2e2b4410e55e7368b844d9bf0aeca92deb017def69af777e8d4edb1f1b926ae01df3366abb9e4568fc08fe255b68bca0e48382a8e6df1c7b0ba33bc2225cc512b39176a26b13098e733e51417224be36fbd933a8a7d98a08f356cf010f0fc59b9f1e32d3fb43209a82fa0e7f69e302fcb0f20362b86cbbeb08b81b1ba07f08ab119ce5e092d09996b710588779327d91ee80eb679a99f0fdca7eb4a50ef174295e94d590e3cf8bf37d23e5b22dcd79a4ac2c1ea7d1d55170789fcd2fcbb3ea52ead4f7116f862578f5e22421c90cd0a7ee095903150631f27305191429a54cace66dd076c51a94034b31bebec406ee460181225e03a9a22c51e6a2a8db4a94fd352605115caf251b14df0cec523c48b79b58b0fc0676792d38a0d61523eb75f5cbc33ebda1b19933878ce7050356bd228ce9327a9916f9ff3bb5b6beedfe5382b861d6c4da52a9754b6feec8a99372b43afa7808836d281c5b2cdf791cf76d6c737aad32c5ed7475855fc15c3f45c4705dd0d6b4078656d027cfee6f37772e03c35c0dcbbdaa25ea64d6865c87cac0a9a999eb88d7a16515811a77192071189c353c1e72242a4f3106cef2bad1075549b4efd6885690f3f58c1f4686951cc543118428ec653e3c6fbdb427930f624680672c1e70c25db7e7b67016a95b30dba56d0083759eac93a8e4d0c54853aa43f197b96fd70696ae5750d7d1f0427b8dbcfafc8b9924d51340fbf71bc22780fba76525f5e5b91a2461983b60bf087dfdd89dcbc6f7892d9e4c5d55d106d45f77e4fc1c44a376d693bfb8b160f12ed1bdf5f4f1127e61d9dec2dc1bba43a6ff47d294de7a67cdf3ef90937667092517e985642d195031c6f5339c1cea607a699c55e75c5479cbd30ddaccab307472aa67a6a9a547d7e1eba123144193e6d2933556ddeb516151eacf0b48ce08892236abfb74bf0cee3a0e45997301027f2a53990697694f14de4fac0c908eeaeedf3dbb45c4ce9f744fef88ec1068c52056b16da099e1fb620bd90de25534b5e820b367a400000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
　*/