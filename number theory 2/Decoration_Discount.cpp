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
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        int ans = 200;
        for (int i = 0; i < n - 1; i++)
        {
            int val = v[i] + (v[i + 1] / 2);
            ans = min(ans, val);
        }
        sort(v.begin(), v.end());
        int val = v[0] + v[1];
        ans = min(ans, val);
        cout << ans << "\n";
    }
    return 0;
}