#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1500
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class ModEquation {
	public:
		int q;
		vector<int> fac;
		ll cnt[N][N];
		ll dp[2][N];
		vector<int> tar[N];
		void update (ll & target, ll value) {
			target = (target + value) % mod;
		}
		ll getPow(ll a, ll b) {
			ll res = 1LL;
			while (b) {
				if (b & 1) {
					res = res * a % mod;
				}
				a = a * a % mod;
				b /= 2;
			}
			return res;
		}
		vector<int> count (int n, int k, vector<int> query) {
			q = query.size();
			fac.clear();
			for (int i = 1; i * i <= k; ++i) {
				if (k % i == 0) {
					fac.push_back(i);
					if (i != k / i) {
						fac.push_back(k / i);
					}
				}
			}
			sort(fac.begin(), fac.end());
			for (int i = 0; i < fac.size(); ++i) {
				tar[i].clear();
				for (int j = i; j < fac.size(); ++j) {
					if (fac[j] % fac[i] == 0) tar[i].push_back(j);
				}
			}
			memset(cnt, 0LL, sizeof(cnt));
			for (int i = fac.size() - 1; i >= 0; --i) {
				cnt[0][i] = k / fac[i];
				for (int j = i + 1; j < fac.size(); ++j) {
					if (fac[j] % fac[i] == 0) {
						cnt[0][i] -= cnt[0][j];
					}
				}
			}
			for (int i = 1; i < fac.size(); ++i) {
				for (int j = 0; j < fac.size(); ++j) {
					int idx = lower_bound(fac.begin(), fac.end(), (int)__gcd((ll)k, (ll)fac[i] * (ll)fac[j])) - fac.begin();
					cnt[i][idx] += cnt[0][j];
				}
			}
			memset(dp, 0LL, sizeof(dp));
			int now = 0;
			dp[now][0] = 1LL;
			for (int i = 0; i < n; ++i) {
				memset(dp[now ^ 1], 0LL, sizeof(dp[now ^ 1]));
				for (int p1 = 0; p1 < fac.size(); ++p1) {
					for (int p2 = 0; p2 < tar[p1].size(); ++p2) {
						update(dp[now ^ 1][tar[p1][p2]], dp[now][p1] * cnt[p1][tar[p1][p2]] % mod);
					}
				}
				now ^= 1;
			}
			vector<int> ans;
			ans.clear();
			for (int i = 0; i < q; ++i) {
				int idx = lower_bound(fac.begin(), fac.end(), __gcd(query[i], k)) - fac.begin();
				ans.push_back((int)(dp[now][idx] * getPow((ll)cnt[0][idx], mod - 2) % mod));
			}
			return ans;
		}
};
