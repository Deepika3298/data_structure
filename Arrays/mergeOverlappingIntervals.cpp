#include <bits/stdc++.h>
using namespace std;

// Brute Force
// Time Complexity: O(N*logN) + O(2*N), where N = the size of the given array.
// Reason: Sorting the given array takes  O(N*logN) time complexity. Now, after that, we are using 2 loops i and j. But while using loop i, we skip all the intervals that are merged with loop j. So, we can conclude that every interval is roughly visited twice(roughly, once for checking or skipping and once for merging). So, the time complexity will be 2*N instead of N2.
// Space Complexity: O(N), as we are using an answer list to store the merged intervals.
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];
        if (!ans.empty() && end <= ans.back()[1])
            continue;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j][0] <= end)
            {
                end = max(end, arr[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start, end});
    }

    return ans;
}

// Optimal Approach-Time Complexity: O(N*logN) + O(N), where N = the size of the given array.
// Reason: Sorting the given array takes  O(N*logN) time complexity. Now, after that, we are just using a single loop that runs for N times. So, the time complexity will be O(N).
// Space Complexity: O(N), as we are using an answer list to store the merged intervals. 
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }

    return ans;
}