#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
const int N = 1e5 + 5;
vector<int> adj[N];
vector<int> level(N);
vector<int> val(N);
vector<int> vis(N);
void dfs(int i, int p)
{
    vis[i] = 1;
    for (auto it : adj[i])
    {
        if (!vis[it] && it != p)
        {
            level[it] = level[i] + 1;
            dfs(it, i);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        val[i] = v;
        if (v != -1)
        {
            adj[v].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (val[i] == -1 && !vis[i])
        {
            level[i] = 0;
            dfs(i, 0);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, level[i]);
    }
    cout << ans + 1 << "\n";
    return 0;
}