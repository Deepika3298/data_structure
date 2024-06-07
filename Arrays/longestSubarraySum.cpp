#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N3) & Space complexity- O(1)
// int longestSubarrayWithSumK(vector<int> a, long long k)
// {
//     int n = a.size();
//     int len = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             long long sum = 0;
//             for (int K = i; K <= j; K++)
//             {
//                 sum += a[K];
//             }
//             if (sum == k)
//             {
//                 len = max(len, j - i + 1);
//             }
//         }
//     }
//     return len;
// }

// Time Complexity: O(N2) & Space complexity- O(1)
// int longestSubarrayWithSumK(vector<int> &a, long long k)
// {
//     int n = a.size();

//     int len = 0;
//     for (int i = 0; i < n; i++)
//     {
//         long long s = 0;
//         for (int j = i; j < n; j++)
//         {
//             s += a[j];

//             if (s == k)
//                 len = max(len, j - i + 1);
//         }
//     }
//     return len;
// }


// Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
// Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will be O(N)(though in the worst case, unordered_map takes O(N) to find an element and the time complexity becomes O(N2)) but if we are using a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array.
// Space Complexity: O(N) as we are using a map data structure.
int longestSubarrayWithSumK(vector<int> a, long long k) {
   int n = a.size(); // size of the array.

    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        long long rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}


// Time Complexity: O(2*N), where N = size of the given array.
// Reason: The outer while loop i.e. the right pointer can move up to index n-1(the last index). Now, the inner while loop i.e. the left pointer can move up to the right pointer at most. So, every time the inner loop does not run for n times rather it can run for n times in total. So, the time complexity will be O(2*N) instead of O(N2).
// Space Complexity: O(1) as we are not using any extra space.
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int n = a.size(); 
    int left =0, right=0;
    
    long long sum = a[0];
    int maxLen = 0;
    while(right<n){
        while(left<=right && sum>k){
            sum-=a[left];
            left++;
        }
        
        if(sum==k) maxLen= max(maxLen, (right-left+1));

        right++;
        if(right<n)sum+=a[right];
    }

    return maxLen;
}

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = longestSubarrayWithSumK(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}