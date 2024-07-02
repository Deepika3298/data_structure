#include <bits/stdc++.h>
using namespace std;


// SELECTION SORT- It select minimum from the array and swap with current element.
// Time Complexity- O(n2)
void selection_sort(int arr[], int n)
{
    int temp;
    for (int i = 0; i <= n - 2; i++)
    {
        int mini = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[mini])
                mini = j;
        }
        temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}

// BUBBLE SORT- It takes the maximum element to the end by adjacent swappings.
// Time Complexity- O(n2)(for avg and worst case) and O(N)(for best case) by doing Optimization.
void bubble_sort(int arr[], int n){
    for(int i=n-1; i>=1; i--){
        for(int j=0; j<i; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
// Optimized Version
void bubble_sort(int arr[], int n){
    for(int i=n-1; i>=1; i--){
        int flag=0;
        for(int j=0; j<i; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag=1;
            }
        }
        if(flag==0) break;
    }
}

// INSERTION ELEMENT- Takes an element and place it in its correct order.
// TIME COMPLEXITY-O(n2)(for avg and worst case) and O(N)(for best case)
void insertion_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the elements to sort" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // selection_sort(arr, n);
    // bubble_sort(arr, n);
    insertion_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}