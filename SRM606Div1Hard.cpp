#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#define N 52
using namespace std;
typedef long long ll;
class Subcube {
public:
	int n;
	unordered_set<ll> ans;
	ll dis[N][N];
	void dfs(int cur, ll s, ll d) {
		if (cur == n) {
			ans.insert(s);
			return;
		}
		dfs(cur + 1, s, d);
		for (int i = 0; i < n; ++i) {
			if (!((1LL<<i) & s)) continue;
			ll d1 = dis[i][cur];
			if (d1 != d && d1 != 2 * d && d1 != 3 * d) return;
			for (int j = 0; j < n; ++j) {
				if (i != j && ((1LL<<j)&s)) {
					ll d2 = dis[j][cur]+d1+dis[i][j];
					if (d2 != 4*d && d2 != 6*d) return;
				}
			}
		}
		dfs(cur + 1, (1LL<<cur) | s, d);
	}
	ll getCount(vector<int> x, vector<int> y, vector<int> z) {
		n = x.size();
		ans.clear();
		unordered_set<ll> ds;
		ds.clear();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				dis[i][j] = (ll)(x[i]-x[j])*(ll)(x[i]-x[j])+(ll)(y[i]-y[j])*(ll)(y[i]-y[j])+(ll)(z[i]-z[j])*(ll)(z[i]-z[j]);
				ds.insert(dis[i][j]);
				if (dis[i][j] % 2 == 0) ds.insert(dis[i][j] / 2);
				if (dis[i][j] % 3 == 0) ds.insert(dis[i][j] / 3);
			}
		}
		ds.insert(0);
		for (auto d = ds.begin(); d != ds.end(); ++d) {
			dfs(0, 0, *d);
		}
		ans.erase(0);
		return ans.size();
	}
};
