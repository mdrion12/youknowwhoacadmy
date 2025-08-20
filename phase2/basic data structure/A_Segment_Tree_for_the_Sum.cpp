#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 5;
vector<int> ar(N);
struct st
{
#define lc (n << 1)
#define rc (n << 1) + 1
    ll t[4 * N];
    static const int inf = -1e9;
    st()
    {
        memset(t, 0, sizeof(t));
    }
    void pull(int n)
    {
        t[n] = t[lc] + t[rc];
    }
    ll combine(ll a, ll b)
    {
        return a + b;
    }
    void upd(int n, int b, int e, int i, int x)
    {
        if (b > i || e < i)
        {
            return;
        }
        if (b == e)
        {
            t[n] = x;
            return;
        }
        int mid = (b + e) / 2;
        upd(lc, b, mid, i, x);
        upd(rc, mid + 1, e, i, x);
        pull(n);
    }
    void build(int n, int b, int e)
    {
        if (b == e)
        {
            t[n] = ar[b];
            return;
        }
        int mid = (b + e) / 2;
        build(lc, b, mid);
        build(rc, mid + 1, e);
        pull(n);
    }
    ll query(int n, int b, int e, int i, int j)
    {
        if (b > j || e < i)
        {
            return 0;
        }
        if (b >= i && e <= j)
        {
            return t[n];
        }
        int mid = (b + e) / 2;
        return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
    }

} t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    t.build(1, 0, n - 1);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            t.upd(1, 0, n - 1, b, c);
        }
        else
        {
            cout << t.query(1, 0, n - 1, b, c - 1) << "\n";
        }
    }

    return 0;
}