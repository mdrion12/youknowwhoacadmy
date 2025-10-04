#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n, e, q;
    cin >> n >> e >> q;
    ll adj[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adj[i][j] = LLONG_MAX;
            if (i == j)
                adj[i][j] = 0;
        }
    }
    while (e--)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b], c);
        adj[b][a] = min(adj[b][a], c);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj[i][k] != LLONG_MAX && adj[k][j] != LLONG_MAX)
                {
                    if (adj[i][k] + adj[k][j] < adj[i][j])
                    {
                        adj[i][j] = adj[i][k] + adj[k][j];
                    }
                }
            }
        }
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (adj[a][b] == LLONG_MAX)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << adj[a][b] << "\n";
        }
    }

    return 0;
}
