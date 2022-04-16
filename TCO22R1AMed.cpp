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
#define M 200005
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
double dp[12][200];
double dp2[10002][3];
class SingleOrDouble {
public:
	double probAlice(int n, int d, int a, int b) {
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= n*d; ++j) {
				dp[i][j] = 0.0;
			}
		}
		dp[0][0] = 1.0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= n * d; ++j) {
				if (dp[i][j]) {
					for (int j2 = 1; j2 <= d; ++j2) {
						if (j + j2 <= n*d) {
							dp[i+1][j+j2] = (dp[i+1][j+j2] + dp[i][j]/(double)d);
						}
					}
				}
			}
		}
		double pa = dp[n][a];
		double pb = dp[n][b];
		// P = pa + pb*pa + pb*pb*0 + pb*(1-pa-pb)*P + (1-pa-pb)*P
		double ans = (pa + pa * pb) / (pb * pb + pa + pa * pb);
		return ans;
	}
};
