#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1000010
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class CycleColoring {
	public:
		ll dp[N][2];
		int n;
		ll getpw(ll x, ll m) {
			x %= mod;
			ll res = 1LL;
			while(m) {
				if (m & 1) res = res * x % mod;
				x = x * x % mod;
				m /= 2;
			}
			return res;
		}
		int countColorings(vector <int> vertexCount, vector <int> fromVertex, vector <int> toVertex, int k) {
			memset(dp, 0LL, sizeof(dp));
			n = vertexCount.size();
			dp[1][1] = k;
			dp[1][0] = 0;
			for (int i = 2; i <= 1000001; ++i) {
				dp[i][1] = dp[i - 1][0];
				dp[i][0] = (dp[i - 1][1] * (ll)(k - 1) % mod + dp[i - 1][0] * (ll)(k - 2) % mod) % mod;
			}
		//	cout<<dp[vertexCount[0]][0]<<endl;
		//	if (n == 1 && toVertex[0] == fromVertex[0]) return dp[vertexCount[0]][0];
			ll same = k;
			ll diff = 0;
			ll revk = getpw((ll)k, mod - 2);
			ll revk2 = getpw((ll)k * (ll)(k - 1), mod - 2);
			for (int i = 0; i < n; ++i) {
				int pre = (i - 1 + n) % n;
			//	int top = vertexCount[i] - abs(fromVertex[i] - toVertex[pre]) + 1;
			//	int bottom = abs(fromVertex[i] - toVertex[pre]) + 1;
				int top, bottom;
				if (toVertex[pre] <= fromVertex[i]) {
					top = fromVertex[i] - toVertex[pre] + 1;
					bottom = vertexCount[i] - top + 2;
				} else {
					bottom = toVertex[pre] - fromVertex[i] + 1;
					top = vertexCount[i] - bottom + 2;
				}
			//	cout<<top<<" "<<bottom<<endl;
				ll nextSame = same * (dp[top][1] * revk % mod) % mod * (dp[bottom][1] * revk % mod) % mod;
				nextSame = (nextSame + diff * (dp[top][0] * revk2 % mod) % mod * (dp[bottom][0] * revk2 % mod) % mod) % mod;
				
				ll nextDiff = same * (dp[top][0] * revk2 % mod) % mod * (dp[bottom][0] * revk2 % mod) % mod * (ll)(k - 1) % mod;
				nextDiff = (nextDiff + diff * (dp[top][1] * revk % mod) % mod * (dp[bottom][1] * revk % mod) % mod) % mod;
				nextDiff = (nextDiff + diff * (dp[top][0] * revk2 % mod) % mod * (dp[bottom][0] * revk2 % mod) % mod * (ll)(k - 2) % mod) % mod;
				
				same = nextSame;
				diff = nextDiff;
			}
			return same;
		}
};
