#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;
const int N = 1009;
const int MAXS = 1005;

vector<pair<int, int>> adj[N];
ll dist[N][MAXS];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i <= n; i++)
        {
            adj[i].clear();
        }

        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> s(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> s[i];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < MAXS; j++)
            {
                dist[i][j] = INF;
            }
        }
        using T = tuple<ll, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        dist[1][s[1]] = 0;
        pq.push({0, 1, s[1]});

        while (!pq.empty())
        {
            auto [cost, node, slow] = pq.top();
            pq.pop();

            if (cost > dist[node][slow])
                continue;

            for (auto [v, w] : adj[node])
            {
                int new_slow = min(slow, s[v]);
                ll nd = cost + 1LL * slow * w;

                if (nd < dist[v][new_slow])
                {
                    dist[v][new_slow] = nd;
                    pq.push({nd, v, new_slow});
                }
            }
        }

        ll ans = INF;
        for (int sl = 1; sl < MAXS; sl++)
            ans = min(ans, dist[n][sl]);

        cout << ans << "\n";
    }

    return 0;
}