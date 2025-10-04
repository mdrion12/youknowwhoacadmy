#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int INF = INT_MAX;

vector<pair<int, int>> adj[N], rev[N];

vector<int> dijkstra(int src, vector<pair<int, int>> g[], int n)
{
    vector<int> dis(n, INF);
    dis[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        auto [cost, node] = pq.top();
        pq.pop();
        if (cost > dis[node])
            continue;

        for (auto [child, w] : g[node])
        {
            if (dis[node] + w < dis[child])
            {
                dis[child] = dis[node] + w;
                pq.push({dis[child], child});
            }
        }
    }
    return dis;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        int n, m, capital, q;
        cin >> n >> m >> capital >> q;

        for (int i = 0; i < n; i++)
        {
            adj[i].clear();
            rev[i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back({v, 1});
            rev[v].push_back({u, 1});
        }
        vector<int> dist_from_cap = dijkstra(capital, adj, n);
        vector<int> dist_to_cap = dijkstra(capital, rev, n);

        cout << "Case " << tc << ":\n";
        while (q--)
        {
            int u, v;
            cin >> u >> v;
            if (dist_to_cap[u] == INF || dist_from_cap[v] == INF)
            {
                cout << "Not possible to go from " << u << " to " << v << ".\n";
            }
            else
            {
                cout << "The shortest distance from " << u << " to " << v
                     << " is " << dist_to_cap[u] + dist_from_cap[v] << ".\n";
            }
        }
    }
    return 0;
}