#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N) + O(N), where N = size of the array. First O(N) for counting the number of 0’s, 1’s, 2’s, and second O(N) for placing them correctly in the original array.
// Space Complexity: O(1) as we are not using any extra space.
void sortArray(vector<int>& arr, int n)
{   
    int count0=0, count1=0, count2=0;
    for(int i=0; i<n; i++){
        if(arr[i]==0) count0++;
        else if(arr[i]==1) count1++;
        else count2++;
    }
    for(int i=0; i<count0; i++) arr[i]=0;
    for(int i=count0; i<count0+count1; i++) arr[i]=1;
    for(int i=count0+count1; i<n; i++) arr[i]=2;
}

// Time Complexity: O(N), where N = size of the given array.
// Reason: We are using a single loop that can run at most N times.
// Space Complexity: O(1) as we are not using any extra space.
// void sortArray(vector<int>& arr, int n)
// {   
//     int low= 0, mid=0, high=n-1;
//     while(mid<=high){
//         if(arr[mid]==0) {
//             swap(arr[low],arr[mid]);
//             low++, mid++;
//         }
//         else if(arr[mid]==1){
//             mid++;
//         }
//         else if(arr[mid]==2){
//             swap(arr[mid],arr[high]);
//             high--;
//         }
//     }
// }

void sortArray(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        int temp;
        while(mid<=high){
            switch(nums[mid]){
                case 0: {
                    temp = nums[mid];
                    nums[mid] = nums[low];
                    nums[low] = temp;
                    low++;
                    mid++;
                    break;
                }
                case 1: {
                    mid++;
                    break;
                }
                case 2: {
                    temp = nums[mid];
                    nums[mid] = nums[high];
                    nums[high] = temp;
                    high--;
                    break;
                }
            }
        }
    }
int main()  
{
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}