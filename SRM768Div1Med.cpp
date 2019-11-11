#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll dp[4002][4002];
class PBG {
	public:
		ll getrev(ll a) {
			ll b = mod-2;
			ll res=1LL;
			while(b) {
				if (b&1) res=res*a%mod;
				a = a*a%mod;
				b /= 2;
			}
			return res;
		}
		ll getev(int s, int w) {
			ll rev2[6006];
			for (int i = 0; i <= s + w + 1; ++i) {
				rev2[i] = getrev(i * (i-1)/2);
			}
			memset(dp, 0, sizeof(dp));
			for (int i = 0; i <= s; ++i) {
				for (int j = 0; j <= w; ++j) {
					if (i == 0) continue;
					if (j == 0) {
						dp[i][j] = (i + j + dp[i-1][j]) % mod;
						continue;
					}
					if (i >= 2) {
						dp[i][j] += (i*(i-1)/2) * (i + j + dp[i-1][j]) % mod;
					}
					if (j) {
						dp[i][j] += (i * j + j*(j-1)/2) * dp[i][j-1] % mod;
					}
					int cnt=i+j;
					dp[i][j] = dp[i][j] * rev2[cnt] % mod;
				}
			}
			return dp[s][w];
		}
		// G > P > B
		int findEV(int P, int B, int G) {
			ll GPV = getev(G+P, B);
			ll GV = getev(G, P+B);
			return (GPV-GV+mod) * getrev(P) % mod;
		}
};
