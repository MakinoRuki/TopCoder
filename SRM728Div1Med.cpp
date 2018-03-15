#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 610
using namespace std;
typedef long long ll;
ll mod = 998244353LL;
ll dp[N / 2][N];
ll table[N][N];
class IncreasingSequences {
	public:
		int n;
		ll getrev(ll x) {
			ll b = mod - 2;
			ll res = 1LL;
			while(b) {
				if (b & 1) res = res * x % mod;
				x = x * x % mod;
				b /= 2;
			}
			return res;
		}
		int count(vector<int> L, vector<int> R) {
			n = L.size();
			memset(dp, 0LL, sizeof(dp));
			vector<int> secs;
			secs.clear();
			for (int i = 0; i < n; ++i) {
				L[i] += n - i;
				R[i] += n - i;
			}
			for (int i = 0; i < n; ++i) {
				secs.push_back(L[i]);
				secs.push_back(R[i] + 1);
			}
			secs.push_back(0);
			secs.push_back(1000000005);
			sort(secs.begin(), secs.end());
			secs.erase(unique(secs.begin(), secs.end()), secs.end());
			int m = secs.size();
			for (int i = 0; i < m - 1; ++i) {
				dp[0][i] = 1LL;
				table[i][0] = 1LL;
				ll len = secs[i + 1] - secs[i] - 1;
				for (int j = 1; j <= n; ++j) {
					len++;
					table[i][j] = table[i][j - 1] * (ll)len % mod * getrev((ll)j) % mod;
				}
			}
			for (int i = 1; i <= n; ++i) {
				if (L[i - 1] <= secs[0] && R[i - 1] + 1 >= secs[1]) {
					dp[i][0] = table[0][i];
				} else {
					break;
				}
			}
		//	ll ans = 0LL;
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j < m - 1; ++j) {
					dp[i][j] = dp[i][j - 1];
					for (int k = 1; k <= i; ++k) {
						if (!(L[i - k] <= secs[j] && R[i - k] + 1 >= secs[j + 1])) break;
						dp[i][j] = (dp[i][j] + dp[i - k][j - 1] * table[j][k] % mod) % mod;
					}
				}
			}
			return dp[n][m - 2];
		}
};
