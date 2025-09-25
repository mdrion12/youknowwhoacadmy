#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 9;
const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;

int power(long long n, long long k, int mod)
{
    int ans = 1 % mod;
    n %= mod;
    if (n < 0)
        n += mod;
    while (k)
    {
        if (k & 1)
            ans = (long long)ans * n % mod;
        n = (long long)n * n % mod;
        k >>= 1;
    }
    return ans;
}

int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void prec()
{
    pw[0] = {1, 1};
    for (int i = 1; i < N; i++)
    {
        pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
    }
    ip1 = power(p1, mod1 - 2, mod1);
    ip2 = power(p2, mod2 - 2, mod2);
    ipw[0] = {1, 1};
    for (int i = 1; i < N; i++)
    {
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
    }
}

pair<int, int> pref[N];
void build(const string &s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        pref[i].first = 1LL * (int)s[i] * pw[i].first % mod1;
        if (i)
            pref[i].first = (pref[i].first + pref[i - 1].first) % mod1;
        pref[i].second = 1LL * (int)s[i] * pw[i].second % mod2;
        if (i)
            pref[i].second = (pref[i].second + pref[i - 1].second) % mod2;
    }
}

pair<int, int> get_hash(int i, int j)
{
    assert(i <= j);
    pair<int, int> hs({0, 0});
    hs.first = pref[j].first;
    if (i)
        hs.first = (hs.first - pref[i - 1].first + mod1) % mod1;
    hs.first = 1LL * hs.first * ipw[i].first % mod1;
    hs.second = pref[j].second;
    if (i)
        hs.second = (hs.second - pref[i - 1].second + mod2) % mod2;
    hs.second = 1LL * hs.second * ipw[i].second % mod2;
    return hs;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    prec();
    build(s);

    vector<int> v;
    int n = s.size();
    for (int i = 1; i <= n; i++)
    {
        if (get_hash(0, i - 1) == get_hash(n - i, n - 1))
        {
            v.push_back(i);
        }
    }

    if (v.empty())
    {
        cout << 0 << "\n";
        return 0;
    }

    auto isOk = [&](int mid)
    {
        int count = 0;
        for (int i = 0; i + mid - 1 < n; i++)
        {

            if (get_hash(i, i + mid - 1) == get_hash(0, mid - 1))
            {
                count++;
            }
        }
        if (count >= 3)
            return 0;
        else
            return 1;
    };

    int ans = 0;
    int l = 0, r = (int)v.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (isOk(v[mid]) == 0)
        {
            ans = v[mid];
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    if (ans != 0)
        cout << s.substr(0, ans) << "\n";
    else
    {
        cout << "Just a legend" << "\n";
    }
    return 0;
}
