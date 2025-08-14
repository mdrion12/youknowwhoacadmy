#include <bits/stdc++.h>
using namespace std;

long long trailing_zeros(long long n)
{
    long long count = 0;
    while (n)
    {
        n /= 5;
        count += n;
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;

    // Binary search for lower bound of n where trailing_zeros(n) == m
    long long low = 0, high = 5LL * (m + 1), mid;
    long long left_bound = -1, right_bound = -1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        long long z = trailing_zeros(mid);
        if (z < m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
            if (z == m)
                left_bound = mid;
        }
    }

    if (left_bound == -1)
    {
        // কোনো n নেই যার trailing zeros == m
        cout << 0 << "\n";
        return 0;
    }

    // Binary search for upper bound of n where trailing_zeros(n) == m
    low = left_bound;
    high = 5LL * (m + 1);
    while (low <= high)
    {
        mid = (low + high) / 2;
        long long z = trailing_zeros(mid);
        if (z > m)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
            if (z == m)
                right_bound = mid;
        }
    }

    // Print results
    cout << right_bound - left_bound + 1 << "\n";
    for (long long i = left_bound; i <= right_bound; i++)
    {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}
