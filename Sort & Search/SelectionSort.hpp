/**
 * Worst case : O(n^2) comparisons, O(n) swaps
 * Average    : O(n^2) comparisons, O(n) swaps
 * Best case  : O(n^2) comparisons, O(1) swaps
 * 
 * Space      :  O(1)
 */

#include <vector>

template <class T>
void selectionSort(std::vector<T> &arr) {
    for (int i = 0; i < arr.size() - 1; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }

        if (minIndex != i) {
            std::swap<T>(arr[i], arr[minIndex]);
        }
    }
}
