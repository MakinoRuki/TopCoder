#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000000000000037LL;
class EllysHash {
	public:
		vector<ll> leftv;
		vector<ll> rightv;
		void dfs(int cur, int sz, string& a, string& b, string& c, ll v, vector<ll>& vec) {
			if (cur == sz) {
				vec.push_back(v);
				return;
			}
			dfs(cur + 1, sz, a, b, c, (v * 127LL % mod + (a[cur])) % mod, vec);
			dfs(cur + 1, sz, a, b, c, (v * 127LL % mod + (b[cur])) % mod, vec);
			dfs(cur + 1, sz, a, b, c, (v * 127LL % mod + (c[cur])) % mod, vec);
		}
		ll getHash(int n, string a, string b, string c) {
			leftv.clear();
			rightv.clear();
			ll v = 0;
			dfs(0, n/2, a, b, c, v, leftv);
			v = 0;
			dfs(n/2, n, a, b, c, v, rightv);
			sort(rightv.begin(), rightv.end());
			ll ans = mod;
			for (int i = 0; i < leftv.size(); ++i) {
				ll pwv = leftv[i];
				for (int j = 1; j <= n - n/2; ++j) {
					pwv = pwv * 127LL % mod;
				}
				ll res = (pwv + rightv[0]) % mod;
				auto it = lower_bound(rightv.begin(), rightv.end(), mod - pwv) - rightv.begin();
				if (it < rightv.size()) {
					res = min(res, (pwv + rightv[it]) % mod);
				}
				ans = min(ans, res);
			}
			return ans;
		}
};
