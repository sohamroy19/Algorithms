/**
 * Worst case : O(n)
 * Average    : O(n)
 * Best case  : O(1)
 * 
 * Space      : O(1)
 */

#include <vector>

template <class T>
int linearSearch(const std::vector<T> &arr, const T &t) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == t) return i;
    }

    return -1; // if no element matches
}