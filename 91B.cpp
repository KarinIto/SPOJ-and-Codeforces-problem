#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], b[N], T[N];
void update(int x, int i)
{
    for (; x <= n; x += x & -x)
    {
        T[x] = max(T[x], i);
    }
}
int get(int x)
{
    int ans = 0;
    for (; x > 0; x -= x & -x)
    {
        ans = max(ans, T[x]);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; ++i)
    {
        a[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;
    }
    for (int i = n; i > 0; --i)
    {
        b[i] =  max(-1, get(a[i] - 1)  - i - 1);
        update(a[i], i);
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << b[i] << ' ';
    }
}
