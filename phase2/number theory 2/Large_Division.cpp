
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
const int N = 1e5 + 5;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        string a;
        int b;
        cin >> a;
        cin >> b;
        b = abs(b);
        int i = 0;
        if (a[0] == '-')
        {
            i = 1;
        }
        ll ans = 0;
        for (int j = i; j < a.size(); j++)
        {
            ans = ((1ll * ans * 10) % b + (a[j] - '0')) % b;
        }
        cout << "Case " << tc << ": ";
        if (ans == 0)
        {
            cout << "divisible" << "\n";
        }
        else
        {
            cout << "not divisible" << "\n";
        }
    }
    return 0;
}