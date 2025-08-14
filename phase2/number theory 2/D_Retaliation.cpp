#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }
        ll y = (2 * v[1] - v[2]) / (n + 1);
        ll x = v[2] - v[1] + y;
        if (x < 0 || y < 0)
        {
            cout << "NO" << "\n";
            continue;
        }
        bool f = true;
        for (int i = 1; i <= n; i++)
        {
            v[i] -= x * (i);
            v[i] -= y * (n - (i - 1));
            if (v[i] != 0)
            {
                f = false;
            }
        }
        if (f)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
    return 0;
}