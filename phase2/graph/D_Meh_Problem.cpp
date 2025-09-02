#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
const int N = 1e5 + 9;
vector<int> adj[N];
vector<int> vis(N);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    set<int> st;
    st.insert(1);
    while (!st.empty())
    {
        int v = *st.begin();
        st.erase(st.begin());
        if (vis[v] == 1)
            continue;
        cout << v << " ";
        vis[v] = 1;
        for (auto it : adj[v])
        {
            if (!vis[it])
                st.insert(it);
        }
        }

    return 0;
}