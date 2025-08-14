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
        bool f = true;
        for (int i = 1; i <= min(n, 21); i++)
        {
            bool can = false;

            for (int j = 2; j <= i + 1; j++)
            {
                if (v[i] % j != 0)
                {
                    can = true;
                }
            }
            if (can == false)
            {
                f = false;
            }
        }
        if (f)
        {
            yes
        }
        else
        {
            no
        }
    }
    return 0;
}