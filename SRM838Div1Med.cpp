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
#define M 200015
#define N 110
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
//bool vis[N][N][N*N];
class DistinctFaces {
public:
	int n;
	ll dp[N];
	ll getpw(ll x, ll y) {
		ll res=1LL;
		while(y) {
			if (y&1) res=res*x%mod;
			x=x*x%mod;
			y/=2;
		}
		return res;
	}
	int expectation(vector<int> cnt, vector<int> sz) {
		n = (int)cnt.size();
		int mx = 0;
		for (int i = 1; i <= n; ++i) {
			dp[i] = (sz[i-1]-1) % mod * getpw(sz[i-1], mod-2) % mod;
			dp[i] = getpw(dp[i], cnt[i-1]);
			mx = max(mx, sz[i-1]);
		}
		ll ans = 0LL;
		for (int i = 1; i <= mx; ++i) {
			ll tmp = 1LL;
			for (int j = 1; j <= n; ++j) {
				if (sz[j-1] >= i) {
					tmp = tmp * dp[j] % mod;
				}
			}
			ans = (ans + (1-tmp+mod)%mod) % mod;
		}
		return ans;
	}
};
