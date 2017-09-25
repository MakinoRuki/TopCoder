#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll fac[14];
ll dp[1<<14][14];
int rem;
class DFSCount {
	public:
		int n;
		vector<string> g;
		int extract (int x) {
			int res = (1<<x);
			rem ^= (1<<x);
			for (int i = 0; i < n; ++i) {
				if (((1<<i) & rem) && (g[x][i] == 'Y')) {
					res ^= extract(i);
				}
			}
			return res;
		}
		ll solve (int st, int root) {
			if (dp[st][root] >= 0) return dp[st][root];
			rem = st ^ (1<<root);
			vector<int> components;
			components.clear();
			for (int i = 0; i < n; ++i) {
				if ((1<<i) & rem) {
					components.push_back(extract(i));
				} else {
					components.push_back(-1);
				}
			}
			int cnt = 0;
			ll res = 1LL;
			for (int i = 0; i < n; ++i) {
				if (components[i] >= 0) {
					int cur = components[i];
				//	cout<<rem<<" "<<i<<" "<<cur<<endl;
					cnt++;
					ll tmp = 0;
					for (int k = 0; k < n; ++k) {
						if (((1<<k) & cur) && (g[root][k] == 'Y')) {
							tmp += solve(cur, k);
						}
					}
					res = res * tmp;
				}
			}
			res *= fac[cnt];
			return dp[st][root] = res;
		}
		ll count (vector<string> G) {
			n = G.size();
			g = G;
			fac[0] = 1LL;
			for (int i = 1; i <= n; ++i) {
				fac[i] = fac[i - 1] * (ll)i;
			}
			ll ans = 0LL;
			memset(dp, -1, sizeof(dp));
			for (int i = 0; i < n; ++i) {
				ans += solve((1<<n) - 1, i);
			}
			return ans;
		}
};
