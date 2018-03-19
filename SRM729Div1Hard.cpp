#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 102
using namespace std;
typedef long long ll;
ll inf = 1LL<<60;
class XorAndLIS {
	public:
		int n;
		ll dp[N][N];
		vector<ll> x;
		void getbase(int m) {
			if (m <= 0) return;
			sort(x.begin(), x.begin() + m);
			int i;
			for (i = 60; i >= 0; --i) {
				if ((1LL<<i) & x[m - 1]) break;
			}
			for (int j = 0; j < m - 1; ++j) {
				if ((1LL<<i) & x[j]) x[j] ^= x[m - 1];
			}
			getbase(m - 1);
		}
		ll getnext(ll a, ll b, int m) {
			ll l, r;
			if (a <= b) l = -1, r = b;
			else l = b, r = inf;
			for (int i = m; i >= 0; --i) {
				ll nl = l, nr = r;
				if ((nl ^ x[i]) >= a) r = min(r, nl ^ x[i]);
				if ((nl ^ x[i]) < a) l = max(l, nl ^ x[i]);
				if ((nr ^ x[i]) >= a) r = min(r, nr ^ x[i]);
				if ((nr ^ x[i]) < a) l = max(l, nr ^ x[i]);
			}
			return r;
		}
		int maximalLength(vector<ll> xx) {
			x = xx;
			n = x.size();
			for (int i = 0; i <= n; ++i) {
				for (int j = 0; j <= n; ++j) {
					dp[i][j] = inf;
				}	
			}
			dp[0][0] = -1;
			for (int i = 1; i <= n; ++i) {
				getbase(i - 1);
				for (int j = 0; j <= i; ++j) {
					dp[i][j] = dp[i - 1][j];
					if (j > 0) dp[i][j] = min(dp[i][j], getnext(dp[i - 1][j - 1] + 1, x[i - 1], i - 2));
				}
			}
			for (int i = n; i >= 1; --i) {
				if (dp[n][i] < inf) return i;
			}
			return 0;
		}
};
