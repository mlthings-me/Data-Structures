#include <iostream>
using namespace std;
void selectionSort(int *arr)
{
    for (int i = 0; i < 7; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < 8; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        int t = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = t;
    }
    for (int k = 0; k < 8; k++)
    {

        cout << arr[k] << " ";
    }
}
int main()
{
    int n;
    int arr[10] = {12, 67, 43, 78, 33, 93, 11, 23};
    selectionSort(arr);
}