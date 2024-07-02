#include <bits/stdc++.h>
using namespace std;

// Brute force with extra space-Time Complexity: O(n+m) + O(n+m), where n and m are the sizes of the given arrays.
// Reason: O(n+m) is for copying the elements from arr1[] and arr2[] to arr3[]. And another O(n+m) is for filling back the two given arrays from arr3[].
// Space Complexity: O(n+m) as we use an extra array of size n+m.
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
{
    int n = a.size();
    int m = b.size();
    int i = 0, j = 0;
    vector<long long> ans;
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            ans.push_back(a[i]);
            i++;
        }
        else
        {
            ans.push_back(b[j]);
            j++;
        }
    }

    while (i < n)
    {
        ans.push_back(a[i]);
        i++;
    }
    while (j < m)
    {
        ans.push_back(b[j]);
        j++;
    }

    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
            a[i] = ans[i];
        else
            b[i - n] = ans[i];
    }
}

// Optimal 1-Time Complexity: O(min(n, m)) + O(n*logn) + O(m*logm), where n and m are the sizes of the given arrays.
// Reason: O(min(n, m)) is for swapping the array elements. And O(n*logn) and O(m*logm) are for sorting the two arrays.
// Space Complexity: O(1) as we are not using any extra space.
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
{
    int n = a.size();
    int m = b.size();
    int i = n - 1, j = 0;
    while (i > 0 && j < m)
    {
        if (a[i] > b[j])
        {
            swap(a[i], b[j]);
            i--, j++;
        }
        else if (a[i] <= b[j])
        {
            i--, j++;
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

// Optimal-2 Time Complexity: O((n+m)*log(n+m)), where n and m are the sizes of the given arrays.
// Reason: The gap is ranging from n+m to 1 and every time the gap gets divided by 2. So, the time complexity of the outer loop will be O(log(n+m)). Now, for each value of the gap, the inner loop can at most run for (n+m) times. So, the time complexity of the inner loop will be O(n+m). So, the overall time complexity will be O((n+m)*log(n+m)).
// Space Complexity: O(1) as we are not using any extra space.
void swapIfGreater(vector<long long> &a, vector<long long> &b, int indx1, int indx2){
	if(a[indx1]> b[indx2]){
		swap(a[indx1],b[indx2]);
	}
}
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	int n= a.size();
	int m= b.size();
	int len= n+m;
	int gap= (len/2)+ (len%2);
	while(gap>0){
		int left=0;
		int right= left+gap;
		while(right<len){
			// arr1 && arr2
			if(left<n && right>=n){
				swapIfGreater(a, b, left, right-n);
			}
			// arr2 && arr2
			else if(left>=n){
				swapIfGreater(b, b, left-n, right-n);
			}
			// arr1 & arr1
			else{
				swapIfGreater(a, a, left, right);
			}
			left++, right++;
		}
		if(gap==1) break;
		gap=(gap/2)+ (gap%2);
	}
	
}