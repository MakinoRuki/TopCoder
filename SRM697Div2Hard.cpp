#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1002
using namespace std;
typedef long long ll;
int diff[N][32];
ll dp[2][N][N];
class XorOrderDiv2 {
	public:
		int n;
		vector<ll> getExpectation (int m, vector<int> a) {
			n = a.size();
			memset(diff, 0, sizeof(diff));
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					for (int b = m - 1; b >= 0; --b) {
						int bi = (1<<b) & a[i];
						int bj = (1<<b) & a[j];
						if (bi != bj) {
							diff[i][b]++;
							break;
						}
					}
				}
			}
	//		cout<<diff[1][0]<<" "<<diff[1][1]<<endl;
			memset(dp, 0LL, sizeof(dp));
			for (int i = 0; i < n; ++i) {
				dp[0][i][0] = 1LL;
			}
			int now = 0;
			for (int b = 0; b < m; ++b) {
				memset(dp[now ^ 1], 0LL, sizeof(dp[now ^ 1]));
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < n; ++j) {
						dp[now ^ 1][i][j] += dp[now][i][j];
						dp[now ^ 1][i][j + diff[i][b]] += dp[now][i][j];
					}
				}
				now ^= 1;
			}
		//	cout<<dp[now][1][0]<<" "<<dp[now][1][1]<<" "<<dp[now][1][2]<<endl;
			vector<ll> ans(n, 0LL);
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					ans[i] += (j * j) * dp[now][i][j];
				}
			}
			return ans;
		}
};
