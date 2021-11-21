/**
 * https://en.wikipedia.org/wiki/Levenshtein_distance
 * https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
 */

#include <algorithm>
#include <iostream>
#include <string_view>
#include <vector>

int floydWarshall(std::string_view a, std::string_view b) {
    int n = a.size() + 1;
    int m = b.size() + 1;

    std::vector<int> dp(n * m);

    for (int i = 0; i < n; ++i) {
        dp[i * m + 0] = i;
    }

    for (int j = 0; j < m; ++j) {
        dp[0 * m + j] = j;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i * m + j] = dp[(i - 1) * m + j - 1];
            } else {
                dp[i * m + j] = std::min({dp[(i - 1) * m + j - 1], dp[(i - 1) * m + j], dp[i * m + j - 1]}) + 1;
            }
        }
    }

    return dp[n * m - 1];
}

int main() {
    std::cout << "Enter the two strings:\n";
    std::string a, b;
    std::cin >> a >> b;

    std::cout << "The Levenshtein distance between " << a << " and " << b << " is: "
              << floydWarshall(a, b) << '\n';
}
