#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "No" << "\n";
#define yes cout << "Yes" << "\n";
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
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            string s = to_string(v[i]);
            for (int j = 0; j < s.size(); j++)
            {
                ans += s[j] - '0';
            }
        }
        if (ans % 3 == 0)
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