#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
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
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        vector<pair<int, int>> mp;
        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                // cout << i << " " << j << "\n";
                if (a[i] != a[j])
                {
                    mp.push_back({i, j});
                }
            }
        }

        // cout << mp.size() << "\n";
        // for (auto it : mp)
        // {
        //     // if (count > n - 1)
        //     // {
        //     //     break;
        //     // }
        //     cout << it.first << " " << it.second << "\n";
        //     // count++;
        // }
        if (mp.size() >= n - 1)
        {
            int count = 1;
            yes for (auto it : mp)
            {
                if (count > n - 1)
                {
                    break;
                }
                cout << it.first << " " << it.second << "\n";
                count++;
            }
        }
        else
        {
            no
        }
    }
    return 0;
}