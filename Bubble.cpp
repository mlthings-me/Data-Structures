#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n)
{
    int j = n;
    while (j > 0)
    {
        for (int i = 0; i < j; i++)
        {
            if (arr[i + 1] < arr[i])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
        j--;
    }
    for (int i = 1; i < n + 1; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {24, 48, 72, 12, 36, 60};
    int n = 6;
    cout << "Original Array:";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "Sorted array:";
    bubbleSort(arr, n);
}
