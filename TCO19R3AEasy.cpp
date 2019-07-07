#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class FamilySeatingArrangement {
	public:
		int n;
		ll dp[1002][1002];
		ll getpw(ll a, ll b) {
			ll res=1LL;
			while(b) {
				if (b&1) res= res*a%mod;
				a=a*a%mod;
				b/=2;
			}
			return res;
		}
		int countWays(vector<int> a, int k) {
			n  = a.size();
			memset(dp, 0, sizeof(dp));
			dp[0][0] = 1;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j <= k; ++j) {
					dp[i+1][j] = (dp[i+1][j]+dp[i][j]*j%mod)%mod;
					if (j+1<=k)
					dp[i+1][j+1] = (dp[i+1][j+1]+dp[i][j]*(k-j)%mod)%mod;
				}
			}
			ll ans = 0LL;
			for (int i = 1; i <= k; ++i) {
				ll res = dp[n][i];
				ll rem = k-i+1;
				for (int j = 0; j < a.size(); ++j) {
					res = res*getpw(rem, a[j])%mod;
				}
				ans = (ans+res)%mod;
			}
			return ans;
		}
};
