#include <bits/stdc++.h>
using namespace std;

int i, j, k, l, root, val, cont;
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    int n = s.length(), dp[n]= {}, pre[n+1]= {};
    for(i = 0; i < n; i++) dp[i]= 20000;
    for(k= -1; k < n; k++)
    {
        pre[k + 1]=0;
        for(i = k + 2, l = 0; i < n;) (s[l + k + 1] == s[i]) ? (pre[i++] = ++l) : (l ? l = pre[k + l] : pre[i++] = 0);
        for(j = k + 1; j<n; j++)
        {
            root = ((j - k) % (j - k - pre[j])) ? (j - k) : (j - k - pre[j]);
            val = (j - k) / root;
            for(cont = 0; val; cont++) val /= 10;
            dp[j] = min(dp[j], ((k == -1) ? 0 : dp[k]) + cont + root);
        }
    }
    cout << dp[n - 1];
    return 0;
}