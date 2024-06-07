#include <bits/stdc++.h>
using namespace std;

// Brute Force: Finding all possible permutations. 
// Approach :For finding, all possible permutations, it is taking N!xN. N represents the number of elements present in the input array. Also for searching input arrays from all possible permutations will take N!. Therefore, it has a Time complexity of O(N!xN).
// Space Complexity :Since we are not using any extra spaces except stack spaces for recursion calls. So, it has a space complexity of O(1).

// Step 1: Find all possible permutations of elements present and store them.
// Step 2: Search input from all possible permutations.
// Step 3: Print the next permutation present right after it.

// Better Approach-C++ provides an in-built function called next_permutation() which directly returns the lexicographically next greater permutation of the input.
int main() {
    int arr[] = {1,3,2};
    
    next_permutation(arr,arr+3);//using in-built function of C++
    
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    
    return 0;
}

// Optimal Approach- Time Complexity- O(3N) & Space complexity- O(1)
void nextPermutation(vector<int> &nums)
{
    int n = nums.size();

    int ind = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            ind = i;
            break;
        }
    }

    if (ind == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    else
    {
        for (int i = n - 1; i > ind; i--)
        {
            if (nums[i] > nums[ind])
            {
                swap(nums[i], nums[ind]);
                break;
            }
        }
    }

    reverse(nums.begin() + ind + 1, nums.end());
    return;
}