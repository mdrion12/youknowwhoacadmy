#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 9, inf = 1e9;
int a[N];
struct node
{
    int max_prefix_sum, max_suffix_sum;
    int max_subarray_sum;
    int total_sum;
};
node t[N * 4];

node merge(node l, node r)
{
    if (l.total_sum == inf)
        return r;
    if (r.total_sum == inf)
        return l;
    node ans;
    ans.max_subarray_sum = max(l.max_subarray_sum, r.max_subarray_sum);
    ans.max_subarray_sum = max(ans.max_subarray_sum, l.max_suffix_sum + r.max_prefix_sum);

    ans.max_prefix_sum = max(l.max_prefix_sum, l.total_sum + r.max_prefix_sum);
    ans.max_suffix_sum = max(r.max_suffix_sum, r.total_sum + l.max_suffix_sum);

    ans.total_sum = l.total_sum + r.total_sum;
    return ans;
}

void build(int n, int b, int e)
{
    if (b == e)
    {
        t[n].max_prefix_sum = a[b];
        t[n].max_suffix_sum = a[b];
        t[n].max_subarray_sum = a[b];
        t[n].total_sum = a[b];
        return;
    }
    int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = merge(t[l], t[r]);
}

void upd(int n, int b, int e, int i, int v)
{
    if (i < b or e < i)
        return;
    if (b == e)
    {
        t[n].max_prefix_sum = v;
        t[n].max_suffix_sum = v;
        t[n].max_subarray_sum = v;
        t[n].total_sum = v;
        return;
    }
    int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
    upd(l, b, mid, i, v);
    upd(r, mid + 1, e, i, v);
    t[n] = merge(t[l], t[r]);
}

node query(int n, int b, int e, int i, int j)
{
    if (e < i or j < b)
        return {inf, inf, inf, inf};
    if (b >= i and e <= j)
    {
        return t[n];
    }
    int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
    return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}

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
    build(1, 1, n);
    int q;
    cin >> q;
    while (q--)
    {
        int ty;
        cin >> ty;
        if (ty == 0)
        {
            int i, x;
            cin >> i >> x;
            upd(1, 1, n, i, x);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            node ans = query(1, 1, n, l, r);
            cout << ans.max_subarray_sum << '\n';
        }
    }
    return 0;
}