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
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<ll> f(55, 0);
        for (int x : v)
            f[x]++;
        ll ans = 0;
        ll c2 = min(f[0], f[1]);
        ans += c2 * 2;
        f[0] -= c2;
        f[1] -= c2;
        ll c1 = f[0];
        ans += c1;
        f[0] = 0;
        for (int i = 0; i < 55; i++)
        {
            if (f[i] > 0)
            {
                ans += i * f[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
