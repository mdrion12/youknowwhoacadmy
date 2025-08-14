#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, a;
        cin >> n >> a;
        int c1 = 0, c2 = 0, c0 = 0;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            int v;
            cin >> v;
            sum += v;
            if (v == 0)
            {
                c0++;
            }
            else if (v == 1)
            {
                c1++;
            }
            else
            {
                c2++;
            }
        }
    }
    return 0;
}