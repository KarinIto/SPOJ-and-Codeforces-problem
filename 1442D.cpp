#include <bits/stdc++.h>
using namespace std;

int n, k;
long long res;
vector < vector <int> > a;
vector < long long > sum_a;

void maximize (long long &a, long long b) {
	a = max (a, b);
}

void cal(int l, int r, vector <long long> &f) {
	if (l == r) {
		long long sum = 0;
		for (int i = 0; i < (int) a[l].size(); i++) {
			sum += a[l][i];
			maximize (res, f[k-i-1] + sum);
		}
		return;
	}
	
	int mid = (l + r) >> 1;
	vector <long long> dp = f;
	for (int x = mid+1; x <= r; x++)
		for (int i = k - a[x].size(); i >= 0; i--)
			maximize (dp[i+a[x].size()], dp[i] + sum_a[x]);
	cal (l, mid, dp);

	dp = f;
	for (int x = l; x <= mid; x++)
		for (int i = k - a[x].size(); i >= 0; i--)
			maximize (dp[i+a[x].size()], dp[i] + sum_a[x]);
	cal (mid+1, r, dp);

	return;
}

int main() {
	ios :: sync_with_stdio (0);
	cin.tie (0);  cout.tie (0);

	if (fopen ("main.in", "r"))
		freopen ("main.in", "r", stdin);

	cin >> n >> k;
	a.resize (n+1);
	sum_a.resize (n+1);
	for (int i = 1; i <= n; i++) {
		int sz; cin >> sz;
		a[i].resize (sz);
		for (int &x : a[i]) cin >> x;
		a[i].resize (min (sz, k));
		for (int x : a[i]) sum_a[i] += x;
	}
	
	vector <long long> f(k+1, 0);
	cal(1, n, f);

	cout << res << '\n';

	return 0;
}