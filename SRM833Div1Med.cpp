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
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
//bool vis[N][N][N*N];
int dx[2] = {0, 1};
int dy[2] = {1, 0};
int l[N], r[N];
ll dp[N][2];
int l2[N], r2[N];
class FroggerAndNets {
public:
	int jump(string s, int c, int mnw, int sd) {
		ll st = sd;
		int n = (int)s.size();
		int mxw = n-1;
		for (int i = 0; i < c; ++i) {
			st = (st * 1103515245LL + 12345) % (1LL<<31);
			ll w = mnw + (st % (mxw - mnw + 1));
			st = (st * 1103515245LL + 12345) % (1LL<<31);
			l[i] = st % (n-w);
			r[i] = l[i] + w;
		}
		memset(dp, -1, sizeof(dp));
		vector<int> ids;
		ids.clear();
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'O') ids.push_back(i);
		}
		memset(l2, -1, sizeof(l2));
		memset(r2, -1, sizeof(r2));
		int id1 = lower_bound(ids.begin(), ids.end(), l[0]) - ids.begin();
		if (id1 < ids.size() && ids[id1] <= r[0]) {
			dp[0][0] = 0LL;
			l2[0] = ids[id1];
		}
		int id2 = upper_bound(ids.begin(), ids.end(), r[0]) - ids.begin();
		if (id2 > 0 && ids[id2-1] >= l[0]) {
			dp[0][1] = 0LL;
			r2[0] = ids[id2-1];
		}
		for (int i = 0; i < c-1; ++i) {
			for (int j = 0; j < 2; ++j) {
				if (dp[i][j] >= 0) {
					int id1 = lower_bound(ids.begin(), ids.end(), l[i+1]) - ids.begin();
					if (id1 < ids.size() && ids[id1] <= r[i+1]) {
						ll dt = 0LL;
						if (j == 0) dt = abs(l2[i] - ids[id1]);
						else dt = abs(r2[i] - ids[id1]);
						dp[i+1][0] = max(dp[i+1][0], dp[i][j] + dt);
						l2[i+1] = ids[id1];
					}
					int id2 = upper_bound(ids.begin(), ids.end(), r[i+1]) - ids.begin();
					if (id2 > 0 && ids[id2-1] >= l[i+1]) {
						ll dt = 0LL;
						if (j == 0) dt = abs(l2[i] - ids[id2-1]);
						else dt= abs(r2[i] - ids[id2-1]);
						dp[i+1][1] = max(dp[i+1][1], dp[i][j] + dt);
						r2[i+1] = ids[id2-1];
					}
				}
			}
		}
		return max(dp[c-1][0], dp[c-1][1]);
	}
};
