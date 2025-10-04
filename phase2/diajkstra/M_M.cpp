#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
const int N = 1e5 + 5;
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m, x, y;
bool valid(int a, int b)
{
    if (a >= 1 && a <= n && b >= 1 && b <= m)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n >> m >> x >> y;
        int arr[n + 1][m + 1];
        int dis[n + 1][m + 1];
        int dis2[n + 1][m + 1];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> arr[i][j];
                dis[i][j] = INT_MAX;
                dis2[i][j] = INT_MAX;
            }
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, 1, 1});
        while (!pq.empty())
        {
            auto parent = pq.top();
            pq.pop();
            int cost, nodea, nodeb;
            tie(cost, nodea, nodeb) = parent;
            if (cost > dis[nodea][nodeb])
                continue;
            for (auto it : dir)
            {
                int cx = nodea + it.first;
                int cy = nodeb + it.second;
                if (valid(cx, cy))
                {
                    int ck = abs(arr[nodea][nodeb] - arr[cx][cy]);
                    int nd = 0;
                    if (ck % 2 == 0)
                    {
                        nd = cost;
                    }
                    else
                    {
                        nd = cost + x;
                    }

                    if (nd < dis[cx][cy])
                    {
                        dis[cx][cy] = nd;
                        pq.push({nd, cx, cy});
                    }
                }
            }
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
        q.push({0, 1, 1});
        while (!q.empty())
        {
            auto pa = q.top();
            q.pop();
            int cost1, na, nb;
            tie(cost1, na, nb) = pa;
            if (cost1 > dis2[na][nb])
                continue;
            for (auto it : dir)
            {
                int cx = na + it.first;
                int cy = nb + it.second;
                if (valid(cx, cy))
                {
                    int ck = abs(arr[na][nb] - arr[cx][cy]);
                    int nd = 0;
                    if (ck % 2 == 1)
                    {
                        nd = cost1;
                    }
                    else
                    {
                        nd = cost1 + y;
                    }

                    if (nd < dis2[cx][cy])
                    {
                        dis2[cx][cy] = nd;
                        q.push({nd, cx, cy});
                    }
                }
            }
        }
        (dis[n][m] < dis2[n][m]) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}