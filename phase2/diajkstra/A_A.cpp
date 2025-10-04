#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
const int N = 2e5 + 5;
vector<pair<ll, ll>> adj[N];
ll dis[N];
struct cmp
{
    bool operator()(pair<ll, ll> a, pair<ll, ll> b)
    {
        return a.second > b.second;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < N; i++)
    {
        dis[i] = LLONG_MAX;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        }
    dis[1] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> pq;
    pq.push({1, 0});
    while (!pq.empty())
    {
        auto par = pq.top();
        pq.pop();
        ll node = par.first;
        ll cost = par.second;
        if (cost > dis[node])
            continue;
        for (auto it : adj[node])
        {
            ll child_cost = it.second;
            ll child_node = it.first;
            ll nd = child_cost + cost;
            if (nd < dis[child_node])
            {
                dis[child_node] = nd;
                pq.push({child_node, nd});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }

    return 0;
}