#include <cassert>
#include <iostream>
#include <vector>

template <class T>
class Mat {
public:
    int const n, m;
    std::vector<std::vector<T>> a;

    Mat(int nInit, int mInit)
        : n(nInit), m(mInit),
          a(std::vector<std::vector<T>>(n, std::vector<T>(m))) {}

    Mat(std::vector<std::vector<T>> v)
        : n(v.size()), m(n > 0 ? v[0].size() : 0), a(v) {}

    Mat& operator=(const Mat &b) {
        assert(n == b.n && m == b.m);

        if (this != &b) {
            a = b.a;
        }

        return *this;
    }

    T &operator()(int i, int j) {
        assert(0 <= i && i < n);

        return a[i][j];
    }

    T operator()(int i, int j) const {
        assert(0 <= i && i < n);

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

        Mat ans = Mat(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans(i, j) = (a[i][j] + b(i, j));
            }
        }

        return ans;
    }

    Mat operator-(const Mat &b) {
        assert(n == b.n && m == b.m);

        Mat ans = Mat(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans(i, j) = (a[i][j] - b(i, j));
            }
        }

        return ans;
    }

    Mat operator*(const Mat &b) {
        assert(m == b.n);

        Mat ans = Mat(n, b.m);
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

int main() {
    Mat<int> eg({{1, 2}, {3, 4}});
    Mat<int> id(2, 2);
    id.makeIdentity();

    std::cout << "eg      : " << eg << "\n";
    std::cout << "id      : " << id << "\n\n";

    std::cout << "eg + id : " << eg + id << "\n";
    std::cout << "eg - id : " << eg - id << "\n";
    std::cout << "eg * id : " << eg * id << "\n\n";

    std::cout << "id ^ 2  : " << id.pow(2) << "\n";
    std::cout << "eg ^ 2  : " << eg.pow(2) << "\n\n";
}