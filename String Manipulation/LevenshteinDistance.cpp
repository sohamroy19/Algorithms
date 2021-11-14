/**
 * https://en.wikipedia.org/wiki/Levenshtein_distance
 */

#include <iostream>
#include <string_view>

int levenshtein(std::string_view a, std::string_view b) {
    if (a.empty()) return b.size();
    if (b.empty()) return a.size();

    if (a[0] == b[0]) return levenshtein(a.substr(1), b.substr(1));

    return 1 + std::min(
                   std::min(levenshtein(a.substr(1), b), levenshtein(a, b.substr(1))),
                   levenshtein(a.substr(1), b.substr(1)));
}

int main() {
    std::cout << "Enter the two strings:\n";
    std::string a, b;
    std::cin >> a >> b;

    std::cout << "The Levenshtein distance between " << a << " and " << b << " is: "
              << levenshtein(a, b) << '\n';
}