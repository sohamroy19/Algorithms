/**
 * Worst case : O(nlogn)
 * Average    : O(nlogn)
 * Best case  : O(nlogn)
 * 
 * Space      : O(n)
 */

#include <iostream>
#include <vector>

template <class T>
void merge(std::vector<T> &arr, int first, int mid, int last);

template <class T>
void mergeSort(std::vector<T> &arr, int first = 0, int last = -1) {
    if (last == -1) last = arr.size() - 1;

    if (first < last) {
        int mid = (first + last) / 2;

        mergeSort<T>(arr, first, mid);
        mergeSort<T>(arr, mid + 1, last);
        merge<T>(arr, first, mid, last);
    }
}

template <class T>
void merge(std::vector<T> &arr, int first, int mid, int last) {
    std::vector<T> leftArr(arr.begin() + first, arr.begin() + mid + 1);
    std::vector<T> rightArr(arr.begin() + mid + 1, arr.begin() + last + 1);

    int leftI = 0, rightI = 0;
    for (int i = first; i <= last; ++i) {
        if (rightI == rightArr.size() ||
            leftI < leftArr.size() && leftArr[leftI] < rightArr[rightI]) {
            arr[i] = leftArr[leftI++];
        } else {
            arr[i] = rightArr[rightI++];
        }
    }
}