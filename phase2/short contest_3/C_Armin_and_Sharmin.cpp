#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
const int mod = 1e9 + 7;
int n, k;
int dp[2100][2100];
int faltu(int pre, int j)
{
    if (j == k)
    {
        return 1;
    }
    if (dp[pre][j] != -1)
    {
        return dp[pre][j];
    }
    int ans = 0;
    for (int i = pre; i <= n; i += pre)
    {
        int op1 = faltu(i, j + 1);
        ans += op1;
        ans %= mod;
    }
    return dp[pre][j] = ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    cout << faltu(1, 0) << "\n";
    return 0;
}