#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
const int N = 1e5 + 5;
vector<int> vis(N);
vector<int> adj[N];
vector<int> v(N + 1);
int dfs(int n)
{
    vis[n] = 1;
    int mn = v[n];
    for (auto it : adj[n])
    {
        if (!vis[it])
        {
            mn = min(mn, dfs(it));
        }
    }
    return mn;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            ans += dfs(i);
        }
    }
    cout << ans << "\n";
    return 0;
}