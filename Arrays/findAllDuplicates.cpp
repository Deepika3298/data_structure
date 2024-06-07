#include <bits/stdc++.h>
using namespace std;
//Time complexity O(n) & space complexity O(n) 
vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> ans;
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(nums[i]) != mp.end())
        {
            mp[nums[i]]++;
        }
        else
        {
            mp[nums[i]] = 1;
        }
    }
    for (auto ele : mp)
    {
        if (ele.second > 1)
            ans.push_back(ele.first);
    }
    return ans;
}


// time complexity of O(n log n) & Space complexity- O(n)
// vector<int> findDuplicates(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());
//     vector<int> ans;
//     for (int i = 1; i < nums.size(); i++)
//     {
//         if (nums[i] == nums[i - 1])
//         {
//             if (ans.empty() || ans.back() != nums[i])
//             {
//                 ans.push_back(nums[i]);
//             }
//         }
//     }
//     return ans;
// }

// Space complexity- O(1)
// vector<int> findDuplicates(vector<int>& nums) {
//     sort(nums.begin(), nums.end());
//     vector<int> ans;
//     int prev = INT_MIN;

//     for (int num : nums) {
//         if (num == prev) {
//             ans.push_back(num);
//         }
//         prev = num;
//     }
//     return ans;
// }



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

    vector<int> ans = findDuplicates(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}