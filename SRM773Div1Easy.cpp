#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
class ChristmasSongBroadcast {
	public:
		int n;
		int par[N];
		bool has[N];
		int find(int u) {
			return u == par[u] ? u : par[u] = find(par[u]);
		}
		ll getpw(ll x) {
			ll res=1LL;
			ll b = mod-2;
			while(b) {
				if (b&1) res=res*x%mod;
				x = x*x % mod;
				b /= 2;
			}
			return res;
		}
		int minimizeCost(int t, vector <int> a, vector <int> b, vector <string> dc) {
			n = a.size();
			memset(has, false, sizeof(has));
			for (int i = 0; i <n ; ++i) {
				par[i] = i;
			}
			vector<pair<ll, pair<int, int>>> rk;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j <500; ++j) {
					ll v = (j - b[i] + mod) % mod;
					v = v * getpw((ll)a[i]) % mod;
					if (v < t) {
						rk.push_back(make_pair((ll)j, make_pair(i, -1)));
						break;
					}
				}
				rk.push_back(make_pair((ll)b[i], make_pair(i, -1)));
			}
			for (int i = 0; i < n; ++i) {
				for (int j = i+1; j < n; ++j) {
					rk.push_back(make_pair(dc[i][j], make_pair(i, j)));
				}
			}
			sort(rk.begin(), rk.end());
			ll ans=0LL;
			for (int i = 0; i < rk.size(); ++i) {
				ll w = rk[i].first;
				int u = rk[i].second.first;
				int v = rk[i].second.second;
				if (v < 0) {
					int p = find(u);
					if (!has[p]) {
						has[p] = true;
						ans += w;
					}
				} else {
					int pu = find(u);
					int pv = find(v);
					if (pu == pv) continue;
					if (has[pu] && has[pv]) continue;
					par[pu] = pv;
					if (has[pu] || has[pv]) {
						has[pu] = true;
						has[pv] = true;
					}
					ans += w;
				}
			}
			return ans;
		}
};
