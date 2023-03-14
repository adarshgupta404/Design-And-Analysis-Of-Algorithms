#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int bSearch(int *arr, int l, int h, int x)
{
    if (l > h)
        return -1;
    else
    {
        int mid = (l + h) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            bSearch(arr, l, mid - 1, x);
        else
            bSearch(arr, mid + 1, h, x);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;
    cout << "The Element is present at index " << bSearch(arr, 0, n - 1, x);
    return 0;
}