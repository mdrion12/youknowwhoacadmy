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
    int n;
    cin >> n;
    vector<int> v(n + 1), exit(n + 1);
    vector<int> c;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> exit[i];
        mp[exit[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int val = mp[v[i]];
        c.push_back(val);
    }
    int mx = 0;
    int ans = 0;
    for (int i = 0; i < c.size(); i++)
    {
        if (c[i] < mx)
        {
            ans++;
        }
        mx = max(c[i], mx);
    }
    cout << ans << "\n";
    return 0;
}