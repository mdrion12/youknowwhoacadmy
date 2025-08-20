#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 9;
const int MOD = 1e9 + 7;

struct st
{
#define lc (n << 1)
#define rc (n << 1) + 1
    int t[4 * N];
    int lazy[4 * N];

    st()
    {
        for (int i = 0; i < 4 * N; i++)
        {
            t[i] = 0;
            lazy[i] = 1;
        }
    }

    void push(int n, int b, int e)
    {
        if (lazy[n] == 1)
            return;
        t[n] = (1LL * t[n] * lazy[n]) % MOD;
        if (b != e)
        {
            lazy[lc] = (1LL * lazy[lc] * lazy[n]) % MOD;
            lazy[rc] = (1LL * lazy[rc] * lazy[n]) % MOD;
        }
        lazy[n] = 1;
    }

    void pull(int n)
    {
        t[n] = (t[lc] + t[rc]) % MOD;
    }

    void build(int n, int b, int e)
    {
        lazy[n] = 1;
        if (b == e)
        {
            t[n] = 1;
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
            // lazy[n] = (1LL * lazy[n] * x) % MOD;
            lazy[n] = x;
            push(n, b, e);
            return;
        }
        int mid = (b + e) >> 1;
        upd(lc, b, mid, i, j, x);
        upd(rc, mid + 1, e, i, j, x);
        pull(n);
    }

    ll query(int n, int b, int e, int i, int j)
    {
        push(n, b, e);
        if (b > j || e < i)
            return 0;
        if (b >= i && e <= j)
            return t[n];
        int mid = (b + e) >> 1;
        return (query(lc, b, mid, i, j) + query(rc, mid + 1, e, i, j)) % MOD;
    }
} t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    t.build(1, 0, n - 1);

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
