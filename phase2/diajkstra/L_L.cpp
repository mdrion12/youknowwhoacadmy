#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
const int INF = INT_MAX;

vector<pair<int, int>> adj[N];

vector<int> dijkstra(int src, int n)
{
    vector<int> dist(n, INF);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        auto [cost, node] = pq.top();
        pq.pop();
        if (cost > dist[node])
            continue;

        for (auto [child, w] : adj[node])
        {
            int nd = cost + w;
            if (nd < dist[child])
            {
                dist[child] = nd;
                pq.push({nd, child});
            }
        }
    }

    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N_nodes, M_edges, Q;
    cin >> N_nodes >> M_edges >> Q;

    for (int i = 0; i < N_nodes; i++)
        adj[i].clear();

    for (int i = 0; i < M_edges; i++)
    {
        int u, v, L;
        cin >> u >> v >> L;
        adj[u].push_back({v, L});
        adj[v].push_back({u, L});
    }

    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> queries[i];
    }

    for (int i = 0; i < Q; i++)
    {
        int start = queries[i];
        vector<int> dist = dijkstra(start, N_nodes);

        int max_dist = 0;
        int count = 0;
        for (int j = 0; j < N_nodes; j++)
        {
            if (dist[j] == INF)
                continue;
            if (dist[j] > max_dist)
            {
                max_dist = dist[j];
                count = 1;
            }
            else if (dist[j] == max_dist)
            {
                count++;
            }
        }

        cout << max_dist << " " << count << "\n";
    }

    return 0;
}
