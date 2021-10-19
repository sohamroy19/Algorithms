#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cassert>
#include <iostream>
#include <vector>

template <class T>
class Mat {
private:
    std::vector<std::vector<T>> a;

public:
    int const n, m;

    Mat(int nInit, int mInit)
        : n(nInit), m(mInit),
          a(std::vector<std::vector<T>>(nInit, std::vector<T>(mInit))) {}

    Mat(std::vector<std::vector<T>> v)
        : n(v.size()), m(v.empty() ? 0 : v[0].size()), a(v) {}

    Mat &operator=(const Mat &b) {
        assert(n == b.n && m == b.m);

        if (this != &b) {
            a = b.a;
        }

        return *this;
    }

    T &operator()(int i, int j) {
        assert(0 <= i && i < n && 0 <= j && j < m);

        return a[i][j];
    }

    T operator()(int i, int j) const {
        assert(0 <= i && i < n && 0 <= j && j < m);

        return a[i][j];
    }

    void makeIdentity() {
        assert(n == m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = (i == j);
            }
        }
    }

    Mat operator+(const Mat &b) {
        assert(n == b.n && m == b.m);

        Mat ans(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans(i, j) = (a[i][j] + b(i, j));
            }
        }

        return ans;
    }

    Mat operator-(const Mat &b) {
        assert(n == b.n && m == b.m);

        Mat ans(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans(i, j) = (a[i][j] - b(i, j));
            }
        }

        return ans;
    }

    Mat operator*(const Mat &b) {
        assert(m == b.n);

        Mat ans(n, b.m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < b.m; k++) {
                    ans(i, k) += a[i][j] * b(j, k);
                }
            }
        }

        return ans;
    }

    Mat pow(unsigned int k) {
        assert(n == m);

        Mat ans(n, n), t(a);
        ans.makeIdentity();

        while (k) {
            if (k % 2 != 0) ans *= t;
            t *= t;
            k /= 2;
        }

        return ans;
    }

    Mat &operator+=(const Mat &b) {
        assert(n == b.n && m == b.m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] += b(i, j);
            }
        }

        return *this;
    }

    Mat &operator-=(const Mat &b) {
        assert(n == b.n && m == b.m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] -= b(i, j);
            }
        }

        return *this;
    }

    inline Mat &operator*=(const Mat &b) { return *this = (*this) * b; }

    inline bool operator==(const Mat &b) { return a == b.a; }
    inline bool operator!=(const Mat &b) { return a != b.a; }
};

template <class T>
std::ostream &operator<<(std::ostream &os, Mat<T> const &mat) {
    os << "Mat(";

    for (int i = 0; i < mat.n - 1; ++i) {
        for (int j = 0; j < mat.m - 1; ++j) {
            os << mat(i, j) << ", ";
        }

        os << mat(i, mat.m - 1) << "; ";
    }

    for (int j = 0; j < mat.m - 1; ++j) {
        os << mat(mat.n - 1, j) << ", ";
    }

    os << mat(mat.n - 1, mat.m - 1) << ")";

    return os;
}

#endif /* MATRIX_HPP */