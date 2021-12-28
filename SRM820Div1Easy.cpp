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
#define M 72
#define N 205
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
int dp[N][7][7][7];
class SelectFromArrays {
public:
	int maxSum(vector<int> a, vector<int> b, vector<int> c, int na, int nb, int nc) {
		memset(dp, -1, sizeof(dp));
		dp[0][0][0][0] = 0;
		int n = (int)a.size();
		for (int i = 0; i < n; ++i) {
			for (int n1 = 0; n1 <= na; ++n1) {
				for (int n2 = 0; n2 <= nb; ++n2) {
					for (int n3 = 0; n3 <= nc; ++n3) {
						if (dp[i][n1][n2][n3] >= 0) {
							if (n1+1<=na) {
								dp[i+1][n1+1][n2][n3] = max(dp[i+1][n1+1][n2][n3], dp[i][n1][n2][n3] + a[i]);
							}
							if (n2+1<=nb) {
								dp[i+1][n1][n2+1][n3] = max(dp[i+1][n1][n2+1][n3], dp[i][n1][n2][n3] + b[i]);
							}
							if (n3+1<=nc) {
								dp[i+1][n1][n2][n3+1] = max(dp[i+1][n1][n2][n3+1], dp[i][n1][n2][n3] + c[i]);
							}
							dp[i+1][n1][n2][n3] = max(dp[i+1][n1][n2][n3], dp[i][n1][n2][n3]);
						}
					}
				}
			}
		}
		return dp[n][na][nb][nc];
	}
};
