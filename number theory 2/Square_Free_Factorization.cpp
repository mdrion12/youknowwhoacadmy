#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
const int N = 1e6 + 5;
int spf[N];
void sieveSPF()
{
    for (ll i = 2; i < N; ++i)
        spf[i] = i;
    for (ll i = 2; i * i < N; ++i)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < N; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}
map<ll, ll> getFactorization(ll x)
{
    map<ll, ll> mp;
    while (x != 1)
    {
        mp[spf[x]]++;
        x /= spf[x];
    }
    return mp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieveSPF();
    int t;
    cin >> t;
    while (t--)
    {
        ll v;
        cin >> v;
        map<ll, ll> mp = getFactorization(v);
        ll ans = 0;
        for (auto it : mp)
        {
            ans = max(ans, it.second);
        }
        cout << ans << "\n";
    }
    return 0;
}