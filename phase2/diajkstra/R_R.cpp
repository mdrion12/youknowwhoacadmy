#include <bits/stdc++.h>
using namespace std;
#define ll long long

// prime check function
bool is_prime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

// generate next valid numbers by increasing/decreasing one digit
vector<string> getString(string s)
{
    vector<string> ans;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        string t = s;
        if (t[i] > '0') // decrease
        {
            t[i]--;
            if (!is_prime(stoi(t)))
                ans.push_back(t);
        }
        t = s;
        if (t[i] < '9') // increase
        {
            t[i]++;
            if (!is_prime(stoi(t)))
                ans.push_back(t);
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++)
    {
        string start, end;
        cin >> start >> end;
        int len = start.size(); // fix length

        unordered_map<string, ll> dist;
        priority_queue<pair<ll, string>, vector<pair<ll, string>>, greater<>> pq;

        dist[start] = stoi(start);
        pq.push({stoi(start), start});

        ll answer = -1;

        while (!pq.empty())
        {
            auto pa = pq.top();
            pq.pop();
            ll cost = pa.first;
            string node = pa.second;

            if (node == end)
            {
                answer = cost;
                break;
            }

            if (cost > dist[node])
                continue;

            for (string next : getString(node))
            {
                ll nd = cost + stoi(next);
                if (!dist.count(next) || nd < dist[next])
                {
                    dist[next] = nd;
                    pq.push({nd, next});
                }
            }
        }

        cout << "Case " << tc << ": " << answer << "\n";
    }
}
