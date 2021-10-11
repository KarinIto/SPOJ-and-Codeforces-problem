#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9;
int n, a[100005], val[2];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	a[1] = 1; a[2] = 2; a[3] = 3, a[0] = 1;
	val[1] = 1; val[0] = -1;
	for (int i = 4; i <= n; ++i)
	{
		for (int j = 1; j <= 300; ++j)
		{
			int tmp = j * (3 * j - 1) / 2;
			if (tmp > i) break;
			a[i] = (0LL + a[i] + a[i - tmp] * (val[j & 1]) + 1LL * mod * mod) % mod;
			tmp = (- j) * (3 * (- j) - 1) / 2;
			if (tmp > i) break;
			a[i] = (0LL + a[i] + a[i - tmp] * (val[j & 1]) + 1LL * mod * mod) % mod;
		}
	}
	a[0] = 0;
	cout << a[n];
} 
