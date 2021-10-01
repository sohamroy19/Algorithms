/**
 * Worst case : O(n^2) comparisons, O(n^2) swaps
 * Average    : O(n^2) comparisons, O(n^2) swaps
 * Best case  :  O(n)  comparisons,  O(1)  swaps
 * 
 * Space      : O(1)
 */

#include <iostream>
#include <vector>

template <class T>
void insertionSort(std::vector<T> &arr) {
    for (int i = 1; i < arr.size(); ++i) {
        T temp = std::move(arr[i]);

        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = std::move(arr[j]); // shift larger element rightwards
            --j;
        }

        arr[j + 1] = std::move(temp);
    }
}