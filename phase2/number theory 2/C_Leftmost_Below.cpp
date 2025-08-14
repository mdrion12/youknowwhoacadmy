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
        bool f = true;
        int m = v[0];
        for (int i = 1; i < n; i++)
        {
            int k = (v[i] / 2) + 1;
            if (k > m)
            {
                f = false;
                break;
            }
            else
            {
                m = min(m, v[i]);
            }
        }
        if (f)
        {
            yes;
        }
        else
        {
            no;
        }
    }
    return 0;
}