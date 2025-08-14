#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
double p[N];
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i < N; i++)
    {
        p[i] = p[i - 1] + log2(i);
    }
    int t, cs = 0;
    cin >> t;
    while (t--)
    {
        int n, b;
        cin >> n >> b;
        double ans = 0;
        // for (int i = 1; i <= n; i++) {
        //   ans += log2(i) / log2(b); // log_b(i)
        // }

        // for (int i = 1; i <= n; i++) {
        //   ans += log2(i);
        // }
        ans = p[n];

        ans /= log2(b);

        ans += 1;
        cout << "Case " << ++cs << ": " << (int)floor(ans) << '\n';
    }
    return 0;
}