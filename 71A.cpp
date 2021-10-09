#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    cin >> n;
    while (n--)
    {
        cin >> s;
        if (s.size() > 10)
        {
            cout << *s.begin() << s.size() - 2 << *s.rbegin();
        }
        else cout << s;
        cout << '\n';
    }
}
