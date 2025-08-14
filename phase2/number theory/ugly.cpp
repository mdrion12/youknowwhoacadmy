
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
const ll Maxn = 1e18;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll p1 = 1;
    vector<ll> v;
    for (ll i = 0; i < 60; i++, p1 *= 2)
    {
        ll p2 = 1;
        for (int j = 0; p1 * p2 <= Maxn; j++, p2 *= 3)
        {
            ll p3 = 1;
            for (ll k = 0; p1 * p2 * p3 <= Maxn; k++, p3 *= 5)
            {
                v.push_back(p1 * p2 * p3);
            }
        }
    }
    sort(v.begin(), v.end());
    cout << "The 1500'th ugly number is " << v[1499] << ".\n";
    return 0;
}