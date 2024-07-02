#include <bits/stdc++.h>
using namespace std;

int team(vector <int> &skill, int n)
{
    int count=0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(skill[i]>(2*skill[j])) count++;
        }
    }
    return count;
}

// T.C.- (2nlogn) & S.C.-O(n)
void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<= high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low; i<=high; i++){
        arr[i]= temp[i-low];
    }
}
int countPairs(vector<int> &arr, int low, int mid, int high){
    int count=0;
    int right=mid+1;
    for(int i=low; i<=mid; i++){
        while( right<=high && arr[i]>(2*arr[right])) right++;

        count+=(right-(mid+1));
    }
    return count;
}


int merge_sort(vector<int> &arr, int low, int high){
    int count=0;
    if(low>=high) return count;
    int mid=(low+high)/2;
    count+=merge_sort(arr, low, mid);
    count+=merge_sort(arr, mid+1, high);
    count+=countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);

    return count;
}
int team(vector <int> & skill, int n)
{
    return merge_sort(skill, 0, n-1);
}
