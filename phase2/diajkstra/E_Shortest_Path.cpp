#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    if (!(cin >> n >> m >> k))
        return 0;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // Forbidden triplets: store as hashed set for O(1) check
    const int BASE = n + 5; // safe base
    auto encode = [&](int a, int b, int c) -> long long
    {
        return ((long long)a * BASE + b) * BASE + c;
    };
    unordered_set<long long> forb;
    forb.reserve(k * 2 + 10);
    for (int i = 0; i < k; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        forb.insert(encode(a, b, c));
    }

    // dist[prev][cur] = steps taken to reach state (prev, cur)
    const int INF = 1e9;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, -1));
    // parent[prev][cur] = pair(prev_prev, prev)
    vector<vector<pii>> parent(n + 1, vector<pii>(n + 1, {-1, -1}));

    queue<pii> q;
    // start from (0,1) -- we will use index 0 for "no previous"
    // For storage convenience, our dist uses indices 0..n for prev, 1..n for cur.
    dist[0][1] = 0;
    parent[0][1] = {-1, -1};
    q.push({0, 1});

    while (!q.empty())
    {
        auto [p, u] = q.front();
        q.pop();
        for (int v : adj[u])
        {
            // check forbidden only if p != 0
            if (p != 0)
            {
                if (forb.find(encode(p, u, v)) != forb.end())
                    continue;
            }
            if (dist[u][v] == -1)
            {
                dist[u][v] = dist[p][u] + 1;
                parent[u][v] = {p, u};
                q.push({u, v});
            }
        }
    }

    // Find best (p, n)
    int bestP = -1;
    int bestDist = INF;
    for (int p = 0; p <= n; p++)
    {
        if (dist[p][n] != -1 && dist[p][n] < bestDist)
        {
            bestDist = dist[p][n];
            bestP = p;
        }
    }
    if (bestP == -1)
    {
        cout << -1 << '\n';
        return 0;
    }

    // Reconstruct path from state (bestP, n)
    vector<int> path;
    int curP = bestP;
    int cur = n;
    while (!(curP == 0 && cur == 1))
    {
        path.push_back(cur);
        pii par = parent[curP][cur]; // par = (pp, pu)
        int pp = par.first;
        int pu = par.second;
        cur = pu;
        curP = pp;
    }
    path.push_back(1);
    reverse(path.begin(), path.end());

    cout << (int)path.size() - 1 << '\n'; // number of roads = nodes-1
    for (size_t i = 0; i < path.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << path[i];
    }
    cout << '\n';
    return 0;
}
