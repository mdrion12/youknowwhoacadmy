#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
vector<int> spf(N);
vector<ll> v[N]; // ✅ long long vector

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

void get(int x)
{
    int orig = x;
    int div = 1;
    while (x > 1)
    {
        int p = spf[x], e = 0;
        while (x % p == 0)
        {
            e++;
            x /= p;
        }
        div *= (2 * e + 1); // divisor count for square = (2*e + 1)
    }
    v[div].push_back(1LL * orig * orig);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieveSPF();

    for (ll i = 1; i * i <= 1e10; i++) // ✅ overflow-safe
    {
        get(i);
    }

    int t;
    cin >> t;
    while (t--)
    {
        int k;
        ll l, r;
        cin >> k >> l >> r;
        if (v[k].empty())
        {
            cout << "0\n";
            continue;
        }
        int ans = upper_bound(v[k].begin(), v[k].end(), r) - lower_bound(v[k].begin(), v[k].end(), l);
        cout << ans << '\n';
    }

    return 0;
}
