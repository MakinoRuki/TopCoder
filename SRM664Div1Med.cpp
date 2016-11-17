#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1000010
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class BearAttacks {
	public:
		vector<int> edges[N];
		ll dp[N];
		ll getpw(ll a, ll b) {
			ll res = 1LL;
			while (b) {
				if (b & 1) res = res * a % mod;
				a = a * a % mod;
				b /= 2;
			}
			return res;
		}
		int expectedValue (int n, int r0, int a, int b, int m, int low, int high) {
			ll r = r0;
			ll billion = 1000000000L;
			for (int i = 1; i < n; ++i) {
				r = ((ll)a * (ll)r + (ll)b) % (ll)m;
				ll minV = (ll)(i - 1) * (ll)low / billion;
				ll maxV = (ll)(i - 1) * (ll)high / billion;
				int j = (int)(minV + (r % (ll)(maxV - minV + 1)));
				edges[i].push_back(j);
				edges[j].push_back(i);
			}
		//	cout<<"ok here."<<endl;
			ll ans = 0LL;
			for (int i = n - 1; i >= 0; --i) {
				ll pb = getpw(i + 1, mod - 2);
				dp[i] = pb;
				ans = (ans + pb) % mod;
				for (int j = 0; j < edges[i].size(); ++j) {
					int v = edges[i][j];
					if (v > i) {
						ans = (ans + dp[i] * dp[v] * 2LL % mod) % mod;
						dp[i] = (dp[i] + dp[v] * pb % mod) % mod;
					}
				}
			}
			for (int i = 1; i <= n; ++i) {
				ans = (ans * (ll)i) % mod;
			}
			return ans;
		}
};
