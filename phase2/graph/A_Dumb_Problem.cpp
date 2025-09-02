#include <bits/stdc++.h>
using namespace std;
#define no cout << "NO\n";
#define yes cout << "YES\n";

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

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

        bool f = false;
        int i_index = -1, j_index = -1, k_index = -1;

        for (int i = 1; i <= n - 2; i++)
        {
            if (v[i] < v[i + 1] && v[i + 1] > v[i + 2])
            {
                f = true;
                i_index = i;
                j_index = i + 1;
                k_index = i + 2;
                break;
            }
        }

        if (f)
        {
            yes;
            cout << i_index << " " << j_index << " " << k_index << "\n";
        }
        else
        {
            no;
        }
    }
    return 0;
}
