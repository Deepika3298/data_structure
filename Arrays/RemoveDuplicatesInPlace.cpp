#include <bits/stdc++.h>
using namespace std;

    //Naive Approach(By taking extra Space)- Time Complexity: O(N) & Auxiliary Space: O(N)
    // int removeDuplicates(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n == 0 || n == 1)
    //         return n;

    //     vector<int> temp(n);

    //     int j = 0;
    //     for (int i = 0; i < n - 1; i++)
    //         if (nums[i] != nums[i + 1])
    //             temp[j++] = nums[i];

    //     temp[j++] = nums[n - 1];

    //     for (int i = 0; i < j; i++)
    //         nums[i] = temp[i];

   
    //     nums.resize(j);

    //     return j;
    // }


    // 2-pointers Approach- Time Complexity- O(N) & Space Complexity- O(1)
    // int removeDuplicates(vector<int>& nums) {
    //     int i=0;
    //     for(int j=i+1; j<nums.size(); j++){
    //         if( nums[i] != nums[j] ){
    //             nums[i+1]=nums[j];
    //             i++;
    //         }
    //     }
    //     return i+1;
    // }

    // Set Approach- TimeComplexity- O(N) & Space Complexity- O(N)
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        for(int i=0; i<nums.size(); i++){
            st.insert(nums[i]);
        }

        int index=0;
        for(auto el: st){
            nums[index]=el;
            index++;
        }

        return index;
    }


    int main(){
        vector<int>arr;
    int ele;
    cout<<"Enter the element in array"<<endl;
    for(int i=0; i<10; i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<removeDuplicates(arr);
    
    return 0;
    }