#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main()
{
    o_set<int> se;
    int n;
    cin >> n;
    vector<int> v(n), l(n), r(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        r[i] = se.order_of_key(v[i]);
        se.insert(v[i]);
    }
    se.clear();
    for (int i = 0; i < n; i++)
    {
        l[i] = v.size() - se.order_of_key(v[i] + 1);
        se.insert(v[i]);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += 1LL * l[i] * r[i];
    }
    cout << ans << "\n";
}