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
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    int cnt = 0;
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] > v[i - 1])
        {
            cnt++;
            ans = max(ans, cnt);
        }
        else
        {
            cnt = 1;
        }
    }
    cout << ans << "\n";
    return 0;
}