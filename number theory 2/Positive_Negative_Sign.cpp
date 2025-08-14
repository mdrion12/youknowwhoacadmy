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
    for (int tc = 1; tc <= t; tc++)
    {
        cout << "Case " << tc << ": ";
        int n, m;
        cin >> n >> m;
        cout << (n / 2) * m << "\n";
    }
    return 0;
}