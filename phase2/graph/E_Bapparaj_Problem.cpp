#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct operation
{
    int l, r, d;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    vector<ll> v(n + 2); // 1-indexed + 1 extra
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    vector<operation> op(m + 2);
    for (int i = 1; i <= m; i++)
        cin >> op[i].l >> op[i].r >> op[i].d;

    vector<ll> opcount(m + 2, 0);
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        opcount[x] += 1;
        opcount[y + 1] -= 1;
    }

    for (int i = 1; i <= m; i++)
        opcount[i] += opcount[i - 1];

    vector<ll> diff(n + 2, 0);
    for (int i = 1; i <= m; i++)
    {
        ll val = 1LL * op[i].d * opcount[i];
        diff[op[i].l] += val;
        diff[op[i].r + 1] -= val;
    }

    for (int i = 1; i <= n; i++)
    {
        diff[i] += diff[i - 1];
        v[i] += diff[i];
        cout << v[i] << " ";
    }
    cout << "\n";

    return 0;
}
