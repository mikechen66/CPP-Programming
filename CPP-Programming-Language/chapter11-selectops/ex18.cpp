#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

namespace selectops {
    class Vector {
        int sz;
        float* items;
        
    public:
        class RangeError {};
        class SizeError {};

        Vector();
        Vector(int size);
        Vector(const Vector& other);
        ~Vector();

        void check(int idx) const;
        void check_size_equals(const Vector& other) const;
        float& operator[](const int idx);
        float operator[](const int idx) const;

        Vector& operator+=(const Vector& x);
        Vector& operator-=(const Vector& x);
        Vector& operator*=(const Vector& x);
        Vector& operator/=(const Vector& x);
        Vector operator+(const Vector& x) const;
        Vector operator-(const Vector& x) const;
        Vector operator*(const Vector& x) const;
        Vector operator/(const Vector& x) const;

        Vector& operator=(const Vector& x);
        Vector& operator+=(const float x);
        Vector& operator-=(const float x);
        Vector& operator*=(const float x);
        Vector& operator/=(const float x);
        Vector operator+(const float x) const;
        Vector operator-(const float x) const;
        Vector operator*(const float x) const;
        Vector operator/(const float x) const;
        friend Vector operator+(const float x, const Vector& y);
        friend Vector operator-(const float x, const Vector& y);
        friend Vector operator*(const float x, const Vector& y);
        friend Vector operator/(const float x, const Vector& y);

        friend std::ostream& operator<<(std::ostream& output, const Vector& x);
    };

    Vector::Vector() : sz(0), items(0) {}

    Vector::Vector(int size) : sz(size) {
        items = new float[sz];
        for (int i = 0; i < sz; i++)
            items[i] = 0.0;
    }

    Vector::Vector(const Vector& other) {
        sz = other.sz;
        items = new float[sz];
        for (int i = 0; i < sz; i++)
            items[i] = other.items[i];
    }

    Vector::~Vector() {
        delete[] items;
    }

    void Vector::check(const int idx) const {
        if (idx < 0 || idx >= sz)
            throw RangeError();
    }

    void Vector::check_size_equals(const Vector& other) const {
        if (sz != other.sz)
            throw SizeError();
    }

    float& Vector::operator[](const int idx) {
        check(idx);
        return items[idx];
    }

    float Vector::operator[](const int idx) const {
        check(idx);
        return items[idx];
    }

    Vector& Vector::operator=(const Vector& x) {
        if (sz != x.sz) {
            if (items != 0)
                delete[] items;
            items = new float[x.sz];
            sz = x.sz;
        }
        for (int i = 0; i < sz; i++)
            items[i] = x.items[i];
        return *this;
    }

    Vector& Vector::operator+=(const Vector& x) {
        check_size_equals(x);
        for (int i = 0; i < sz; i++)
            items[i] += x.items[i];
        return *this;
    }

    Vector& Vector::operator-=(const Vector& x) {
        check_size_equals(x);
        for (int i = 0; i < sz; i++)
            items[i] -= x.items[i];
        return *this;
    }

    Vector& Vector::operator*=(const Vector& x) {
        check_size_equals(x);
        for (int i = 0; i < sz; i++)
            items[i] *= x.items[i];
        return *this;
    }

    Vector& Vector::operator/=(const Vector& x)  {
        check_size_equals(x);
        for (int i = 0; i < sz; i++)
            items[i] /= x.items[i];
        return *this;
    }

    Vector Vector::operator+(const Vector& x) const {
        Vector result = *this;
        result += x;
        return result;
    }

    Vector Vector::operator-(const Vector& x) const {
        Vector result = *this;
        result -= x;
        return result;
    }

    Vector Vector::operator*(const Vector& x) const {
        Vector result = *this;
        result *= x;
        return result;
    }

    Vector Vector::operator/(const Vector& x) const {
        Vector result = *this;
        result /= x;
        return result;
    }

    Vector& Vector::operator+=(const float x) {
        for (int i = 0; i < sz; i++)
            items[i] += x;
        return *this;
    }

    Vector& Vector::operator-=(const float x) {
        for (int i = 0; i < sz; i++)
            items[i] -= x;
        return *this;
    }

    Vector& Vector::operator*=(const float x) {
        for (int i = 0; i < sz; i++)
            items[i] *= x;
        return *this;
    }

    Vector& Vector::operator/=(const float x) {
        for (int i = 0; i < sz; i++)
            items[i] /= x;
        return *this;
    }

    Vector Vector::operator+(const float x) const {
        Vector result = *this;
        result += x;
        return result;
    }

    Vector Vector::operator-(const float x) const {
        Vector result = *this;
        result -= x;
        return result;
    }

    Vector Vector::operator*(const float x) const {
        Vector result = *this;
        result *= x;
        return result;
    }

    Vector Vector::operator/(const float x) const {
        Vector result = *this;
        result /= x;
        return result;
    }

    Vector operator+(const float x, const Vector& y) {
        return y + x;
    }

    Vector operator-(const float x, const Vector& y) {
        Vector result(y.sz);
        for (int i = 0; i < y.sz; i++)
            result[i] = x - y.items[i];
        return result;
    }

    Vector operator*(const float x, const Vector& y) {
        return y * x;
    }

    Vector operator/(const float x, const Vector& y) {
        Vector result(y.sz);
        for (int i = 0; i < y.sz; i++)
            result[i] = x / y.items[i];
        return result;
    }

    std::ostream& operator<<(std::ostream& output, const Vector& x) {
        output << '[';
        for (int i = 0; i < x.sz; i++) {
            output << x.items[i];
            if (i < x.sz-1) output << ',';
        }
        output << ']';
        return output;
    }

    class Matrix
    {
        int rows;
        int columns;
        Vector* items;

    public:
        class RangeError {};
        class SizeError {};

        Matrix(int rows, int columns);
        Matrix(const Matrix& other);
        ~Matrix();

        void check(int idx) const;
        void check_size_equals(const Matrix& other) const;
        Vector& operator[](int idx);
        const Vector& operator[](int idx) const;
        Matrix& operator=(const Matrix& x);
        Matrix& operator+=(const Matrix& x);
        Matrix operator+(const Matrix& x) const;
        Matrix& operator*=(const float x);
        Matrix operator*(const float x) const;
        Matrix& operator*=(const Matrix& x);
        Matrix operator*(const Matrix& x) const;
        friend Matrix operator*(const float x, const Matrix& y);

        friend std::ostream& operator<<(std::ostream& output, const Matrix& x);

        void gaussian_elimination(Vector& answers);
    };

    Matrix::Matrix(int rows, int columns) : rows(rows), columns(columns) {
        items = new Vector[rows];
        for (int i = 0; i < rows; i++)
            items[i] = Vector(columns);
    }

    Matrix::Matrix(const Matrix& other) {
        rows = other.rows;
        columns = other.columns;
        items = new Vector[rows];
        for (int i = 0; i < rows; i++)
            items[i] = other.items[i];
    }

    Matrix::~Matrix() {
        delete[] items;
    }
    
    void Matrix::check(int idx) const {
        if (idx < 0 || idx >= rows)
            throw RangeError();
    }

    void Matrix::check_size_equals(const Matrix& other) const {
        if (rows != other.rows || columns != other.columns)
            throw SizeError();
    }

    Vector& Matrix::operator[](int idx) {
        check(idx);
        return items[idx];
    }

    const Vector& Matrix::operator[](int idx) const {
        check(idx);
        return items[idx];
    }

    Matrix& Matrix::operator=(const Matrix& x) {
        if (rows != x.rows) {
            delete[] items;
            items = new Vector[x.rows];
            rows = x.rows;
        }
        for (int i = 0; i < rows; i++)
            items[i] = x.items[i];
        return *this;
    }

    Matrix& Matrix::operator+=(const Matrix& x) {
        check_size_equals(x);
        for (int i = 0; i < rows; i++)
            items[i] += x.items[i];
        return *this;
    }

    Matrix Matrix::operator+(const Matrix& x) const {
        Matrix result = *this;
        result += x;
        return result;
    }

    Matrix& Matrix::operator*=(const float x) {
        for (int i = 0; i < rows; i++)
            items[i] *= x;
        return *this;
    }

    Matrix Matrix::operator*(const float x) const {
        Matrix result = *this;
        result *= x;
        return result;
    }

    Matrix operator*(const float x, const Matrix& y) {
        return y * x;
    }

    Matrix& Matrix::operator*=(const Matrix& x) {
        *this = *this * x;
        return *this;
    }

    Matrix Matrix::operator*(const Matrix& x) const {
        if (columns != x.rows)
            throw SizeError();

        Matrix result(rows,x.columns);
        for (int i = 0; i < rows; i++) {
            for(int j = 0; j < x.columns; j++) {
                float a = 0;
                for(int k = 0; k < columns; k++) {
                    a += items[i][k] * x.items[k][j];
                }
                result[i][j] = a;
            }
        }
        return result;
    }

    std::ostream& operator<<(std::ostream& output, const Matrix& x) {
        output << " _" << std::string(8*x.columns, ' ') << '_' << std::endl;
        for (int i = 0; i < x.columns; i++) {
            output << "|";
            for (int j = 0; j < x.columns; j++) {
                output.width(7);
                output << x[i][j];
                if (j < x.columns-1) output << ",";
            }
            output << "   |" << std::endl;
        }
        output << " -" << std::string(8*x.columns, ' ') << '-' << std::endl;

        return output;
    }

    void Matrix::gaussian_elimination(Vector& answers) {
        if (rows != columns)
            throw SizeError();
        int sz = rows;

        int i = 0, j = 0;
        while (i < sz && j < sz) {
            int maxi = i;
            for (int k = i+1; k < sz; k++) {
                if (abs(items[k][j]) > abs(items[maxi][j]))
                    maxi = k;
            }
            if (items[maxi][j] != 0) {
                Vector tmp = items[maxi];
                items[maxi] = items[i];
                items[i] = tmp;
                float atmp = answers[maxi];
                answers[maxi] = answers[i];
                answers[i] = atmp;
                for (int k = 0; k < sz; k++) {
                    items[i][k] /= items[i][j];
                }
                answers[i] /= items[i][j];
                for (int u = i+1; u < sz; u++) {
                    for (int k = 0; k < sz; k++) {
                        items[u][k] -= items[u][i] * items[i][k];
                    }
                    answers[u] -= items[u][i] * answers[i];
                }
                i++;
            }
            j++;
        }
    }
}

int main() {
    using namespace std;
    using namespace selectops;

    Vector v1(5);
    v1[0] = 1.2f;
    v1[1] = 4.3f;
    v1[2] = 7.0f;
    v1[3] = 1.8f;
    v1[4] = 0.1f;

    Vector v2(5);
    v2[0] = 1.0f;
    v2[1] = 2.0f;
    v2[2] = 2.4f;
    v2[3] = 3.3f;

    Vector v3(5);
    v3[0] = 0.8f;
    v3[1] = 1.0f;
    v3[2] = 1.16f;
    v3[3] = 2.9f;
    v3[4] = 2.8f;

    Vector v4(5);
    v4[0] = 1.1f;
    v4[1] = 6.8f;
    v4[2] = 9.1f;
    v4[3] = 10.0f;
    v4[4] = 8.8f;

    Vector v5(5);
    v5[0] = 8.0f;
    v5[1] = 6.6f;
    v5[2] = 9.6f;
    v5[3] = 7.7f;
    v5[4] = 0.5f;

    Matrix m1(5,5);
    m1[0] = v1;
    m1[1] = v2;
    m1[2] = v3;
    m1[3] = v4;
    m1[4] = v5;

    Matrix m2(5,5);
    m2[0] = v2;
    m2[1] = v5;
    m2[2] = v1;
    m2[3] = v4;
    m2[4] = v3;

    cout << "m1:" << endl << m1;
    cout << "m2:" << endl << m2;
    cout << "m1 + m2:" << endl << m1 + m2;
    cout << "m1 * 3:" << endl << m1 * 3;
    cout << "m1 * m2:" << endl << m1 * m2;

    m1.gaussian_elimination(v3);
    cout << "After Gaussian elimination:" << endl;
    cout << m1;
    cout << v3;

    return 0;
}



/* Output */

/*
$g++ -o main *.cpp
$main
m1:
 _                                        _
|    1.2,    4.3,      7,    1.8,    0.1   |
|      1,      2,    2.4,    3.3,      0   |
|    0.8,      1,   1.16,    2.9,    2.8   |
|    1.1,    6.8,    9.1,     10,    8.8   |
|      8,    6.6,    9.6,    7.7,    0.5   |
 -                                        -
m2:
 _                                        _
|      1,      2,    2.4,    3.3,      0   |
|      8,    6.6,    9.6,    7.7,    0.5   |
|    1.2,    4.3,      7,    1.8,    0.1   |
|    1.1,    6.8,    9.1,     10,    8.8   |
|    0.8,      1,   1.16,    2.9,    2.8   |
 -                                        -
m1 + m2:
 _                                        _
|    2.2,    6.3,    9.4,    5.1,    0.1   |
|      9,    8.6,     12,     11,    0.5   |
|      2,    5.3,   8.16,    4.7,    2.9   |
|    2.2,   13.6,   18.2,     20,   17.6   |
|    8.8,    7.6,  10.76,   10.6,    3.3   |
 -                                        -
m1 * 3:
 _                                        _
|    3.6,   12.9,     21,    5.4,    0.3   |
|      3,      6,    7.2,    9.9,      0   |
|    2.4,      3,   3.48,    8.7,    8.4   |
|    3.3,   20.4,   27.3,     30,   26.4   |
|     24,   19.8,   28.8,   23.1,    1.5   |
 -                                        -
m1 * m2:
 _                                        _
|  46.06,  73.22,109.656,  67.96,  18.97   |
|  23.51,  47.96,  68.43,  56.02,  30.28   |
| 15.622, 35.708, 49.278, 49.548, 33.976   |
|  84.46, 163.01,232.828, 197.89, 116.95   |
|  81.19,  153.7, 220.41, 172.95,  73.42   |
 -                                        -
After Gaussian elimination:
 _                                        _
|      1,    6.6,    9.6,    7.7,    0.5   |
|      0,      1,    9.1,     10,    8.8   |
|      0,      0,      1,    1.8,    0.1   |
|      0,      0,      0,      1,      0   |
|      0,      0,      0,      0,      1   |
 -                                        -
[2.8,2.9,0.8,1,1.16]
 */