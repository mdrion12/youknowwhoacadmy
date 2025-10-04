#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
const int N = 505;
vector<pair<int, int>> adj[N];
vector<int> dist(N);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int start, q;
    cin >> start >> q;
    while (q--)
    {
        for (int i = 0; i < 505; i++)
        {
            dist[i] = INT_MAX;
        }
        int last;
        cin >> last;
        dist[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});
        while (!pq.empty())
        {
            auto parent = pq.top();
            pq.pop();
            int node = parent.second;
            int cost = parent.first;
            if (dist[node] < cost)
                continue;
            for (auto child : adj[node])
            {
                int cnode = child.first;
                int ccost = child.second;
                int nd = cost + ccost;
                if (nd < dist[cnode])
                {
                    dist[cnode] = nd;
                    pq.push({nd, cnode});
                }
            }
        }
        (dist[last] == INT_MAX) ? cout << "NO PATH\n" : cout << dist[last] << "\n";
    }

    return 0;
}