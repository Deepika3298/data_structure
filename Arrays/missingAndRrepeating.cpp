#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N2), where N = size of the given array.
// Reason: Here, we are using nested loops to count occurrences of every element between 1 to N.
// Space Complexity: O(1) as we are not using any extra space.
vector<int> findTwoElement(vector<int> arr, int n)
{
    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == i)
            {
                cnt++;
            }
            if (cnt == 2)
                repeating = i;
            else if (cnt == 0)
                missing = i;

            if (repeating != -1 && missing != -1)
                break;
        }
    }
    return {repeating, missing};
}

// Time Complexity: O(2N), where N = the size of the given array.
//  Reason: We are using two loops each running for N times. So, the time complexity will be O(2N).
//  Space Complexity: O(N) as we are using a hash array to solve this problem.
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    int n = a.size();
    vector<int> ans(2);
    vector<int> hashArray(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        hashArray[a[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (hashArray[i] == 2)
        {
            ans[0] = i;
        }
        if (hashArray[i] == 0)
        {
            ans[1] = i;
        }
    }

    return ans;
}
// Using maths.
// Time Complexity: O(N), where N = the size of the given array.
// Reason: We are using only one loop running for N times. So, the time complexity will be O(N).
// Space Complexity: O(1) as we are not using any extra space to solve this problem.
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    long long n = a.size();
    //   Summation of n natural numbers
    long long SN = (n * (n + 1)) / 2;
    //   Summation of square of n natural numbers
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++)
    {
        //   Summation of array elements
        S = S + a[i];
        //   Summation of square of array elements
        S2 = S2 + (a[i] * a[i]);
    }
    // x-y
    long long val1 = S - SN;
    // x+y
    long long val2 = S2 - S2N;
    val2 = val2 / val1;
    // value of x and y on solving 2 equations
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}

// Using Xor
// Time Complexity: O(N), where N = the size of the given array.
// Reason: We are just using some loops running for N times. So, the time complexity will be approximately O(N).
// Space Complexity: O(1) as we are not using any extra space to solve this problem.
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    long long n = a.size();
    int xr = 0;
    // Find Xor of Array elements and 1 to n elements
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }
    // Find Differentiating bit
    int bitOne = 0;
    while (1)
    {
        if ((xr & (1 << bitOne)) != 0)
        {
            break;
        }
        bitOne++;
    }
    // club the array and n elements into 0 and 1 bit club
    int zero = 0; // consider as repeating element
    int one = 0;  // consider as missing element
    for (int i = 0; i < n; i++)
    {
        // 1 club
        if ((a[i] & (1 << bitOne)) != 0)
        {
            one = one ^ a[i];
        }
        // 0 club
        else
        {
            zero = zero ^ a[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        // 1 club
        if ((i & (1 << bitOne)) != 0)
        {
            one = one ^ i;
        }
        // 0 club
        else
        {
            zero = zero ^ i;
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == zero)
            count++;
    }

    if (count == 2)
        return {zero, one};
    else
        return {one, zero};
}