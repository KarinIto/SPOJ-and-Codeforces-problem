#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
int n, m, k, fin, st, org;
deque <int> q;
int d[222], p[222], M[222];
int capa[222][222], cost[222][222], flow[222][222];
vector <int> path;
void pape()
{
	for (int i = 1; i <= n; ++i) d[i] = inf, M[i] = 2;
	d[st] = 0;
	q.push_back(st);
	while (!q.empty())
	{
		int u = q.front(); q.pop_front();
		M[u] = 0;
		for (int v = 1; v <= n; ++v)
		{
			int uv = cost[u][v] * (flow[u][v] < 0 ? -1 : 1);
			if (capa[u][v] - flow[u][v] > 0 && d[v] > d[u] + uv)
			{
				d[v] = d[u] + uv;
				p[v] = u;
				if (M[v] == 2)
				{
                    M[v] = 1;
                    q.push_back(v);
                }
                else if (M[v] == 0)
                {
                    M[v] = 1;
                    q.push_front(v);
                }
			}
		}
	}
}
	
void go(int u)
{
  	path.push_back(u);
  	for (int v = 1; v <= n; ++v)
  		if (flow[u][v] > 0)
  		{
    		flow[u][v] = 0; go(v); break;
  		}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	if (fopen("input.txt", "r"))
		freopen("input.txt", "r", stdin);
	cin >> n >> m >> k >> st >> fin;
	while (m--)
	{
		int u, v, c;
		cin >> u >> v >> c;
		capa[u][v] = capa[v][u] = 1;
		cost[u][v] = cost[v][u] = c;
	}
	int Flow = 0, res = 0;
	++n;
	cost[n][st] = 0;
	capa[n][st] = k;
	org = st; st = n;
	while (1)
	{
		pape();
		if (d[fin] == inf) break;
		int f = inf, cur = fin;
		while (cur != st)
		{
			f = min(f, flow[p[cur]][cur] >= 0 ? (capa[p[cur]][cur] - flow[p[cur]][cur]) : -flow[p[cur]][cur]);
			cur = p[cur];
		}
		Flow += f;
		res += f * d[fin];
		cur = fin;
		while (cur != st) 
		{
            flow[p[cur]][cur] += f;
            flow[cur][p[cur]] -= f;
            cur = p[cur];
        }
	}
	if (Flow < k)
	{
		cout << -1;
		exit(0);
	}
	cout << res << '\n';
	while (k--)
	{
		path.clear();
      	go(org);
      	cout << path.size() << ' ';
      	for (int it: path)
        	cout << it << ' ';
      	cout << '\n';
  	}
} 
