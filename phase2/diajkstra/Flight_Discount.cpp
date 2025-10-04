#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
const int N = 1e5 + 5;
vector<pair<int, ll>> adj[N];
ll dis[2][N + 1];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dis[i][j] = LLONG_MAX;
        }
    }
    dis[0][1] = 0;
    pq.push({0, 1, 0});
    while (!pq.empty())
    {
        auto parent = pq.top();
        pq.pop();
        int type, node;
        ll cost;
        tie(cost, node, type) = parent;
        if (cost > dis[type][node])
            continue;
        for (auto it : adj[node])
        {
            int childnode = it.first;
            ll childcost = it.second;

            if (type == 0)
            {
                if ((childcost / 2) + cost < dis[1][childnode])
                {
                    dis[1][childnode] = (childcost / 2) + cost;
                    pq.push({dis[1][childnode], childnode, 1});
                }
                if (childcost + cost < dis[0][childnode])
                {
                    dis[0][childnode] = childcost + cost;
                    pq.push({dis[0][childnode], childnode, 0});
                }
            }
            else
            {
                if (childcost + cost < dis[1][childnode])
                {
                    dis[1][childnode] = childcost + cost;
                    pq.push({dis[1][childnode], childnode, 1});
                }
            }
        }
    }
    cout << min(dis[0][n], dis[1][n]);

    return 0;
}