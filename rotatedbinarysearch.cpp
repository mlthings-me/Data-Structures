#include <iostream>

int binarySearch(int arr[], int target, int s, int e) {
    if (s > e) {
        return -1;
    }
    int m = s + (e - s) / 2;
    if (arr[m] == target) {
        return m;
    }
    if (arr[s] <= arr[m]) {
        if (target >= arr[s] && target <= arr[m]) {
            return binarySearch(arr, target, s, m - 1);
        } else {
            return binarySearch(arr, target, m + 1, e);
        }
    }
    if (target >= arr[m] && target <= arr[e]) {
        return binarySearch(arr, target, m + 1, e);
    }
    return binarySearch(arr, target, s, m - 1);
}

int main() {
    int arr[] = {5, 6, 7, 8, 9, 1, 2, 3};
    int target = 2;
    int length = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, target, 0, length - 1);

    if (result != -1) {
        std::cout << "Element " << target << " found at index " << result << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the array." << std::endl;
    }

    return 0;
}
