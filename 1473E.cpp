#include <bits/stdc++.h>
using namespace std;

int main() {
    ios :: sync_with_stdio (0);
    cin.tie (0);  cout.tie (0);

    //freopen ("main.in", "r", stdin);

    const long long inf = 1e15;
    int n, m; cin >> n >> m;
    vector < vector < pair <int, int> > > adj(n+1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back ({v, w});
        adj[v].push_back ({u, w});
    }

    vector < vector <long long> > d(n+1, vector<long long> (4));
    for (int i = 1; i <= n; i++)
        for (int t = 0; t < 4; t++)
            d[i][t] = inf;

    auto const BIT=[&](int x, int k) {
        return (x >> k) & 1;
    };

    struct SVertex {
        int u, status;
        long long w;
        bool operator > (SVertex const &A) const {
            return w > A.w;
        }
    };

    priority_queue < SVertex, vector <SVertex>, greater <SVertex> > heap;
    heap.push ({1, 0, 0}); d[1][0] = 0;

    while (heap.size()) {
        int u = heap.top().u;
        int s = heap.top().status;
        long long du = heap.top().w;
        heap.pop();
        if (du != d[u][s]) continue;
        for (auto it: adj[u]) {
            int v = it.first;
            int w = it.second;
            if (d[v][s] > d[u][s] + w) {
                d[v][s] = d[u][s] + w;
                heap.push ({v, s, d[v][s]});
            }
            if (BIT(s, 0) == 0) {
                if (d[v][s+1] > d[u][s] + 2 * w) {
                    d[v][s+1] = d[u][s] + 2 * w;
                    heap.push({v, s+1, d[v][s+1]});
                }
            }
            if (BIT(s, 1) == 0) {
                if (d[v][s+2] > d[u][s]) {
                    d[v][s+2] = d[u][s];
                    heap.push({v, s+2, d[v][s+2]});
                }
            }
            if (BIT(s, 0) == 0 && BIT(s, 1) == 0) {
                if (d[v][s+3] > d[u][s] + w) {
                    d[v][s+3] = d[u][s] + w;
                    heap.push({v, s+3, d[v][s+3]});
                }
            }
        }
    }

    for (int i = 2; i <= n; i++)
        cout << d[i][3] << ' ';

    return 0;
}