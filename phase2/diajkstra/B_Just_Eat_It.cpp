#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO\n";
#define yes cout << "YES\n";

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> v(n);
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
        }

        bool ok = true;
        ll pref = 0, suff = 0;

        // check prefix sums (excluding full array)
        for (int i = 0; i < n - 1; i++)
        {
            pref += v[i];
            if (pref >= sum)
                ok = false;
        }

        // check suffix sums (excluding full array)
        for (int i = n - 1; i > 0; i--)
        {
            suff += v[i];
            if (suff >= sum)
                ok = false;
        }

        if (ok)
            yes else no
    }
    return 0;
}
