/**
 * Worst case : O(n^2) comparisons, O(n^2) swaps
 * Average    : O(n^2) comparisons, O(n^2) swaps
 * Best case  :  O(n)  comparisons,  O(1)  swaps
 * 
 * Space      :  O(1)
 */

#include <vector>

template <class T>
void bubbleSort(std::vector<T> &arr) {
    for (int i = arr.size(); i > 1; --i) {
        bool swapped = false;

        for (int j = 1; j < i; ++j) {
            if (arr[j - 1] > arr[j]) {
                std::swap<T>(arr[j - 1], arr[j]);
                swapped = true;
            }
        }

        if (!swapped) return; // if already done sorting
    }
}
