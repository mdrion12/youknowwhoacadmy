#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
vector<pair<int, ll>> adj[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 1});
    vector<priority_queue<ll>> v(n + 1);
    v[1].push(0);

    while (!pq.empty())
    {
        auto parent = pq.top();
        pq.pop();
        int node = parent.second;
        ll cost = parent.first;
        if (v[node].size() >= k && cost > v[node].top())
            continue;
        for (auto it : adj[node])
        {
            int cn = it.first;
            ll cc = it.second;
            ll nd = cost + cc;

            if ((int)v[cn].size() < k)
            {
                v[cn].push(nd);
                pq.push({nd, cn});
            }
            else
            {
                ll val = v[cn].top();
                if (val > nd)
                {
                    v[cn].pop();
                    v[cn].push(nd);
                    pq.push({nd, cn});
                }
            }
        }
    }
    vector<ll> res;
    while (!v[n].empty())
    {
        res.push_back(v[n].top());
        v[n].pop();
    }
    for (int i = (int)res.size() - 1; i >= 0; i--)
    {
        cout << res[i] << " ";
    }
    cout << "\n";
    return 0;
}
