#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
#define tll tuple<ll, int, int>
const int N = 110;

struct edge
{
    int node;
    ll cost;
    ll tol;
};

vector<edge> adj[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < N; i++)
            adj[i].clear();

        ll k;
        int n, e;
        cin >> k >> n >> e;

        for (int i = 0; i < e; i++)
        {
            int u, v;
            ll c, t;
            cin >> u >> v >> c >> t;
            adj[u].push_back({v, c, t});
        }
        vector<vector<ll>> dist(n + 1, vector<ll>(k + 1, LLONG_MAX));
        priority_queue<tll, vector<tll>, greater<tll>> pq;

        dist[1][0] = 0;
        pq.push({0, 1, 0});

        while (!pq.empty())
        {
            auto parent = pq.top();
            pq.pop();

            ll cost;
            int node;
            ll tol;
            tie(cost, node, tol) = parent;

            if (dist[node][tol] < cost)
                continue;

            for (auto it : adj[node])
            {
                int cn = it.node;
                ll cc = it.cost;
                ll ct = it.tol;

                if (tol + ct <= k)
                {
                    ll nd = cost + cc;
                    if (dist[cn][tol + ct] > nd)
                    {
                        dist[cn][tol + ct] = nd;
                        pq.push({nd, cn, tol + ct});
                    }
                }
            }
        }

        ll ans = LLONG_MAX;
        for (ll i = 0; i <= k; i++)
        {
            ans = min(ans, dist[n][i]);
        }

        if (ans == LLONG_MAX)
            cout << "-1\n";
        else
            cout << ans << "\n";
    }
    return 0;
}
