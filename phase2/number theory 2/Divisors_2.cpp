
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int d[N + 9];
bool ok[N + 9];
// vector<int> divs[N + 9];
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j += i)
        {
            d[j]++;
            // divs[j].push_back(i);
        }
    }
    for (int n = 1; n <= N; n++)
    {
        ok[n] = true;
    }
    // for (int n = 1; n <= N; n++) {
    //   for (auto m: divs[n]) {
    //     if (d[n] % d[m] != 0) {
    //       ok[n] = false;
    //     }
    //   }
    // }
    for (int m = 1; m <= N; m++)
    {
        for (int n = m; n <= N; n += m)
        {
            if (d[n] % d[m] != 0)
            {
                ok[n] = false;
            }
        }
    }
    vector<int> ans;
    for (int n = 1; n <= N; n++)
    {
        if (d[n] > 3 and ok[n])
        {
            ans.push_back(n);
        }
    }
    for (int i = 107; i < ans.size(); i += 108)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}