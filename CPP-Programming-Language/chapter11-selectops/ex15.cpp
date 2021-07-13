#include <iostream>

namespace selectops {
    class Vec4 {
        static const int VEC_SIZE = 4;
        float* items;
        
    public:
        class RangeError {};

        Vec4();
        Vec4(const Vec4& other);
        ~Vec4();

        void check(int idx) const;
        float& operator[](const int idx);
        float operator[](const int idx) const;

        Vec4& operator+=(const Vec4& x);
        Vec4& operator-=(const Vec4& x);
        Vec4& operator*=(const Vec4& x);
        Vec4& operator/=(const Vec4& x);
        Vec4 operator+(const Vec4& x) const;
        Vec4 operator-(const Vec4& x) const;
        Vec4 operator*(const Vec4& x) const;
        Vec4 operator/(const Vec4& x) const;

        Vec4& operator=(const Vec4& x);
        Vec4& operator+=(const float x);
        Vec4& operator-=(const float x);
        Vec4& operator*=(const float x);
        Vec4& operator/=(const float x);
        Vec4 operator+(const float x) const;
        Vec4 operator-(const float x) const;
        Vec4 operator*(const float x) const;
        Vec4 operator/(const float x) const;
        friend Vec4 operator+(const float x, const Vec4& y);
        friend Vec4 operator-(const float x, const Vec4& y);
        friend Vec4 operator*(const float x, const Vec4& y);
        friend Vec4 operator/(const float x, const Vec4& y);

        friend std::ostream& operator<<(std::ostream& output, const Vec4& x);
    };

    Vec4::Vec4() {
        items = new float[VEC_SIZE];
        for (int i = 0; i < VEC_SIZE; i++)
            items[i] = 0.0;
    }

    Vec4::Vec4(const Vec4& other) {
        items = new float[VEC_SIZE];
        for (int i = 0; i < VEC_SIZE; i++)
            items[i] = other.items[i];
    }

    Vec4::~Vec4() {
        delete[] items;
    }

    void Vec4::check(const int idx) const {
        if (idx < 0 || idx >= VEC_SIZE)
            throw RangeError();
    }

    float& Vec4::operator[](const int idx) {
        check(idx);
        return items[idx];
    }

    float Vec4::operator[](const int idx) const {
        check(idx);
        return items[idx];
    }

    Vec4& Vec4::operator=(const Vec4& x) {
        for (int i = 0; i < Vec4::VEC_SIZE; i++)
            items[i] = x.items[i];
        return *this;
    }

    Vec4& Vec4::operator+=(const Vec4& x) {
        for (int i = 0; i < Vec4::VEC_SIZE; i++)
            items[i] += x.items[i];
        return *this;
    }

    Vec4& Vec4::operator-=(const Vec4& x) {
        for (int i = 0; i < Vec4::VEC_SIZE; i++)
            items[i] -= x.items[i];
        return *this;
    }

    Vec4& Vec4::operator*=(const Vec4& x) {
        for (int i = 0; i < Vec4::VEC_SIZE; i++)
            items[i] *= x.items[i];
        return *this;
    }

    Vec4& Vec4::operator/=(const Vec4& x) {
        for (int i = 0; i < Vec4::VEC_SIZE; i++)
            items[i] /= x.items[i];
        return *this;
    }

    Vec4 Vec4::operator+(const Vec4& x) const {
        Vec4 result = *this;
        result += x;
        return result;
    }

    Vec4 Vec4::operator-(const Vec4& x) const {
        Vec4 result = *this;
        result -= x;
        return result;
    }

    Vec4 Vec4::operator*(const Vec4& x) const {
        Vec4 result = *this;
        result *= x;
        return result;
    }

    Vec4 Vec4::operator/(const Vec4& x) const {
        Vec4 result = *this;
        result /= x;
        return result;
    }

    Vec4& Vec4::operator+=(const float x) {
        for (int i = 0; i < Vec4::VEC_SIZE; i++)
            items[i] += x;
        return *this;
    }

    Vec4& Vec4::operator-=(const float x) {
        for (int i = 0; i < Vec4::VEC_SIZE; i++)
            items[i] -= x;
        return *this;
    }

    Vec4& Vec4::operator*=(const float x) {
        for (int i = 0; i < Vec4::VEC_SIZE; i++)
            items[i] *= x;
        return *this;
    }

    Vec4& Vec4::operator/=(const float x) {
        for (int i = 0; i < Vec4::VEC_SIZE; i++)
            items[i] /= x;
        return *this;
    }

    Vec4 Vec4::operator+(const float x) const {
        Vec4 result = *this;
        result += x;
        return result;
    }

    Vec4 Vec4::operator-(const float x) const {
        Vec4 result = *this;
        result -= x;
        return result;
    }

    Vec4 Vec4::operator*(const float x) const {
        Vec4 result = *this;
        result *= x;
        return result;
    }

    Vec4 Vec4::operator/(const float x) const {
        Vec4 result = *this;
        result /= x;
        return result;
    }

    Vec4 operator+(const float x, const Vec4& y) {
        return y + x;
    }

    Vec4 operator-(const float x, const Vec4& y) {
        Vec4 result;
        for (int i = 0; i < Vec4::VEC_SIZE; i++)
            result[i] = x - y.items[i];
        return result;
    }

    Vec4 operator*(const float x, const Vec4& y) {
        return y * x;
    }

    Vec4 operator/(const float x, const Vec4& y) {
        Vec4 result;
        for (int i = 0; i < Vec4::VEC_SIZE; i++)
            result[i] = x / y.items[i];
        return result;
    }

    std::ostream& operator<<(std::ostream& output, const Vec4& x) {
        output << '[';
        for (int i = 0; i < Vec4::VEC_SIZE; i++) {
            output << x.items[i];
            if (i < Vec4::VEC_SIZE-1) output << ',';
        }
        output << ']';
        return output;
    }
}

int main() {
    using namespace std;
    using namespace selectops;

    Vec4 x;
    x[0] = 1.2f;
    x[1] = 4.3f;
    x[2] = 7.0f;
    x[3] = 1.8f;

    Vec4 y;
    y[0] = 1.0f;
    y[1] = 2.0f;
    y[2] = 2.4f;
    y[3] = 3.3f;

    cout << x << " + " << y << " = " << x + y << endl;
    cout << x << " - " << y << " = " << x - y << endl;
    cout << x << " * " << y << " = " << x * y << endl;
    cout << x << " / " << y << " = " << x / y << endl;

    float z = 2.1f;

    cout << x << " + " << z << " = " << x + z << endl;
    cout << x << " - " << z << " = " << x - z << endl;
    cout << x << " * " << z << " = " << x * z << endl;
    cout << x << " / " << z << " = " << x / z << endl;

    cout << z << " + " << x << " = " << z + x << endl;
    cout << z << " - " << x << " = " << z - x << endl;
    cout << z << " * " << x << " = " << z * x << endl;
    cout << z << " / " << x << " = " << z / x << endl;

    return 0;
}



/* Outout */

/* 
$g++ -o main *.cpp
$main
[1.2,4.3,7,1.8] + [1,2,2.4,3.3] = [2.2,6.3,9.4,5.1]
[1.2,4.3,7,1.8] - [1,2,2.4,3.3] = [0.2,2.3,4.6,-1.5]
[1.2,4.3,7,1.8] * [1,2,2.4,3.3] = [1.2,8.6,16.8,5.94]
[1.2,4.3,7,1.8] / [1,2,2.4,3.3] = [1.2,2.15,2.91667,0.545455]
[1.2,4.3,7,1.8] + 2.1 = [3.3,6.4,9.1,3.9]
[1.2,4.3,7,1.8] - 2.1 = [-0.9,2.2,4.9,-0.3]
[1.2,4.3,7,1.8] * 2.1 = [2.52,9.03,14.7,3.78]
[1.2,4.3,7,1.8] / 2.1 = [0.571429,2.04762,3.33333,0.857143]
2.1 + [1.2,4.3,7,1.8] = [3.3,6.4,9.1,3.9]
2.1 - [1.2,4.3,7,1.8] = [0.9,-2.2,-4.9,0.3]
2.1 * [1.2,4.3,7,1.8] = [2.52,9.03,14.7,3.78]
2.1 / [1.2,4.3,7,1.8] = [1.75,0.488372,0.3,1.16667]

 */