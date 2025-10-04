#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m))
        return 0;

    // dynamic adjacency: pair<to, weight>
    vector<vector<pair<int, long double>>> adj(n + 1);
    adj.reserve(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        long double weight = 1.0L / (long double)w; // w in {1,2,3,4}
        adj[u].push_back({v, weight});
    }

    const long double INF = 1e30L;
    vector<long double> dist(n + 1, INF);
    dist[1] = 0.0L;

    // min-heap (distance, node)
    priority_queue<pair<long double, int>, vector<pair<long double, int>>, greater<pair<long double, int>>> pq;
    pq.push({0.0L, 1});

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        long double d = cur.first;
        int u = cur.second;
        if (d > dist[u])
            continue;

        for (auto &e : adj[u])
        {
            int v = e.first;
            long double w = e.second;
            long double nd = d + w;
            if (nd + 1e-18L < dist[v])
            { // small eps to be safe
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }

    cout.setf(std::ios::fixed);
    cout << setprecision(8);
    for (int i = 2; i <= n; ++i)
    {
        // if graph could be not reachable and judge expects something else,
        // change this branch accordingly. For connected (directed strongly),
        // this will always be finite.
        if (dist[i] >= INF / 2)
        {
            // if you need some special output for unreachable nodes, change here.
            cout << "INF\n";
        }
        else
        {
            cout << (double)dist[i] << '\n'; // cast to double only for printing brevity
        }
    }

    return 0;
}
