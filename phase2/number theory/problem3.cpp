
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
        string s;
        cin >> s;
        int count = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i] != s[i - 1])
            {
                count++;
            }
        }
        if (s[0] == '0')
        {
            cout << count << "\n";
        }
        else
        {
            cout << count + 1 << "\n";
        }
    }
    return 0;
}