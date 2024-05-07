#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    int x, count = 0;
    int ele;
    cout << "Enter the elements" << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> ele;
        v.push_back(ele);
    }

    cout << "Enter the element you want to check" << endl;
    cin >> x;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > x)
        {
            count++;
        }
    }
    cout << count;

    return 0;
}