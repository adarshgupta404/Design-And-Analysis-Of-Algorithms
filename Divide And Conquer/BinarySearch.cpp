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
    printf("Binary Search\n");
    printf("Enter the number of Elements : ");
    int n;
    int x;
    scanf("%d",&n);
    int arr[n];
    printf("Enter the Elements : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter the number to be searched : ");
    scanf("%d",&x); 
    printf("The Element is present at index %d", bSearch(arr, 0, n - 1, x));
    return 0;
}