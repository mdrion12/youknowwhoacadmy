#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "No" << "\n";
#define yes cout << "Yes" << "\n";
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    stack<char> st;
    int cnt = 0;
    for (auto it : s)
    {
        if (!st.empty() && st.top() == it)
        {
            st.pop();
            cnt++;
        }
        else
        {
            st.push(it);
        }
    }
    if (cnt % 2 == 0)
    {
        no
    }
    else
    {
        yes
    }
    return 0;
}