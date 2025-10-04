#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s, x;
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    n = s.size();
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'v')
        {
            c++;
        }
        else if (s[i] == 'o')
        {
            if (c > 1)
            {
                for (int j = 1; j <= c - 1; j++)
                {
                    x += 'w';
                }
            }
            c = 0;
            x += 'o';
        }
    }
    if (c > 1)
    {
        for (int j = 1; j <= c - 1; j++)
        {
            x += 'w';
        }
    }

    n = x.size();
    s = "@" + x;

    vector<int> pref(n + 2, 0), suff(n + 2, 0);

    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + (s[i] == 'w');
    }

    for (int i = n; i >= 1; i--)
    {
        suff[i] = suff[i + 1] + (s[i] == 'w');
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'o')
        {
            ans += 1LL * pref[i] * suff[i];
        }
    }

    cout << ans << "\n";
    return 0;
}
