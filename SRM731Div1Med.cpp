#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 2002
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll dp[2][N];
ll comb[N][N];
ll revs[N];
class RndSubTree {
	public:
		ll getrev(ll a) {
			ll res = 1LL;
			ll b = mod - 2LL;
			while(b) {
				if(b & 1) res = res * a % mod;
				a = a * a % mod;
				b /= 2;
			}
			return res;
		}
		int count(int k) {
			for (int i = 0; i <= k; ++i) {
				comb[i][0] = 1LL;
				for (int j = 1; j <= i; ++j) {
					comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
				}
			}
			revs[0] = 1LL;
			for (int i = 1; i <= k; ++i) {
				revs[i] = revs[i - 1] * getrev(2LL) % mod;
			}
			memset(dp, 0LL, sizeof(dp));
			for (int i = 2; i <= k; ++i) {
				for (int j = 0; j < i; ++j) {
					int x = i - 1 - j;
					ll res = (dp[0][j] + dp[0][x]) % mod;
					res = (res + (dp[1][j] + j) * (x + 1LL) % mod) % mod;
					res = (res + (dp[1][x] + x) * (j + 1LL) % mod) % mod;
					res = res * comb[i - 1][j] % mod;
					res = res * revs[i - 1] % mod;
					dp[0][i] = (dp[0][i] + res) % mod;
					res = (dp[1][j] + dp[1][x] + i - 1) % mod;
					res = res * comb[i - 1][j] % mod;
					res = res * revs[i - 1] % mod;
					dp[1][i] = (dp[1][i] + res) % mod;
				}
			}
			return dp[0][k];
		}
};
