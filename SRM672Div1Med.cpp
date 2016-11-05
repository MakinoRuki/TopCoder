#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 2002
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class AlmostEulerianGraph {
	public:
		ll dpT[N], dpE[N];
		ll comb[N][N];
		ll mypow (ll a, ll b) {
			ll res = 1LL;
			while (b) {
				if (b & 1) res = res * a % mod;
				a = (a * a) % mod;
				b /= 2;
			}
			return res;
		}
		int calculateGraphs (int n) {
			memset(dpT, 0, sizeof(dpT));
			memset(dpE, 0, sizeof(dpE));
			dpT[1] = dpE[1] = 1LL;
			memset(comb, 0LL, sizeof(comb));
			for (int i = 0; i <= n; ++i) {
				comb[i][0] = 1LL;
				for (int j = 1; j <= i; ++j) {
					comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
				}
			}
			for (int i = 2; i <= n; ++i) {
				ll dpD = 0LL;
				for (int j = 1; j < i; ++j) {
					dpD = (dpD + dpE[j] * dpT[i - j] % mod * comb[i - 1][j - 1] % mod) % mod;
				}
				dpT[i] = mypow(2, (i - 1) * (i - 2) / 2);
				dpE[i] = (dpT[i] - dpD + mod) % mod;
			}
			ll ans = (n * (n - 1) / 2 + 1) % mod;
			ans = (ans * dpE[n]) % mod;
			return ans;
		}
};
