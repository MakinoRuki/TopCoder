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
#define N 3002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
class SuperSubset {
public:
	ll dp[N][M];
	int solve(vector<int> a, int y) {
		memset(dp, 0, sizeof(dp));
		int n = a.size();
		dp[0][0] = 1LL;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= y; ++j) {
				dp[i+1][j] = (dp[i+1][j] + dp[i][j]*2LL%mod) % mod;
				if (j+a[i] <= y) {
					dp[i+1][j+a[i]] = (dp[i+1][j+a[i]] + dp[i][j]) % mod;
				}
			}
		}
		return (int)dp[n][y];
	}
};
