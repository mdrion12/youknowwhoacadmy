#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 55;
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
    int tt;
    cin >> tt;
    for (int tc = 1; tc <= tt; tc++)
    {
        int n;
        cin >> n;
        for (int i = 0; i <= n; i++)
            adj[i].clear();

        int mat[n + 1][n + 1];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> mat[i][j];
                if (i != j)
                    adj[i].push_back({j, mat[i][j]});
            }
        }
        int q;
        cin >> q;
        ll ans = 0;
        while (q--)
        {
            int a, b;
            cin >> a >> b;
            for (int i = 0; i <= n; i++)
            {
                dis[i] = LLONG_MAX;
            }

            dis[a] = 0;
            priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> pq;
            pq.push({a, 0});
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
                    ll child_node = it.first;
                    ll child_cost = it.second;
                    if (cost + child_cost < dis[child_node])
                    {
                        dis[child_node] = cost + child_cost;
                        pq.push({child_node, dis[child_node]});
                    }
                }
            }
            ans += dis[b];
        }
        cout << "Case #" << tc << ": " << ans << "\n";
    }
    return 0;
}
