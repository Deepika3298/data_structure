#include <bits/stdc++.h>
using namespace std;

// Worst case Time Complexity- O(n2) depends on gap sequence.Best case complexity is Ω(n log(n)).Average Case Complexity: O(n*log n)~O(n1.25)
// Space Complexity- O(1)
void shell_sort(int arr[], int n){
    for(int gap=n/2; gap>=1; gap/=2){
        for(int j=gap; j<n; j++){
            for(int i=j-gap; i>=0; i-=gap){
                if(arr[i+gap]>arr[i]){
                    break;
                } 
                else{
                    swap(arr[i+gap], arr[i]);
                }
            }
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
    shell_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}