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
    int merge(int i, int j, int a, int b)
    {
        int pw = 0;
        int l = b - a + 1;
        while (l > 1)
        {
            pw++;
            l /= 2;
        }
        if (pw % 2 == 1)
        {
            return i | j;
        }
        else
            return i ^ j;
    }
    static const int inf = 1e9;
    st()
    {
        memset(t, 0, sizeof(t));
    }
    void pull(int n, int b, int e)
    {
        t[n] = merge(t[lc], t[rc], b, e);
    }
    ll combine(ll a, ll b)
    {
        return min(a, b);
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
        pull(n, b, e);
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
        pull(n, b, e);
    }

} t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    n = 1 << n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ar[i];
    }
    t.build(1, 1, n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        t.upd(1, 1, n, a, b);
        cout << t.t[1] << "\n";
    }

    return 0;
}