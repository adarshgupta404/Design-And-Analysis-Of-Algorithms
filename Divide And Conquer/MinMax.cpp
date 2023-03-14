#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void MinMax(int *arr, int &min, int &max, int l, int h)
{
    int max1, min1;
    if (l == h)
        min = max = arr[l];
    else
    {
        if (l == h - 1)
        {
            if (arr[l] < arr[h])
            {
                max = arr[h];
                min = arr[l];
            }
            else
            {
                min = arr[h];
                max = arr[l];
            }
        }
        else
        {
            int mid = (l + h) / 2;
            MinMax(arr, min, max, l, mid);
            max1 = max, min1 = min;
            MinMax(arr, min, max, mid + 1, h);
            if(max < max1)
                max = max1;
            if(min > min1)
                min = min1;
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 8, 9, 10, 11, 12, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min = INT_MAX, max = INT_MIN;
    MinMax(arr, min, max, 0, n - 1);
    cout << "Max Term " << max << endl;
    cout << "Min Term " << min;
    return 0;
}