#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;
struct node
{
    map<int, int> mp;
    int xr = 0;
};
int a[N];
struct ST
{
    node t[4 * N];
    static const int inf = 1e9;

    node empty_node()
    {
        return node();
    }

    node merge(node a, node b)
    {
        node res;
        res.mp = a.mp;
        for (auto it : b.mp)
        {
            res.mp[it.first] += it.second;
        }
        res.xr = 0;
        for (auto it : res.mp)
        {
            if (it.second % 2 == 0)
                res.xr ^= it.first;
        }
        return res;
    }

    void build(int n, int b, int e)
    {
        if (b == e)
        {
            t[n].mp[a[b]]++;
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        t[n] = merge(t[l], t[r]);
    }

    node query(int n, int b, int e, int i, int j)
    {
        if (b > j || e < i)
            return empty_node();
        if (b >= i && e <= j)
            return t[n];
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j)); // change this
    }
} t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    t.build(1, 1, n);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        node nn = t.query(1, 1, n, l, r);
        cout << nn.xr << "\n";
    }

    return 0;
}