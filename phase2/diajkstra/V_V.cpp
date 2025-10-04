#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 110;
vector<pair<int, int>> adj[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, e, timelimit, m;
        cin >> n >> e >> timelimit >> m;

        for (int i = 1; i <= n; i++)
            adj[i].clear();

        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            vector<int> dist(n + 1, INT_MAX);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

            dist[i] = 0;
            pq.push({0, i});

            while (!pq.empty())
            {
                auto parent = pq.top();
                pq.pop();
                int cost = parent.first, node = parent.second;

                if (dist[node] < cost)
                    continue;

                for (auto it : adj[node])
                {
                    int cnode = it.first;
                    int ccost = it.second;
                    int nd = cost + ccost;
                    if (nd < dist[cnode])
                    {
                        dist[cnode] = nd;
                        pq.push({nd, cnode});
                    }
                }
            }

            if (dist[e] <= timelimit)
                cnt++;
        }
        cout << cnt << "\n";
        if (tc)
            cout << "\n";
    }
    return 0;
}
