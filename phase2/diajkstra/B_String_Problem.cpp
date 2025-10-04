#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;
    if (s.size() != t.size())
    {
        cout << -1 << "\n";
        return 0;
    }

    int n;
    cin >> n;

    vector<vector<pair<int, int>>> g(26);
    for (int i = 0; i < n; i++)
    {
        char a, b;
        int w;
        cin >> a >> b >> w;
        g[a - 'a'].push_back({b - 'a', w});
    }
    vector<vector<int>> cost(26, vector<int>(26, INF));
    for (int start = 0; start < 26; start++)
    {
        vector<int> dist(26, INF);
        dist[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, start});
        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u])
                continue;
            for (auto [v, w] : g[u])
            {
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        cost[start] = dist;
    }

    string res = "";
    int totalCost = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int best = INF;
        char choose = '?';
        for (int c = 0; c < 26; c++)
        {
            int cur = cost[s[i] - 'a'][c] + cost[t[i] - 'a'][c];
            if (cur < best)
            {
                best = cur;
                choose = c + 'a';
            }
        }
        if (best >= INF)
        {
            cout << -1 << "\n";
            return 0;
        }
        totalCost += best;
        res += choose;
    }

    cout << totalCost << "\n"
         << res << "\n";
    return 0;
}
