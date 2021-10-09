#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
const int MOD = 1000000007;

char rev(char ch) {
    return (ch == ')') ? '(' : '[';
}

void solve() {
    string s;
    cin >> s;
    vector<int> pref(s.size() + 1);

    stack<pair<char, int>> st;
    vector<pair<int, int>> v, v2;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' or s[i] == '[')
            st.push({s[i], i});
        else {
            if (st.empty())continue;
            if (st.top().first != rev(s[i])){
                while (!st.empty())st.pop();
                continue;
            }
            pair<char, int> tp = st.top();
            st.pop();
            v.push_back({tp.second, i});
        }
    }
    sort(v.begin(), v.end());
    pair<int, int> cur = {0, -1};
    for (auto x: v) {
        if (cur.first <= x.first and cur.second >= x.second)continue;
        if (x.first == cur.second + 1)
            cur = {cur.first, x.second};
        else
            cur = x;
        v2.push_back(cur);
    }
    for (int i = 0; i < s.size(); i++) {
        pref[i + 1] += pref[i];
        if (s[i] == '[')
            pref[i + 1]++;
    }
    pair<int, int> mx = {0, -1};
    int cnt = 0;
    for (auto x: v2) {
        int count = pref[x.second + 1] - pref[x.first];
        if (count > cnt) {
            cnt = count;
            mx = x;
        }
    }
    cout << cnt << endl;
    cout << s.substr(mx.first, mx.second - mx.first + 1) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;

    while (t--)
        solve();
    return 0;
}
