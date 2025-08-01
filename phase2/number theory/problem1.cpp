
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define alice cout << "Alice " << "\n";
#define bob cout << "Bob" << "\n";
#define nx "\n";
void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    int ones = 0;
    int zeros = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            zeros++;
        }
        if (s[i] == '1')
        {
            ones++;
        }
    }
    if (k == 1)
    {
        cout << (ones == 1 ? "Alice" : "Bob") << nx;
        return;
    }
    if (ones == 0)
    {
        cout << "Alice" << nx;
        return;
    }
    if (ones <= k)
    {
        cout << "Alice" << nx;
        return;
    }
    bool ok = (zeros >= k);
    if (ok || (k * 2 <= n))
    {
        cout << "Bob" << nx;
    }
    else
    {
        cout << "Alice" << nx;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}