#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#define N 52
#define pii pair<int, int>
#define mp make_pair
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
map<vector<int>, ll> dp[N][N];
class CoastGuard {
	public:
		int n;
		ll dfs(int l, int r, vector<int>& v, vector<pii>& rk, vector<int>& d) {
			if (v.size() <= 1) return 1;
			if (dp[l][r].find(v) != dp[l][r].end()) return dp[l][r][v];
			ll res = 0LL;
			for (int i = l; i <= r; ++i) {
				vector<int> lft;
				vector<int> rit;
				for (int j = 0; j < v.size() - 1; ++j) {
					int idx1 = v.back();
					int idx2 = v[j];
					ll crs = (rk[idx1].second - d[i]) * rk[idx2].first - (rk[idx2].second - d[i]) * rk[idx1].first;
					if (crs > 0) {
						lft.push_back(v[j]);
					}
					if (crs < 0) {
						rit.push_back(v[j]);
					}
				}
				if ((lft.size() == i - l) && (rit.size() == r - i)) res = (res + dfs(l, i - 1, lft, rk, d) * dfs(i + 1, r, rit, rk, d) % mod) % mod;
			}
			return dp[l][r][v] = res;
		} 
		int count(vector<int> d, vector<int> x, vector<int> y) {
			n = d.size();
			vector<pii> rk;
			vector<int> v;
			v.clear();
			rk.clear();
			sort(d.begin(), d.end());
			for (int i = 0; i <= n; ++i) {
				for (int j = 0; j <= n; ++j) {
					dp[i][j].clear();
				}
			}
			for (int i = 0; i < n; ++i) {
				rk.push_back(mp(y[i], x[i]));
			}
			sort(rk.begin(), rk.end());
			for (int i = 0; i < n; ++i) {
				v.push_back(i);
			}
			return dfs(0, n - 1, v, rk, d);
		}
};
