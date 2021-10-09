#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;
int n, m;
struct segment {
	int l, r, w;
	bool operator < (const segment &a) {
		return w < a.w;
	}
} a[N];

struct IntervalTree {
	struct SNode {
		int val, lazy;
	};
	SNode node[4*N];

	void reset() {
		for (int i = 1; i <= 4*m; i++)
			node[i].lazy = node[i].val = 0;
	}

	void push(int id) {
		int &t = node[id].lazy;

		node[id*2].val += t;
		node[id*2].lazy += t;

		node[id*2+1].val += t;
		node[id*2+1].lazy += t;

		t = 0;
	}

	void update(int l, int r, int w, int id = 1, int low = 1, int high = m) {
		if (low > r || high < l) return;
		if (l <= low && high <= r) {
			node[id].lazy += w;
			node[id].val += w;
			return;
		}
		push(id);
		int mid = (low + high) >> 1;
		update(l, r, w, id*2, low, mid);
		update(l, r, w, id*2+1, mid+1, high);
		node[id].val = min(node[id*2].val, node[id*2+1].val);
	}

	int get(int l, int r, int id = 1, int low = 1, int high = m) {
		if (low > r || high < l) return INT_MAX;
		if (l <= low && high <= r) return node[id].val;
		push(id);
		int mid = (low + high) >> 1;
		int lef = get(l, r, id*2, low, mid);
		int rig = get(l, r, id*2+1, mid+1, high);
		return min(lef, rig);
	}
} IT;

int main() {
	ios :: sync_with_stdio (0);
	cin.tie (0);  cout.tie (0);

	if (fopen ("main.in", "r"))
		freopen ("main.in", "r", stdin);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i].l >> a[i].r >> a[i].w;

	sort(a+1, a+1+n);
	int res = INT_MAX;
	for (int i = 1, j = 1; i <= n; i++) {
		while (j <= n && !IT.get(2, m)) {
			IT.update(a[j].l+1, a[j].r, 1);
			j++;
			if (IT.get(2, m)) {
				res = min(res, a[j-1].w - a[i].w);
				break;
			}
		}
		if (IT.get(2, m)) {
			res = min(res, a[j-1].w - a[i].w);
		}
		IT.update(a[i].l+1, a[i].r, -1);
	}
	cout << res << '\n';

	return 0;
}