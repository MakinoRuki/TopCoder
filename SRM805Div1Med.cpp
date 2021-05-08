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
#define eps 1e-7
#define M 52
#define N 1002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
ll dp[2][N][11];
class SubmultiplesOfN {
public:
	int count(string b, int n) {
		memset(dp, 0LL, sizeof(dp));
		int m = b.size();
		//dp[0][0][0] = 1LL;
		for (int i = 0; i < m; ++i) {
			int now=i&1;
			for (int j = 0; j < n; ++j) {
				for (int d = 0; d <= 10; ++d) {
					dp[now^1][j][d] = 0LL;
				}
			}
			for (int j = 0; j < n; ++j) {
				for (int d2 = 0; d2 < 10; ++d2) {
					int d = b[i]-'0';
					int j2 = (j*10LL+d)%n;
					dp[now^1][j2][d] = (dp[now^1][j2][d] + dp[now][j][d2]) % mod;
					// ll tmp = dp[now][j][d];
					// dp[now^1][j2][d] = (dp[now^1][j2][d]+dp[now][j][0])%mod;
					// dp[now^1][j2][d] = (dp[now^1][j2][d]-tmp+mod)%mod;
					//tot = ((tot-dp[now][j][d]+mod)%mod+tot)%mod;
				//	dp[now^1][j2][d] = (dp[now^1][j2][d]+tot)%mod;
				//	if (i == 1 && j2 == 4) cout<<"x="<<j<<" "<<dp[now^1][j2][d]<<endl;
				}
				// dp[i+1][j] = (dp[i+1][j]+dp[i][j])%mod;
				// int j2 = (j*10LL+d)%n;
				// dp[i+1][j2] = (dp[i+1][j2]+dp[i][j])%mod;
			}
			int d = b[i]-'0';
			for (int j = 0; j < n; ++j) {
				for (int d2 = 0; d2 < 10; ++d2) {
					if (d != d2) {
						dp[now^1][j][d2] = (dp[now^1][j][d2] + dp[now][j][d2])%mod;
					}
				}
			}
			if (d != 0) dp[now^1][d%n][d] = (dp[now^1][d%n][d]+1)%mod;
			// for (int j = 0; j < n; ++j) {
			// 	for (int d = 1; d <= 10; ++d) {
			// 		dp[now^1][j][0] = (dp[now^1][j][0] + dp[now^1][j][d])%mod;
			// 	}
			// 	dp[now^1][0][0] = (dp[now^1][0][0] + 1)%mod;
			// }
			if (i+1==2) cout<<"v="<<dp[now^1][4][1]<<endl;
		}
		ll ans =0LL;
		for (int d = 0; d< 10; ++d) {
			ans = (ans + dp[m&1][0][d]) % mod;
		}
		return ans;
	}
};
