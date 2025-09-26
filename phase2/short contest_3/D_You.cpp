#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
const int mod = 1e9 + 7;
int dp[N][10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i <= 9; i++)
        dp[0][i] = 1;

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j < 9)
                dp[i][j] = dp[i - 1][j + 1] % mod;
            else
                dp[i][j] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int ans = 0;
        while (n)
        {
            int d = n % 10;
            n /= 10;
            ans = (ans + dp[k][d]) % mod;
        }
        cout << ans << "\n";
    }

    return 0;
}
