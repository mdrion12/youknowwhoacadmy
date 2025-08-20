#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 9;
vector<int> ar(N);

struct st
{
#define lc (n << 1)
#define rc (n << 1) + 1
    ll t[4 * N];
    ll lazy[4 * N];
    st()
    {
        memset(t, 0, sizeof(t));
        memset(lazy, 0, sizeof(lazy));
    }
    void push(int n, int b, int e)
    {
        if (lazy[n] == 0)
            return;
        t[n] = t[n] + (lazy[n] * (e - b + 1));
        if (b != e)
        {
            lazy[lc] += lazy[n];
            lazy[rc] += lazy[n];
        }
        lazy[n] = 0;
    }
    void pull(int n)
    {
        t[n] = t[lc] + t[rc];
    }
    void build(int n, int b, int e)
    {
        lazy[n] = 0;
        if (b == e)
        {
            t[n] = ar[b];
            return;
        }
        int mid = (b + e) >> 1;
        build(lc, b, mid);
        build(rc, mid + 1, e);
        pull(n);
    }
    void upd(int n, int b, int e, int i, int j, ll x)
    {
        push(n, b, e);
        if (b > j || e < i)
            return;
        if (b >= i && e <= j)
        {
            lazy[n] = x;
            push(n, b, e);
            return;
        }
        int mid = (b + e) >> 1;
        upd(lc, b, mid, i, j, x);
        upd(rc, mid + 1, e, i, j, x);
        pull(n);
    }
    ll combine(ll a, ll b)
    {
        return a + b;
    }
    ll query(int n, int b, int e, int i, int j)
    {
        push(n, b, e);
        if (b > j || e < i)
            return 0;
        if (b >= i && e <= j)
            return t[n];
        int mid = (b + e) >> 1;
        return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
    }
} t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int l, r;
            ll v;
            cin >> l >> r >> v;
            t.upd(1, 0, n - 1, l, r - 1, v);
        }
        else
        {
            int i, j;
            cin >> i >> j;
            cout << t.query(1, 0, n - 1, i, j - 1) << "\n";
        }
    }
    return 0;
}
