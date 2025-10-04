#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
const int N = 1e5 + 5;
vector<pair<int, int>> dir = {{-1, 2}, {-1, -2}, {1, +2}, {1, -2}, {-2, 1}, {-2, -1}, {2, -1}, {2, 1}};
bool valid(int a, int b)
{
    if (a >= 0 && a <= 7 && b >= 0 && b <= 7)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int dist[9][9];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, d;
    while (cin >> a >> b >> c >> d)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                dist[i][j] = INT_MAX;
            }
        }
        dist[a][b] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, a, b});
        while (!pq.empty())
        {
            auto parent = pq.top();
            pq.pop();
            int anode, bnode, cost;
            tie(cost, anode, bnode) = parent;
            if (dist[anode][bnode] < cost)
                continue;
            for (auto it : dir)
            {
                int childnodea = anode + it.first;
                int childnodeb = bnode + it.second;
                int newcost = (anode * childnodea) + (bnode * childnodeb);
                newcost += cost;
                {
                    if (valid(childnodea, childnodeb) && newcost < dist[childnodea][childnodeb])
                    {
                        dist[childnodea][childnodeb] = newcost;
                        pq.push({newcost, childnodea, childnodeb});
                    }
                }
            }
        }
        if (dist[c][d] != INT_MAX)
        {
            cout << dist[c][d] << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
    return 0;
}
