#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
const int N = 5e4 + 5;
const int m = 1e9 + 7;
ll spf[N];
void sieveSPF()
{
    for (ll i = 2; i < N; ++i)
        spf[i] = i;
    for (ll i = 2; i * i < N; ++i)
    {
        if (spf[i] == i)
        {
            for (ll j = i * i; j < N; j += i)
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
        int n;
        cin >> n;
        ll ans = 1;
        map<ll, ll> t;
        for (int i = 2; i <= n; i++)
        {
            map<ll, ll> mp = getFactorization(i);
            for (auto it : mp)
            {
                t[it.first] += it.second;
            }
        }
        for (auto it : t)
        {
            ans = 1ll * ans * (it.second + 1) % m;
        }
        cout << ans << "\n";
    }
    return 0;
}