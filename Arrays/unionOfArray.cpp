#include <bits/stdc++.h>
using namespace std;

// Using Set Time Complexity: O(m*log(m) + n*log(n)), where ‘m’ and ‘n’ are the size of the arrays and Auxiliary Space: O(m + n)
// vector < int > unionOfArray(vector < int > a, int n, vector < int > b, int m) {
//     set<int> s;
    
//     for (int i = 0; i < n; i++) {
//         s.insert(a[i]);
//     }
 
//     for (int i = 0; i < m; i++) {
//         s.insert(b[i]);
//     }

//     vector<int> vec(s.begin(), s.end());
 
//     return vec;
// }

// Using Map Time Complexity:O(m*log(m) + n*log(n)), where ‘m’ and ‘n’ are the size of the arrays and Auxiliary Space: O(m + n)
// vector < int > unionOfArray(vector < int > a, int n, vector < int > b, int m){
//     map<int,int> mp;

//     for(int i = 0; i < m; i++){
//         if( mp.find(a[i]) != mp.end() ){
//             mp[a[i]]++;
//         }
//         else{
//             mp[a[i]]=1;
//         }
//     }

//     for(int i = 0; i < n; i++){
//         if( mp.find(b[i]) != mp.end() ){
//             mp[b[i]]++;
//         }
//         else{
//             mp[b[i]]=1;
//         } 
//     }
//     vector<int> list;

//     for(auto ele: mp){
//         list.push_back(ele.first);
//     }

//     return list;
// }

// 2-pointers approach 
// T.C. - O(m+n) and S.C. - O(m+n)
vector < int > unionOfArray(vector < int > a, int n, vector < int > b, int m){
  int i = 0, j = 0; 
  vector < int > Union; 
  while (i < n && j < m) {
    if (a[i] <= b[j]) 
    {
      if ( Union.size() == 0 || Union.back() != a[i])
        Union.push_back(a[i]);
      i++;
    } else 
    {
      if ( Union.size() == 0 || Union.back() != b[j])
        Union.push_back(b[j]);
      j++;
    }
  }

  while (i < n) 
  {
    if (Union.back() != a[i])
      Union.push_back(a[i]);
    i++;
  }
  
  while (j < m) 
  {
    if (Union.back() != b[j])
      Union.push_back(b[j]);
    j++;
  }
    
    return Union;
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
    ans = unionOfArray(arr1, n, arr2, m);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}