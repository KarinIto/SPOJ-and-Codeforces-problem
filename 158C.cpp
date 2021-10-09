#include <bits/stdc++.h>
using namespace std;
string s, st;
int q;
vector <string> vt;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while(q--)
    {
        cin >> s;
        if (s == "pwd")
        {
            cout << '/';
            for (auto x : vt)
            {
                cout << x << '/';
            }
            cout << '\n';
            continue;
        }
        cin >> s;
        for (int i = 0; s[i]; ++i)
        {
            char c = s[i];
            if (i == 0 && c == '/')
            {
                vt.clear();
                continue;
            }
            if (c == '/')
            {
//                cout << "err: " << st << '\n';
                if (st == "..") vt.pop_back();
                else vt.push_back(st);
                st = "";
                continue;
            }
            st += c;
        }
//        cout << "err: " << st << '\n';
        if (st == "..") vt.pop_back();
        else vt.push_back(st);
        st = "";
    }
}
