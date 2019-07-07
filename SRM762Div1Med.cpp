// 本题正解应该是FFT。
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class StrawberryHard {
	public:
    // 全部用ll会导致转移时求mod次数太多，全部用__int128会导致计算太慢。
		ll dpfrom[15000];
		__int128 dpto[15000];
	//	__int128 dp[2][15000];
		ll getpw(ll a, ll b) {
			ll res = 1LL;
			while(b) {
				if (b & 1) res = res * a % mod;
				a = a * a % mod;
				b /= 2;
			}
			return res;
		}
		int competitive(int n, int k, int ar, int br, int seed) {
			vector<ll> a;
			vector<ll> b;
			ll as = 0;
			ll bs = 0;
			ll stat = seed;
			for (int i = 0; i <= 2*k; ++i) {
				stat = (1103515245LL * stat + 12345);
				stat = stat % (1LL << 31);
				a.push_back(stat % ar);
				as += a.back();
				stat = (1103515245LL * stat + 12345);
				stat = stat % (1LL << 31);
				b.push_back(stat % br);
				bs += b.back();
			}
			as = getpw(as % mod, mod-2);
			bs = getpw(bs % mod, mod-2);
			for (int i = 0; i <= 2* k; ++i) {
				a[i] = a[i] * as % mod;
				b[i] = b[i] * bs % mod;
			}
		//	memset(dpto, 0, sizeof(dpto));
			memset(dpfrom, 0, sizeof(dpfrom));
			dpfrom[k] = 1;
		//	memset(dp, 0, sizeof(dp));
		//	dp[0][k] = 1;
			for (int i = 0; i < n; ++i) {
		//		int now = i & 1;
		//		int nxt = now ^ 1;
		//		memset(dp[nxt], 0, sizeof(dp[nxt]));
				memset(dpto, 0, sizeof(dpto));
				for (int j = -k; j <= k; ++j) {
					if (i % 2 == 0) {
						for (int p = 0; p <= 2 * k; ++p) {
							if (j + p >= -k && j + p <= k)
						//	dp[nxt][j+k+p] += dp[now][j+k]*a[p];
							dpto[j + k + p] += dpfrom[j + k] * a[p];//= (dp[nxt][j + k + p] + dp[now][j + k] * a[p] % mod) % mod;
						}
					} else {
						for (int p = 0; p <= 2 * k; ++p) {
							if (j - p >= -k && j - p <=k)
						//	dp[nxt][j+k-p] += dp[now][j+k]*b[p];
							dpto[j + k - p] += dpfrom[j + k] * b[p]; //= (dp[nxt][j + k - p] + dp[now][j + k] * b[p] % mod) % mod;
						}
					}
				}
				for (int j = -k; j <= k; ++j) {
				//	dp[nxt][j+k] %= mod;
					dpfrom[j + k] = dpto[j+k] % mod;
				}
			}
		    ll ans = 0LL;
			for (int i = -k; i <= k; ++i) {
				ans += dpfrom[i+k];//dpfrom[i + k];
			}
			return ans%mod;
		}
};
