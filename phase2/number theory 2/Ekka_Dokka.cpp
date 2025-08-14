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

    for (int cs = 1; cs <= t; cs++)
    {
        ll p = 1;
        ll w;
        cin >> w;
        if (w % 2 == 1)
        {
            cout << "Case " << cs << ": ";
            cout << "Impossible" << "\n";
        }
        else
        {

            while (w % 2 == 0)
            {
                p *= 2;
                w /= 2;
            }
            cout << "Case " << cs << ": " << w << " " << p << "\n";
        }
    }
    return 0;
}