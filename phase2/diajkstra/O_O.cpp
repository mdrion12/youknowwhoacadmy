#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int UP = 0, DOWN = 1;
struct Edge
{
    int to, type;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, UP});
        adj[v].push_back({u, DOWN});
    }

    int start, target;
    cin >> start >> target;

    vector<vector<int>> dist(n + 1, vector<int>(2, INF));
    deque<pair<int, int>> dq;
    dist[start][UP] = 0;
    dist[start][DOWN] = 0;
    dq.push_back({start, UP});
    dq.push_back({start, DOWN});

    while (!dq.empty())
    {
        auto [u, gear] = dq.front();
        dq.pop_front();

        for (auto e : adj[u])
        {
            int v = e.to;
            int nextGear = e.type;
            int cost = (gear == nextGear ? 0 : 1);

            if (dist[v][nextGear] > dist[u][gear] + cost)
            {
                dist[v][nextGear] = dist[u][gear] + cost;
                if (cost == 0)
                    dq.push_front({v, nextGear});
                else
                    dq.push_back({v, nextGear});
            }
        }
    }

    cout << min(dist[target][UP], dist[target][DOWN]) << "\n";
    return 0;
}
