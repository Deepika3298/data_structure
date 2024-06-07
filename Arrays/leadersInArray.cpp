#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach- near O(n2) and space complexity- O(n)
vector<int> leaders(int a[], int n)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        bool leader = true;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[i])
            {
                leader = false;
            }
        }
        if (leader == true)
            ans.push_back(a[i]);
    }
    return ans;
}

// Brute Force Approach- near O(n) and space complexity- O(n)
vector<int> leaders(vector<int> &a) {
  int n = a.size();
  vector<int> ans;
  int maxi = INT_MIN;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] > maxi) {
      maxi = a[i];
      ans.push_back(a[i]);
    }
  }
  sort(ans.begin(), ans.end());
  return ans;
}