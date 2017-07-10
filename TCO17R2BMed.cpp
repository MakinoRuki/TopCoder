#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1002
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class DengklekGaneshAndTree {
	public:
		vector<int> edges[N];
		int n;
		ll dpdown[N][2], dpup[N][2];
		ll dplev[N];
		ll downmul[N], upmul[N];
		int lev[N];
		int getCount (string labels, vector<int> par) {
			n = par.size() + 1;
			memset(lev, 0, sizeof(lev));
			for (int i = 1; i < n; ++i) {
				edges[par[i - 1]].push_back(i);
				lev[i] = lev[par[i - 1]] + 1;
			}
			memset(downmul, 0, sizeof(downmul));
			for (int i = 0; i < n; ++i) {
				downmul[lev[i]] = 1;
			}
			for (int i = n - 1; i >= 0; --i) {
				dpdown[i][0] = 1;
				dpdown[i][1] = 1;
				for (int j = 0; j < edges[i].size(); ++j) {
					int v = edges[i][j];
					if (labels[v] == labels[i]) {
						dpdown[i][0] = (dpdown[i][0] * dpdown[v][0] % mod);
						dpdown[i][1] = (dpdown[i][1] * dpdown[v][1] % mod);
					} else {
						dpdown[i][0] = dpdown[i][0] * ((dpdown[v][0] + dpdown[v][1]) % mod) % mod;
						dpdown[i][1] = dpdown[i][1] * ((dpdown[v][0] + dpdown[v][1]) % mod) % mod;
					}
				}
				downmul[lev[i]] = downmul[lev[i]] * dpdown[i][0] % mod;
			}
			ll ans = (dpdown[0][0] + dpdown[0][1]) % mod;
			for (int l = 0; l <= n; ++l) {
				memset(dpup, 0, sizeof(dpup));
				memset(upmul, 0, sizeof(upmul));
				bool ok = false;
				for (int i = 0; i < n; ++i) {
					if (lev[i] == l) {
						dpup[i][0] = 1;
						ok = true;
					}
				}
				if (!ok) {
					break;
				}
				for (int i = 0; i < l; ++i) {
					upmul[i] = 1;
				}
				for (int i = n - 1; i >= 0; --i) {
					if (lev[i] < l) {
						dpup[i][0] = dpup[i][1] = 1;
						for (int j = 0; j < edges[i].size(); ++j) {
							int v = edges[i][j];
							if (labels[v] == labels[i]) {
								dpup[i][0] = dpup[i][0] * dpup[v][0] % mod;
								dpup[i][1] = dpup[i][1] * dpup[v][1] % mod;
							} else {
								dpup[i][0] = dpup[i][0] * ((dpup[v][0] + dpup[v][1]) % mod) % mod;
								dpup[i][1] = dpup[i][1] * ((dpup[v][0] + dpup[v][1]) % mod) % mod;
							}
						}
						upmul[lev[i]] = upmul[lev[i]] * dpup[i][0] % mod;
					}
				}
				dplev[l] = (dpup[0][0] + dpup[0][1]) % mod;
				for (int i = 0; i < l; ++i) {
					dplev[l] = (dplev[l] - upmul[i] * dplev[i] % mod + mod) % mod;
				}
				ans = (ans - dplev[l] * downmul[l] % mod + mod) % mod;
			}
			return ans;
		}
};
