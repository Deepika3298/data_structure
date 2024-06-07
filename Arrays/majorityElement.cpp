#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(N2), where N = size of the given array. Reason: For every element of the array the inner loop runs for N times. And there are N elements in the array. 
// So, the total time complexity is O(N2). Space Complexity: O(1) as we use no extra space.
int majorityElement(vector<int> v){
    int n=v.size();
    int count=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(v[i]==v[j]) count++;
        }
        if(count>n/2) return i;
    }
    return -1;
}

// Time Complexity: O(N*logN) + O(N), where N = size of the given array.
// Reason: We are using a map data structure. Insertion in the map takes logN time. And we are doing it for N elements. So, it results in the first term O(N*logN). The second O(N) is for checking which element occurs more than floor(N/2) times. If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be O(N2).
// Space Complexity: O(N) as we are using a map data structure.
int majorityElement(vector<int> v) {
	map<int ,int>num;
	int size = v.size();
	for(int i=0;i<size;i++){
		num[v[i]]+=1;
	}
	for(auto it : num){
		if(it.second > size/2){
			return it.first;
		}
	}
}


// Time Complexity: O(N) + O(N), where N = size of the given array.
// Reason: The first O(N) is to calculate the count and find the expected majority element. The second one is to check if the expected element is the majority one or not.
// Note: If the question states that the array must contain a majority element, in that case, we do not need the second check. Then the time complexity will boil down to O(N).
// Space Complexity: O(1) as we are not using any extra space.
int majorityElement(vector<int> v) {
	int count=0, element=0;
    for(int i=0; i<v.size(); i++){
      if (count == 0) {
        count=1;
        element = v[i];
      }
        if(element==v[i]) count++;
        if(element!= v[i]) count--;
    }
    // If they ask to check that the majority element is present or not.
    // int cnt1 = 0;
    // for (int i = 0; i < v.size(); i++) {
    //     if (v[i] == element) cnt1++;
    // }
    // if (cnt1 > (v.size() / 2)) return element;
    // return -1;

    // If they said array has majority element
    return element;
}



int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}
