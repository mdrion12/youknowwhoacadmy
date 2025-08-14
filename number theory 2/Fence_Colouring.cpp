#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]]++;
        }
        int mx = INT_MIN;
        for (auto it : mp)
        {
            mx = max(mx, it.second);
        }
        if (mx == mp[1])
        {
            cout << n - mx << "\n";
        }
        else
        {
            cout << (n - mx) + 1 << "\n";
        }
    }
    return 0;
}