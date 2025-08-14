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
        ll d, n;
        cin >> d >> n;
        vector<ll> v(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            cin >> v[i];
        }
        vector<ll> prefix(n + 1);
        prefix[0] = 0;
        for (ll i = 1; i <= n; i++)
        {
            prefix[i] = (v[i] + prefix[i - 1]);
        }
        ll ans = 0;
        map<ll, ll> mp;
        for (ll i = 0; i <= n; i++)
        {
            prefix[i] %= d;
        }
        for (ll i = 0; i <= n; i++)
        {
            ans += mp[prefix[i]];
            mp[prefix[i]]++;
        }
        cout << ans << "\n";
    }
    return 0;
}