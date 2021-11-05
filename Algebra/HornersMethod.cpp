/**
 * Horner's method of evaluating the value of a polynomial
 * https://en.wikipedia.org/wiki/Horner%27s_method
 * 
 * Time  : O(n)
 * Space : O(1)
 */

#include <iostream>
#include <vector>

template <class T>
T horner(std::vector<T> &coeffs, T x) {
    double result = 0;

    for (int i = coeffs.size() - 1; i >= 0; --i) {
        result = result * x + coeffs[i];
    }
    
    return result;
}

int main() {
    std::cout << "Enter the degree of the polynomial: ";
    int n;
    std::cin >> n;

    std::cout << "\nEnter the coefficients of the polynomial:-\n";
    std::vector<double> coeffs(n + 1);
    for (int i = 0; i <= n; ++i) {
        std::cout << "a_" << i << ": ";
        std::cin >> coeffs[i];
    }

    std::cout << "\nEnter the value of x: ";
    double x;
    std::cin >> x;

    std::cout << "\nValue of the polynomial at x = " << x << ": " << horner(coeffs, x) << "\n";

    return 0;
}