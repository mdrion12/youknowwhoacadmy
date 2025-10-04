#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "No\n";
#define yes cout << "Yes\n";

const int N = 210;
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
char arr[N][N];
bool valid(int x, int y)
{
    if (x >= 1 && x <= n && y >= 1 && y <= m && arr[x][y] != '#')
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int startx, starty, endx, endy;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'S')
            {
                startx = i;
                starty = j;
            }
            if (arr[i][j] == 'T')
            {
                endx = i;
                endy = j;
            }
        }
    }

    int x;
    cin >> x;
    int dist[N][N];
    int medicine[N][N];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dist[i][j] = -1;
            medicine[i][j] = 0;
        }
    }

    for (int i = 1; i <= x; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        medicine[u][v] = w;
    }
    priority_queue<tuple<int, int, int>> q;
    int start_energy = medicine[startx][starty];
    q.push({start_energy, startx, starty});
    dist[startx][starty] = start_energy;

    while (!q.empty())
    {
        auto parent = q.top();
        q.pop();
        int energy, x, y;
        tie(energy, x, y) = parent;
        if (energy < dist[x][y])
            continue;
        for (auto it : dir)
        {
            int cx = x + it.first;
            int cy = y + it.second;
            if (valid(cx, cy))
            {
                int nd = energy - 1;
                if (nd < 0)
                    continue;
                nd = max(nd, medicine[cx][cy]);

                if (nd > dist[cx][cy])
                {
                    dist[cx][cy] = nd;
                    q.push({nd, cx, cy});
                }
            }
        }
    }

    if (dist[endx][endy] != -1)
    {
        yes
    }
    else
    {
        no
    }
    return 0;
}
