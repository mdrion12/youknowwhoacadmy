#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll multiple_under_n(ll k, ll n)
{
    return n / k;
}
ll solve(ll k, ll l, ll r)
{
    return multiple_under_n(k, r) - multiple_under_n(k, l - 1);
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, l, r;
    cin >> n >> m >> l >> r;
    ll g = __gcd(n, m);
    if ((long double)n / g > (long double)r / m)
    {
        cout << 0 << '\n';
        return 0;
    }
    ll lc = (n / g) * m;
    cout << solve(lc, l, r) << '\n';
    return 0;
}