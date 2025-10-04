#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
const int N = 1e5 + 5;
vector<int> adj[N];
struct st
{
    int node, cost, servive, liftsiri;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, u, d, i, j, l;
    cin >> n >> u >> d >> i >> j >> l;
    for (int k = 1; k <= l; k++)
    {
        int x;
        cin >> x;
        for (int y = 1; y <= x; y++)
        {
            int v;
            cin >> v;
            adj[k].push_back(v);
        }
    }

    return 0;
}