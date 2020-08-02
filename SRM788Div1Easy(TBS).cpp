#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 200005
#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
class RailwayMaster {
public:
	int par[200];
	int find(int u) {
		return u == par[u] ? u : par[u] = find(par[u]);
	}
	int maxProfit(int n, int m, int k, vector<int> a, vector<int> b, vector<int> v) {
		for (int i = 0; i < n; ++i) {
			par[i] = i;
		}
		vector<pair<int,int>> es;
		es.clear();
		for (int i = 0; i < m; ++i) {
			es.push_back(make_pair(v[i], i));
		}
		sort(es.begin(), es.end());
		vector<int> ws;
		ws.clear();
		for (int i = 0; i < m; ++i) {
			int id = es[i].second;
			int pa = find(a[id]);
			int pb = find(b[id]);
			if (pa != pb) {
				par[pa] = pb;
			} else {
				ws.push_back(es[i].first);
			}
		}
		sort(ws.begin(), ws.end());
		int ans=0;
		reverse(ws.begin(), ws.end());
		for (int i = 0; i < min((int)ws.size(), k); ++i) {
			ans += ws[i];
		}
		return ans;
	}
};
