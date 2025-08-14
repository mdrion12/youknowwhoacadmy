#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
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
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = v[i] - i; j <= n; j += v[i])
            {
                if (j >= 0)
                    if (1ll * v[i] * v[j] == i + j && i < j)
                    {
                        ans++;
                    }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}