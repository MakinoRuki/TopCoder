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
#define N 2000
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
//bool vis[N][N][N*N];
int idx[2][N];
class SortTwoArrays {
public:
	vector<int> twoSorts(int n, vector<int> a, vector<int> b) {
		vector<pair<int,int>> rk;
		rk.clear();
		for (int i = 0; i < n; ++i) {
			rk.push_back(make_pair(a[i], i));
		}
		sort(rk.begin(), rk.end());
		for (int i = 0; i < n; ++i) {
			idx[0][rk[i].second] = i;
		}
		rk.clear();
		for (int i = 0; i < n; ++i) {
			rk.push_back(make_pair(b[i], i));
		}
		sort(rk.begin(), rk.end());
		for (int i = 0; i < n; ++i) {
			idx[1][rk[i].second] = i;
		}
		bool vis[N];
		memset(vis, false, sizeof(vis));
		vector<int> ans;
		ans.clear();
		for (int i = 0; i < n; ++i) {
			if (idx[0][i] != i && !vis[i]) {
				int cur = i;
				ans.push_back(i);
				ans.push_back(0);
				while(true) {
					vis[cur] = true;
					ans.push_back(idx[0][cur]);
					ans.push_back(0);
					cur = idx[0][cur];
					if (cur == i) break;
				}
			}
		}
		memset(vis, false, sizeof(vis));
		for (int i = 0; i < n; ++i) {
			if (idx[1][i] != i && !vis[i]) {
				int cur = i;
				ans.push_back(0);
				ans.push_back(i);
				while(true) {
					vis[cur] = true;
					ans.push_back(0);
					ans.push_back(idx[1][cur]);
					cur = idx[1][cur];
					if (cur == i) break;
				}
			}
		}
		return ans;
	}
};
