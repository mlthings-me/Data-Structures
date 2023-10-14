#include <iostream>
using namespace std;

void mergeSort(int[], int, int);
void merge(int[], int, int, int);

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int array[] = {8, 4, 5, 1, 3, 9, 0, 2, 7, 6};
    int i;

    int size = sizeof(array) / sizeof(array[0]);
    printArray(array, size);

    mergeSort(array, 0, size - 1);
    printArray(array, size);
}

void mergeSort(int a[], int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;

        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

void merge(int a[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int index = left;
    int temp[10];

    while (i <= mid && j <= right)
    {
        if (a[i] < a[j])
        {
            temp[index] = a[i];
            i = i + 1;
        }
        else
        {
            temp[index] = a[j];
            j = j + 1;
        }
        index++;
    }

    if (i > mid)
    {
        while (j <= right)
        {
            temp[index] = a[j];
            index++;
            j++;
        }
    }
    else
    {
        while (i <= mid)
        {
            temp[index] = a[i];
            index++;
            i++;
        }
    }
    int p = left;

    while (p < index)
    {
        a[p] = temp[p];
        p++;
    }
}