#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(n) where n is the size of elements of the input array.Auxiliary Space: O(1) 
    // vector<int> moveZeros(vector<int> nums){
    //     int count=0;
    //     for(int i=0; i<nums.size(); i++){
    //         if(nums[i]!=0){
    //             nums[count++]=nums[i];
    //         }
    //     }
    //     while(count<nums.size()){
    //         nums[count++]=0;
    //     }
    //     return nums;
    // }

    // 
vector<int> moveZeros(vector<int> A) { 
    int n=A.size();
    int B[n]; 
    int j = 0; 
    int count = 0; 
    for (int i = 0; i < n; i++) { 
        if (A[i] != 0) { 
            B[j] = A[i]; 
            j++; 
        } 
        else { 
            count++; 
        } 
    } 
    while (count > 0) { 
        B[j] = 0; 
        count--; 
        j++; 
    } 
  
    for (int i = 0; i < n; i++) { 
        A[i] = B[i]; 
    } 
  
    return A;
}
// 2-pointers Approach-O(n)
// vector<int> moveZeroes(vector<int> &nums)
// {
//     if (nums.size() == 1)
//         return nums;

//     else
//     {
//         int i = 0, j = i + 1;
//         while (j < nums.size())
//         {
//             if (nums[i] != 0 && nums[j] != 0)
//             {
//                 i++, j++;
//             }
//             else if (nums[i] == 0 && nums[j] == 0)
//             {
//                 j++;
//             }
//             else if (nums[i] != 0 && nums[j] == 0)
//             {
//                 i++;
//             }
//             else
//             {
//                 swap(nums[i], nums[j]);
//             }
//         }
//         return nums;
//     }
// }


int main()
{
    vector<int> arr, ans;
    int ele;
    cout << "Enter the element in array" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> ele;
        arr.push_back(ele);
    }
    
    ans = moveZeros(arr);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}