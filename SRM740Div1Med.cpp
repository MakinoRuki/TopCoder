/*#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 32
#define inf 1000000000
using namespace std;
class DieDesign {
	public:
		int n;
		int dp[N][N*N];
		int pre[N][N * N];
		vector<int> ans;
		vector<int> design(vector<int> pips) {
			n = pips.size();
			sort(pips.begin(), pips.end());
			ans.clear();
			int tot = 0;
			memset(pre, -1, sizeof(pre));
			for (int i = 0; i <= n; ++i) {
				if (i < n) tot += pips[i];
				for (int j = 0; j <= n * n; ++j) {
					dp[i][j] = inf;
				}
			}
			dp[0][0] = 0;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j <= i * n; ++j) {
					if (dp[i][j] < inf) {
						if (dp[i + 1][j] > dp[i][j]) {
							dp[i + 1][j] = dp[i][j];
							pre[i + 1][j] = 0;
						}
						for (int k = 1; k <= n;) {
							while(k < n && pips[k] == pips[k - 1]) k++;
							int det = pips[k - 1] + 1;
							if (dp[i + 1][j + k] > dp[i][j] + det && dp[i][j] + det <= tot) {
								dp[i + 1][j + k] = dp[i][j] + det;
								pre[i + 1][j + k] = k;
							}
							k++;
						}
					}
				}
			}
			int maxv = 0;
			for (int i = n * n; i >= 0; --i) {
				if (dp[n][i] <= tot) {
					maxv = i;
				//	cout<<"maxv="<<maxv<<endl;
					break;
				}
			}
			for (int i = n; i > 0; --i) {
				int k = pre[i][maxv];
			//	cout<<i<<" "<<maxv<<" "<<k<<endl;
				int det = (k == 0 ? 0 : pips[k - 1] + 1);
				tot -= det;
				ans.push_back(det);
				maxv -= k;
			}
			if (tot) {
				ans[0] += tot;
			}
			reverse(ans.begin(), ans.end());
			return ans;
		}
};*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define N 32
#define inf 1000000000
using namespace std;
class DieDesign {
	public:
		int n;
		int dp[N][N*N];
		vector<int> ans;
		vector<int> design(vector<int> pips) {
			sort(pips.begin(), pips.end());
			int tot = 0;
			ans.clear();
			n = pips.size();
			for (int i = 0; i < n; ++i) {
				tot += pips[i];
			}
			for (int i = 0; i <= n; ++i) {
				for (int j = 0; j <= n * n; ++j) {
					dp[i][j] = inf;
				}
			}
			dp[0][0] = 0;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j <= i * n; ++j) {
					if (dp[i][j] < inf) {
						dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
						for (int k = 1; k <= n;) {
							while(k < n && pips[k] == pips[k - 1]) k++;
							if (dp[i][j] + pips[k - 1] + 1 <= tot)
								dp[i + 1][j + k] = min(dp[i + 1][j + k], dp[i][j] + pips[k - 1] + 1);
							k++;
						}
					}
				}
			}
			int maxv = 0;
			for (int i = 0; i <= n * n; ++i) {
				if (dp[n][i] <= tot) maxv = max(maxv, i);
			}
		//	cout<<maxv<<endl;
			int sum = 0;
			for (int i = n; i >= 1; --i) {
				for (int j = 0; j <= n; ++j) {
					if (j == 0 && dp[i-1][maxv]==dp[i][maxv]) {
						ans.push_back(0);
						break;
					} else if (j == n && dp[i-1][maxv-j]==dp[i][maxv]-pips[j - 1]-1) {
						ans.push_back(pips[j-1]+1);
						sum += pips[j-1]+1;
						maxv -= j;
						break;
					} else {
						if (j > 0 && j < n && pips[j - 1] == pips[j]) continue;
						if (j > 0 && j < n && pips[j-1] != pips[j]) {
							if (dp[i-1][maxv-j]==dp[i][maxv]-pips[j-1] -1) {
								ans.push_back(pips[j-1]+1);
								sum += pips[j-1]+1;
								maxv -= j;
								break;
							}
						}
						continue;
					}
				}
			}
			int del = tot - sum;
			if (del > 0) ans[0] += del;
			reverse(ans.begin(), ans.end());
			return ans;
		}
};
