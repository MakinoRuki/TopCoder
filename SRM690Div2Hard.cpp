#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define SZ 1002
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll dp[SZ][SZ];
class WolfHockeyTeamEasy {
	public:
		int count (int N, int K) {
			memset(dp, 0LL, sizeof(dp));
			dp[0][0] = 1LL;
			ll fac = 1LL;
			ll ans = 0LL;
			for (int i = 1; i <= N; ++i) {
				fac = fac * (ll)i % mod;
			}
		//	cout<<"1"<<endl;
			for (int i = 0; i <= N; ++i) {
				for (int j = 0; j <= N; ++j) {
					if (dp[i][j]) {
						dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod;
						if (i < j) {
							dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
						}
					}
				}
			}
		//	cout<<"2"<<endl;
			for (int i = 2 * N - 2; i >= N - 1; --i) {
		//		cout<<"i="<<i<<endl;
				int up = 2 * N - 1 - i;
		//		cout<<up<<endl;
				ans = (ans + (dp[N - up][N - 1] * fac % mod) * (2LL * min(up, 2 * N - 1 - K)) % mod) % mod;
			}
	//		cout<<"3"<<endl;
			return ans;
		}
};
