#include <bits/stdc++.h>
using namespace std;

// time complexity of O(n log n) & Auxiliary Space: O(1)
int findDuplicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int ans;
    int prev = INT_MIN;

    for (int num : nums)
    {
        if (num == prev)
        {
            ans = num;
        }
        prev = num;
    }
    return ans;
}
// bitwise operator but not work with array which has all duplicate elements
// Time Complexity: O(N) & Auxiliary Space: O(1)
int findDuplicate(vector<int>& nums) {
    int n= nums.size();
    int answer=0;
    for(int i=0; i<n; i++){
       answer=answer^nums[i];
    }
      
    for(int i=1; i<n; i++){
       answer=answer^i;
    }
    return answer;

    }

// Time Complexity: O(N) & Auxiliary Space: O(1)
// Floyd's Cycle Finding Algorithm:
// This is a clever algorithm that utilizes the concept of a slow and fast pointer to detect a cycle in the array. 
// Since there's a duplicate element, the elements create a cycle. 
// The function can identify the duplicate by finding the meeting point of the slow and fast pointers.
int findDuplicate(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    // Find the "entrance" to the cycle.
    int ptr1 = nums[0];
    int ptr2 = slow;
    while (ptr1 != ptr2)
    {
        ptr1 = nums[ptr1];
        ptr2 = nums[ptr2];
    }
    return ptr1;
}

int main()
{
    vector<int> arr;
    int ele;
    cout << "Enter the element in array" << endl;
    for (int i = 0; i < 8; i++)
    {
        cin >> ele;
        arr.push_back(ele);
    }

    cout << findDuplicate(arr);

    return 0;
}