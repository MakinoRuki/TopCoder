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
#define M 200005
#define N 52
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
bool dp[2][N][M];
class KnapsackTweak {
public:
	int smallest(vector<int> a, int tar) {
		int n = (int)a.size();
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j <= n; ++j) {
				for (int k = 0; k < M; ++k) {
					dp[i][j][k] = false;
				}
			}
		}
		dp[0][0][0] = true;
		for (int i = 0; i < n; ++i) {
			int now = i&1;
			for (int j = 0; j <= n; ++j) {
				for (int k = 0; k < M; ++k) {
					dp[now^1][j][k] = false;
				}
			}
			for (int j = 0; j <=i; ++j) {
				for (int k = 0; k < M; ++k) {
					if (dp[now][j][k]) {
						dp[now^1][j][k] = true;
						if (k + a[i] < M) {
							dp[now^1][j+1][k+a[i]] = true;
						}
					}
				}
			}
		}
		int ans= inf;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < M; ++j) {
				if (dp[n&1][i][j]) {
					int det = abs(tar - j);
					ans = min(ans, (det+i-1)/i);
				}
			}
		}
		// for (int i = 0; i < 50; ++i) {
		// 	cout<<"1,";
		// }
		// cout<<endl;
		return ans;
	}
};
