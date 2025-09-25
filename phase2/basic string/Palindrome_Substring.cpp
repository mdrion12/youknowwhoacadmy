#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 9;
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
{ // O(n)
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

pair<int, int> string_hash(string s)
{ // O(n)
    int n = s.size();
    pair<int, int> hs({0, 0});
    for (int i = 0; i < n; i++)
    {
        hs.first += 1LL * s[i] * pw[i].first % mod1;
        hs.first %= mod1;
        hs.second += 1LL * s[i] * pw[i].second % mod2;
        hs.second %= mod2;
    }
    return hs;
}
struct Hashing
{
    pair<int, int> pref[N];
    void build(string s)
    { // O(n)
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            pref[i].first = 1LL * s[i] * pw[i].first % mod1;
            if (i)
                pref[i].first = (pref[i].first + pref[i - 1].first) % mod1;
            pref[i].second = 1LL * s[i] * pw[i].second % mod2;
            if (i)
                pref[i].second = (pref[i].second + pref[i - 1].second) % mod2;
        }
    }
    pair<int, int> get_hash(int i, int j)
    { // O(1)
        // assert(i <= j);
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
} S, R;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prec();
    string s;
    while (cin >> s)
    {
        S.build(s);
        string r = s;
        reverse(r.begin(), r.end());
        R.build(r);
        set<string> se;
        int n = s.size();
        auto is_palindrome = [&](int i, int j)
        {
            return S.get_hash(i, j) == R.get_hash(n - j - 1, n - i - 1);
        };
        for (int j = 0; j < n; j++)
        { // fix the right endpoint of a substring
            for (int i = 0; i < j; i++)
            { // loop over the substrings from large to small length
                if (is_palindrome(i, j))
                {
                    se.insert(s.substr(i, j - i + 1));
                    break; // important
                }
            }
        }
        for (auto x : se)
        {
            cout << x << '\n';
        }
        cout << '\n';
    }
    return 0;
}
// memory: O(n^2) as the number of unique palindromes in a string is <= n
// time: O(n^2 logn) as the number of unique palindromes in a string is <= n