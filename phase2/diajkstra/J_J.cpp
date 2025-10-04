#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> A(N + 1), B(N + 1);
    vector<int> X(N + 1);
    for (int i = 1; i <= N - 1; ++i)
    {
        cin >> A[i] >> B[i] >> X[i];
    }
    vector<pair<int, ll>> adj[N + 1];
    for (int i = 1; i <= N - 1; ++i)
    {
        adj[i].push_back({i + 1, A[i]});
        adj[i].push_back({X[i], B[i]});
    }
    vector<ll> dist(N + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto parent = pq.top();
        ll d = parent.first;
        int u = parent.second;
        pq.pop();
        if (d != dist[u])
        {
            continue;
        }
        for (auto &e : adj[u])
        {
            int v = e.first;
            ll w = e.second;
            if (dist[v] > d + w)
            {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    cout << dist[N] << "\n";
    return 0;
}
