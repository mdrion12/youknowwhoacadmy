#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
const int N = 110;
vector<int> dist(N);
vector<pair<int, int>> adj[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (1)
    {

        int n;
        cin >> n;
        if (n == 0)
            break;
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
        }

        for (int i = 1; i <= n; i++)
        {
            int ed;
            cin >> ed;
            while (ed--)
            {
                int v, w;
                cin >> v >> w;
                adj[i].push_back({v, w});
            }
        }

        int nval = 0, cval = INT_MAX;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < N; j++)
                dist[j] = INT_MAX;

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            dist[i] = 0;
            pq.push({0, i});

            while (!pq.empty())
            {
                auto parent = pq.top();
                pq.pop();
                int node = parent.second;
                int cost = parent.first;
                if (cost > dist[node])
                    continue;

                for (auto it : adj[node])
                {
                    int childnode = it.first;
                    int childcost = it.second;
                    int nd = cost + childcost;
                    if (nd < dist[childnode])
                    {
                        dist[childnode] = nd;
                        pq.push({nd, childnode});
                    }
                }
            }

            int mx = 0;
            bool ok = true;
            for (int j = 1; j <= n; j++)
            {
                if (dist[j] == INT_MAX)
                {
                    ok = false;
                    break;
                }
                mx = max(mx, dist[j]);
            }

            if (ok && mx < cval)
            {
                cval = mx;
                nval = i;
            }
        }

        if (cval == INT_MAX)
        {
            cout << "disjoint\n";
        }
        else
        {
            cout << nval << " " << cval << "\n";
        }
    }

    return 0;
}
