#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

struct Edge
{
    int to;
    ll cost, w;
};

int N, M;
ll K;
vector<Edge> adj[100005];

bool can(ll wisdom)
{
    // Dijkstra with only edges having w <= wisdom
    vector<ll> dist(N + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto e : adj[u])
        {
            if (e.w > wisdom)
                continue; // can't use this edge
            if (dist[u] + e.cost < dist[e.to])
            {
                dist[e.to] = dist[u] + e.cost;
                pq.push({dist[e.to], e.to});
            }
        }
    }
    return dist[N] < K;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> N >> M >> K;

        for (int i = 1; i <= N; i++)
            adj[i].clear();

        ll maxW = 0;
        for (int i = 0; i < M; i++)
        {
            int u, v;
            ll c, w;
            cin >> u >> v >> c >> w;
            adj[u].push_back({v, c, w});
            adj[v].push_back({u, c, w}); // bidirectional
            maxW = max(maxW, w);
        }

        ll l = 1, r = maxW, ans = -1;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if (can(mid))
            {
                ans = mid;
                r = mid - 1; // try smaller wisdom
            }
            else
            {
                l = mid + 1; // need bigger wisdom
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
