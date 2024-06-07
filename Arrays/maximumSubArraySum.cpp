#include <bits/stdc++.h>
using namespace std;

// Brute force Approach
// Time complexity-O(N3) and space complexity- O(1)
int maxSubArray(vector<int> &nums){
    int n=nums.size();
    int maxi=INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int sum=0;
            for(int k=i; k<=j; k++){
                sum+=nums[k];
            }
            maxi=max(maxi,sum);
        }
    }
    if(maxi<0) maxi=0; //if all numbers are negative
    return maxi;
}

// Better Approach
// Time complexity-O(N2) and space complexity- O(1)
int maxSubArray(vector<int> &nums){
    int n=nums.size();
    int maxi=INT_MIN;
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum+=nums[j];
            maxi=max(maxi,sum);
        }
    }
    if(maxi<0) maxi=0; //if all numbers are negative
    return maxi;
}


// KADANE'S ALGORITHM
// Kadane's algorithm tells us that there is a way to calculate the largest sum
// by only making one pass on the array, bringing the complexity down to linear time. Let's look at how that can be done.
// Since we are looking for the largest sum, it is a good idea to avoid negative numbers because we know that contradicts what the question is asking for.
// Negative numbers will only make our sum smaller.
// Kadane's algorithm runs one for loop over the array and at the beginning of each iteration, if the current sum is negative, it will reset the current sum to zero.
// This way, we ensure a one-pass and solve the problem in linear time.
// Time Complexity: O(N), where N = size of the array. Space Complexity: O(1) as we are not using any extra space.
int maxSubArray(vector<int> &nums)
{
    int maxi = INT_MIN;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        if (sum > maxi)
        {
            maxi = sum;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }

    if(maxi<0) maxi=0; //if all numbers are negative

    return maxi;
}

// To print maximum subArray
long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {

        if (sum == 0) start = i; // starting index

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    //printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]n";

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    int len = maxSubArray(a);
    cout << "The sum of the longest subarray is: " << len << "\n";
    return 0;
}