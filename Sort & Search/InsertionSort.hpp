#include <vector>

template <class T>
void insertionSort(std::vector<T> &arr) {
    for (int i = 1; i < arr.size(); ++i) {
        T temp = arr[i];

        int j = i - 1;
        while(j > 0 && arr[j] > arr[i]) {
            arr[j + 1] = arr[j]; // shift larger element rightwards
            --j;
        }

        arr[j + 1] = temp;
    }
}