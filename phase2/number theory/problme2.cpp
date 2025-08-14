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
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            int v;
            cin >> v;
            s.insert(v);
        }
        int sz = n - s.size();
        if (sz % 2 == 0)
        {
            cout << s.size() << "\n";
        }
        else
        {
            cout << s.size() - 1 << "\n";
        }
    }
    return 0;
}
