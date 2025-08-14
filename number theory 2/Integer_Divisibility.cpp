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
    for (int i = 1; i <= t; i++)
    {
        int n, m;
        cin >> n >> m;
        int ans = 0;
        int curr = 0;
        while (true)
        {

            curr = ((curr * 10) + m) % n;
            ans++;
            if (curr == 0)
            {
                break;
            }
        }
        cout << "Case " << i << ": ";
        cout << ans << "\n";
    }
    return 0;
}