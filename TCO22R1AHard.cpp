#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-10
#define M 200005
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
ll dp[N][N];
ll comb[N][N];
ll fac[N];
class SkyscraperCounting {
public:
	int count(string v) {
		int n = (int)v.size();
		if (v[0] != 'O') return 0;
		memset(comb, 0LL, sizeof(comb));
		for (int i = 0; i <= n; ++i) {
			comb[i][0] = 1LL;
			for (int j = 1; j <= i; ++j) {
				comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % mod;
			}
		}
		fac[0] = 1LL;
		for (int i =1; i <= n; ++i) {
			fac[i] = fac[i-1] * (ll)i % mod;
		}
		for (int i = 1; i <= n; ++i) {
			dp[0][i] = 1LL;
		}
		for (int i = 1; i < n; ++i) {
			if (v[i] == 'O') {
				for (int j = 1; j <= n; ++j) {
					for (int j2 = 1; j2 < j; ++j2) {
						dp[i][j] = (dp[i-1][j2] + dp[i][j]) % mod;
					}
				}
			} else {
				for (int j = 1; j <= n; ++j) {
					if (dp[i-1][j]) {
						if (j-i >= 1) {
							dp[i][j] = (dp[i][j] + dp[i-1][j] * (ll)(j-i) % mod) % mod;
						}
					}
				}
			}
		}
		ll ans = 0LL;
		for (int i = 1; i <= n; ++i) {
			ans = (ans + dp[n-1][i]) % mod;
		}
		return ans;
	}
};
