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
#define N 505
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
//bool vis[N][N][N*N];
ll dp[N][N];
int nxt[N];
class CastleGuard {
public:
	vector<ll> walk(int n, int r, vector<int> cs) {
		memset(dp, 0LL, sizeof(dp));
		for (int i = 0; i < n; ++i) {
			int cur = i;
			//dp[i][i]++;
			for (int j = 0; j < cs.size(); ++j) {
				int x = abs(cs[j]);
				int q = x/n;
				int r2 = x%n;
				for (int k = 0; k < n; ++k) {
					dp[i][k] += q;
				}
				if (cs[j] > 0) {
					for (int j = 0; j < r2; ++j) {
						cur = (cur+1) % n;
						dp[i][cur]++;
					}
				} else {
					for (int j = 0; j < r2; ++j) {
						cur= (cur-1+n)%n;
						dp[i][cur]++;
					}
				}
			}
			nxt[i] = cur;
		}
		int cur = 0;
		vector<ll> ans(n, 0);
		ans[0]++;
		//int dt = 0;
		vector<int> ids;
		ids.clear();
		while(true) {
			ids.push_back(cur);
			// for (int i = 0; i < n; ++i) {
			// 	ans[i] += dp[cur][i];
			// }
			cur = nxt[cur];
			int i;
			for (i = 0; i < ids.size(); ++i) {
				if (ids[i] == cur) {
					break;
				}
			}
			if (i < ids.size()) break;
		}
		int i;
		for (i = 0; i <ids.size(); ++i) {
			if (ids[i] == cur) {
				break;
			}
		}
		//int id = ids[i];
		if (r <= ids.size()) {
			for (int j = 0; j < r; ++j) {
				for (int k = 0; k < n; ++k) {
					ans[k] += dp[ids[j]][k];
				}
			}
			return ans;
		}
		for (int j = 0; j < i; ++j) {
			for (int k = 0; k < n; ++k) {
				ans[k] += dp[ids[j]][k];
			}
		}
		int len = (int)ids.size() - i;
		int q = (r - i) / len;
		int r2 = (r-i) % len;
		for (int j = i; j < ids.size(); ++j) {
			for (int k = 0; k < n; ++k) {
				ans[k] += dp[ids[j]][k]*(ll)q;
			}
		}
		for (int j = 0; j < r2; ++j) {
			for (int k = 0; k < n; ++k) {
				ans[k] += dp[ids[i+j]][k];
			}
		}
		return ans;
	}
};
