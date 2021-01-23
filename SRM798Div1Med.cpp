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
#include <random>
#define eps 1e-7
#define M 10002
#define N 1505
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
class ExpectedValue {
public:
	ll dp[N];
	ll comb[N][N];
	ll fac[N];
	ll getpw(ll a, ll b) {
		ll res=1LL;
		while(b) {
			if (b&1) res=res*a%mod;
			a=a*a%mod;
			b/=2;
		}
		return res;
	}
	int solve(int n) {
		memset(dp, 0, sizeof(dp));
		dp[0] = 1LL;
		dp[1] = 0LL;
		dp[2] = 1LL;
		for (int i = 3; i <= n; ++i) {
			dp[i] = dp[i-1];
			if (i-2>=0) dp[i] = (dp[i] + dp[i-2]) % mod;
			dp[i] = dp[i] * (ll)(i-1) % mod;
		}
		memset(fac, 0LL, sizeof(fac));
		fac[0] = 1LL;
		for (int i = 1; i <= n; ++i) {
			fac[i] = fac[i-1]*(ll)i % mod;
		}
		memset(comb, 0LL, sizeof(comb));
		for (int i = 0; i <= n; ++i) {
			comb[i][0] = 1LL;
			for (int j = 1; j <= i; ++j) {
				comb[i][j] = (comb[i-1][j-1]+comb[i-1][j]) % mod;
			}
		}
		ll ans=0LL;
		for (int i = 2; i <= n; ++i) {
			ll cur = comb[n][i] * fac[i-1] % mod * dp[n-i] % mod;
			ans = (ans + cur) % mod;
		}
		//cout<<ans<<endl;
		ll tmp = getpw(dp[n], mod-2);
		//cout<<ans<<" "<<tmp<<endl;
		ans = ans * tmp % mod;
		ans = (n - ans + mod) % mod;
		return (int)ans;
	}
};
