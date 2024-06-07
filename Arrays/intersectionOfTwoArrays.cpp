#include <bits/stdc++.h>
using namespace std;

// Brute force Approach
// vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m){
//     vector<int> ans;
//     vector<int> visited(arr2.size(), 0);
//     for (int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             if( arr1[i] == arr2[j] && visited[j]==0 ){
//                 ans.push_back(arr2[j]);
//                 visited[j]=1;
//                 break;
//             }
//             else if (arr2[j] > arr1[i]) break;
//         }
//     }
//     return ans;
// }

// Time Complexity : O(m + n) & Auxiliary Space: O(1)
// vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
// {
//     int i = 0, j = 0;

//     vector<int> result;

//     while (i < n && j < m)
//     {

//         if (arr1[i] == arr2[j])
//         {

//             result.push_back(arr1[i]);

//             i++;

//             j++;
//         }

//         else if (arr1[i] > arr2[j])

//             j++;

//         else

//             i++;
//     }

//     return result;
// }


// For handling duplicates in result
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m){
    set<int> st;
    for (int i=0; i<n ; i++){
        st.insert(arr1[i]);
    }
    vector<int> res;

    for(int i=0; i<m; i++){
        if(st.find(arr2[i])!= st.end()){
            res.push_back(arr2[i]);
            st.erase(arr2[i]);
        }
    }

    return res;
}

int main()
{
    vector<int> arr1, arr2, ans;
    int ele;
    cout << "Enter the element in array" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> ele;
        arr1.push_back(ele);
    }
    int n = arr1.size();

    cout << "Enter the element in array" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> ele;
        arr2.push_back(ele);
    }
    
    int m = arr2.size();
    ans = findArrayIntersection(arr1, n, arr2, m);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}