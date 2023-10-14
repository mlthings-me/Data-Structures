#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int currentElement = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > currentElement)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = currentElement;
    }
}
int main()
{
    int arr[] = {9, 6, 7, 2, 5, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
