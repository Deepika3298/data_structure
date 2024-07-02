 #include <bits/stdc++.h>
using namespace std;

// brute force Approach-Time Complexity: O(N2) and Space Complexity- O(1)
vector<int> majorityElement(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(ans.size()==0 || ans[0]!=nums[i]){
                int count=0;
                for(int j=0; j<n; j++){
                    if(nums[j]==nums[i])
                    count++;
                }
                if(count>floor(n/3)) ans.push_back(nums[i]);
            }

        }
        return ans;
    }

// Time Complexity: O(N*logN), where N = size of the given array.
// Reason: We are using a map data structure. Insertion in the map takes logN time. And we are doing it for N elements. So, it results in the first term O(N*logN).
// If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be O(N2).
// Space Complexity: O(N) as we are using a map data structure.     
// vector<int> majorityElement(vector<int> &nums)
// {
//     vector<int> ans;
//     int n = nums.size();
//     map<int, int> mp;
//     for (int i = 0; i < n; i++)
//     {
//         mp[nums[i]]++;
//     }
//     for (auto el : mp)
//     {
//         if (el.second > floor(n / 3))
//             ans.push_back(el.first);
//     }

//     return ans;
// }

vector<int> majorityElement(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();
    map<int, int> mp;
    int mini= int(n/3)+1;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;

        if(mp[nums[i]]==mini) ans.push_back(nums[i]);
    }
    

    return ans;
}

// Optimal Approach- Time Complexity: O(N) + O(N), where N = size of the given array.
// Reason: The first O(N) is to calculate the counts and find the expected majority elements. The second one is to check if the calculated elements are the majority ones or not.
// Space Complexity: O(1) 
vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int mini= int(n/3)+1;
        int cnt1=0, cnt2=0, el1=INT_MIN, el2=INT_MIN;
        for(int i=0; i<n; i++){
            if(cnt1==0 && el2!=nums[i]){
                cnt1=1;
                el1=nums[i];
            } else if(cnt2==0 && el1!=nums[i]){
                cnt2=1;
                el2= nums[i];
            } else if(nums[i]==el1){
                cnt1++;
            } else if(nums[i]==el2){
                cnt2++;
            } else {
                cnt1--, cnt2--;
            }
        }

        int count1=0, count2=0;
        for(int i=0; i<n; i++){
            if(el1==nums[i]) count1++;
            else if(el2==nums[i]) count2++;
        }
        if(count1>=mini) ans.push_back(el1);
        if(count2>=mini) ans.push_back(el2);

        return ans;
    }


int main(){
    int n;
    cin>>n;
    vector<int> nums;
    int temp;
    cout<<"Enter the elements in an array"<<endl;
    for(int i=0; i<n; i++){
        cin>>temp;
        nums.push_back(temp);
    }

    vector<int>ans= majorityElement(nums);

    for (auto it : ans)
        cout << it << " "<<endl;

    return 0;    
}