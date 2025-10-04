#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while ((cin >> n) && n)
    {
        int m;
        cin >> m;
        vector<vector<pair<int, long double>>> adj(n + 1);
        for (int i = 0; i < m; ++i)
        {
            int a, b, p;
            cin >> a >> b >> p;
            long double w = (long double)p / 100.0L;
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }

        const long double EPS = 1e-18L;
        vector<long double> prob(n + 1, 0.0L);
        priority_queue<pair<long double, int>> pq;

        prob[1] = 1.0L;
        pq.push({prob[1], 1});

        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            long double pcur = cur.first;
            int u = cur.second;

            if (pcur + EPS < prob[u])
                continue;
            for (auto &e : adj[u])
            {
                int v = e.first;
                long double w = e.second;
                long double np = pcur * w;
                if (np > prob[v] + EPS)
                {
                    prob[v] = np;
                    pq.push({np, v});
                }
            }
        }

        cout << fixed << setprecision(6) << (double)(prob[n] * 100.0L) << " percent\n";
    }

    return 0;
}
