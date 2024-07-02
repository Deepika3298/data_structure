#include <bits/stdc++.h>
using namespace std;

// Brute force approach- T.C.- O(n2) & S.C.- O(1)
int numberOfInversions(vector<int> &a, int n)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                count++;
        }
    }
    return count;
}

// Time Complexity: O(N*logN), where N = size of the given array.
// Reason: We are not changing the merge sort algorithm except by adding a variable to it. So, the time complexity is as same as the merge sort.
// Space Complexity: O(N), as in the merge sort We use a temporary array to store elements in sorted order.
int merge(vector<int> &arr, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    vector<int> ans;
    int count = 0;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            ans.push_back(arr[left]);
            left++;
        }
        else
        {
            ans.push_back(arr[right]);
            count += (mid - left + 1);
            right++;
        }
    }
    while (left <= mid)
    {
        ans.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        ans.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = ans[i - low];
    }
    return count;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int count = 0;
    if (low >= high)
        return count;
    int mid = (low + high) / 2;
    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += merge(arr, low, mid, high);
    return count;
}
int numberOfInversions(vector<int> &a, int n)
{
    return mergeSort(a, 0, n - 1);
}