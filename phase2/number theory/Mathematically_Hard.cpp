#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
const int N = 5e6 + 9;
int spf[N];
void sieveSPF()
{
    for (int i = 2; i < N; ++i)
        spf[i] = i;
    for (int i = 2; i * i < N; ++i)
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
unsigned long long pref[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieveSPF();
    for (ll i = 1; i < N; i++)
    {
        ll x = i, phi = 1;
        while (x > 1)
        {
            ll p = spf[x], pw = 1;
            while (x % p == 0)
            {
                pw *= p;
                x /= p;
            }
            phi *= (pw / p) * (p - 1);
        }
        pref[i] = pref[i - 1] + 1ll * phi * phi;
    }
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        ll a, b;
        cin >> a >> b;
        cout << "Case " << i << ": " << pref[b] - pref[a - 1] << "\n";
    }
    return 0;
}