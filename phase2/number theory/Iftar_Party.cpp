
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
vector<ll> divisors(ll n)
{
    vector<ll> divisor;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divisor.push_back(i);
            if (i != n / i)
            {
                divisor.push_back(n / i);
            }
        }
    }
    sort(divisor.begin(), divisor.end());
    return divisor;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        ll n, l;
        cin >> n >> l;
        vector<ll> v = divisors(n - l);
        if (v.size() == 0)
        {
            cout << "Case " << i << ": " << "impossible" << "\n ";
            continue;
        }
        cout << "Case " << i << ": ";
        int count = 0;
        for (auto it : v)
        {
            if (it > l)
            {
                cout << it << " ";
                count++;
            }
        }
        if (count == 0)
        {
            cout << "impossible";
        }
        cout << "\n";
    }

    return 0;
}