#include <bits/stdc++.h>
using namespace std;
// Divide and conquer- assume a pivot all smaller on left side of pivot and larger on right side.
// Time Complexity- O(N log N) & Space Complexity- O(1)
int findPivot(vector<int> &arr, int low, int high) {
  int pivot = arr[low];
  int i = low;
  int j = high;
  while(i<j){
      while(arr[i]<=pivot && i<=high-1 ){
        i++;
      } 
      while(arr[j]>pivot && j>=low-1 ) j--;
      if(i<j){
          swap(arr[i], arr[j]);
      }
  }
  swap(arr[j], arr[low]);
  return j;
}

void quick_sort(vector<int> &arr, int low, int high) {
  if (low < high) {
    int partitionIdx = findPivot(arr, low, high);
    quick_sort(arr, low, partitionIdx - 1);
    quick_sort(arr, partitionIdx + 1, high);
  }
}

int main()
{
    int n;
    cin >> n;
    vector<int>arr;
    int temp;
    cout << "Enter the elements to sort" << endl;
    for (int i = 0; i < n; i++)
    {
        cin>>temp;
        arr.push_back(temp);
    }
    
    quick_sort(arr, 0, n-1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}