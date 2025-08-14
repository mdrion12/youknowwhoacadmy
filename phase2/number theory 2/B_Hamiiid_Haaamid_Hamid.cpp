#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<char> v(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }
        int left = 0, right = 0;
        for (int i = 1; i <= n; i++)
        {
            if (v[i] == '#' && i < m)
            {
                left = i;
            }
        }
        for (int i = n; i >= 1; i--)
        {
            if (v[i] == '#' && i > m)
            {
                right = i;
            }
        }
        // cout << left << " " << right << "\n";
        if (left == 0 && right == 0)
        {
            cout << 1 << "\n";
            continue;
        }
        if (m == 1 || m == n)
        {
            cout << 1 << "\n";
            continue;
        }
        if (right == 0)
        {
            right = m + 1;
        }
        int rr = (n - right) + 1;

        if ((left < rr && m - left >= 2) || (left == 0 && rr != 0))
        {
            left = m - 1;
        }
        else if ((rr < left && right - m >= 2))
        {
            rr++;
            right = m + 1;
            rr = (n - right) + 1;
        }
        // cout << right << "\n";
        // cout << left << " " << rr << "\n";
        cout << min(left, rr) + 1 << "\n";
    }
    return 0;
}