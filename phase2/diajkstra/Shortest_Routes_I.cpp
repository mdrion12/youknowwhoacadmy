#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define ld long double
const ll MOD = 1e9 + 7;

const ll N = 1e5 + 5;
const ll INF = 1e15;

vector<pair<ll, ll>> adj[N];
vector<ll> dis(N, INF);

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // যদি undirected গ্রাফ হয় তাহলে নিচের লাইন লাগবে:
        // adj[v].push_back({u, w});
    }

    for (ll i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, 1});
    dis[1] = 0;

    while (!q.empty())
    {
        auto parent = q.top();
        q.pop();

        ll cost = parent.first;
        ll node = parent.second;

        if (dis[node] < cost)
            continue;

        for (auto it : adj[node])
        {
            ll childnode = it.first;
            ll childcost = it.second;
            ll nd = cost + childcost;

            if (nd < dis[childnode])
            {
                dis[childnode] = nd;
                q.push({nd, childnode});
            }
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        cout << dis[i] << ' ';
    }
    cout << "\n";
}
