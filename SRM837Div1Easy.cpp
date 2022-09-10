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
class StairsFromBlocks {
public:
	ll build(vector<int> w, vector<int> h) {
		int n = (int)w.size();
		vector<pair<ll,ll>> rk;
		rk.clear();
		for (int i = 0; i < n; ++i) {
			rk.push_back(make_pair(h[i], w[i]));
		}
		sort(rk.begin(), rk.end());
		ll tot = 0LL;
		ll cur = 0LL;
		for (int i = 0; i < rk.size(); ++i) {
			cur = max(cur+1, rk[i].first);
			cur += rk[i].second-1;
		}
		tot = cur * (cur+1)/2;
		for (int i = 0; i < rk.size(); ++i) {
			tot -= rk[i].first * rk[i].second;
		}
		return tot;
	}
};
