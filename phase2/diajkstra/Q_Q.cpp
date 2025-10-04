#include <bits/stdc++.h>
using namespace std;

const int N = 30;
vector<pair<int, int>> adj[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int tt = 1; tt <= t; tt++)
    {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++)
            adj[i].clear();

        vector<pair<string, int>> v(n + 1);
        map<string, int> mp;
        map<int, string> mp1;

        for (int i = 1; i <= n; i++)
        {
            cin >> v[i].first >> v[i].second;
            mp[v[i].first] = i;
            mp1[i] = v[i].first;
        }

        int m;
        cin >> m;
        for (int i = 1; i <= m; i++)
        {
            string u, vv;
            int km;
            cin >> u >> vv >> km;
            int a = mp[u];
            int b = mp[vv];
            int cost = km * 2;
            adj[a].push_back({b, cost});
            adj[b].push_back({a, cost});
        }

        int q;
        cin >> q;
        int queryNo = 1;
        cout << "Map #" << tt << "\n";
        while (q--)
        {
            string a, b;
            int passengers;
            cin >> a >> b >> passengers;
            int start = mp[a];
            int ending = mp[b];

            vector<int> path(n + 1, -1);
            vector<double> dist(n + 1, 1e18);

            dist[start] = v[start].second;
            priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
            pq.push({dist[start], start});

            while (!pq.empty())
            {
                auto p = pq.top();
                pq.pop();
                int node = p.second;
                double cost = p.first;

                if (cost > dist[node])
                    continue;

                for (auto it : adj[node])
                {
                    int childnode = it.first;
                    int childcost = it.second;

                    double nd = cost + childcost + v[childnode].second;
                    if (nd < dist[childnode])
                    {
                        dist[childnode] = nd;
                        path[childnode] = node;
                        pq.push({nd, childnode});
                    }
                }
            }

            vector<int> ans;
            int cur = ending;
            while (cur != -1)
            {
                ans.push_back(cur);
                cur = path[cur];
            }
            reverse(ans.begin(), ans.end());

            double totalCost = dist[ending] * 1.1;
            double perPassenger = totalCost / passengers;

            cout << "Query #" << queryNo++ << "\n";
            for (int i = 0; i < ans.size(); i++)
            {
                cout << mp1[ans[i]];
                if (i + 1 < ans.size())
                    cout << " ";
            }
            cout << "\n";
            cout << "Each passenger has to pay : " << fixed << setprecision(2) << perPassenger << " taka\n";
        }
        if (tt != t)
        {
            cout << "\n";
                }
    }

    return 0;
}
