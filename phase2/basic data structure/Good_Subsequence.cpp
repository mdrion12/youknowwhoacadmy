#include <bits/stdc++.h>
using namespace std;

int main()
{

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
        int cnt = 1;
        int jor = 0, bijor = 0;
        if (v[0] % 2 == 0)
        {
            jor = 1;
        }
        else
        {
            bijor = 1;
        }
        for (int i = 1; i < n; i++)
        {
            if (jor == 0 && bijor == 1 && v[i] % 2 == 0)
            {
                cnt++;
                jor = 1;
                bijor = 0;
            }
            else if (bijor == 0 and jor == 1 && v[i] % 2 == 1)
            {
                bijor = 1;
                jor = 0;
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}
