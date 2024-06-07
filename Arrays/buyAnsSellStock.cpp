#include <bits/stdc++.h>
using namespace std;

// Brute Force- Time Complexity-O(n2) & Space complexity- O(1)
int maxProfit(vector<int> &prices)
{
    int mProfit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        int profit = 0;
        for (int j = i + 1; j < prices.size(); j++)
        {
            if (prices[j] - prices[i] > profit)
                profit = prices[j] - prices[i];
        }
        mProfit = max(mProfit, profit);
    }
    if (mProfit > 0)
        return mProfit;
    else
        return 0;
}


// Time complexity: O(n)&Space Complexity: O(1)
int maxProfit(vector<int> &prices)
{
    int maxPrice = 0;
    int minPrice = INT_MAX;
    for (int i = 0; i < prices.size(); i++)
    {
        minPrice = min(minPrice, prices[i]);
        maxPrice = max(maxPrice, prices[i] - minPrice);
    }
    if (maxPrice > 0)
        return maxPrice;
    else
        return 0;
}