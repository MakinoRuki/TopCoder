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
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
ll dmg[N];
ll dp[N];
vector<vector<int>> ss;
class BalancedAirplane {
public:
	vector<ll> a;
	
	//ss.clear();
	ll count(int c, int r, vector<int> pre) {
		a.clear();
		ss.clear();
		for (int i = 0; i < pre.size(); ++i) {
			a.push_back(pre[i]);
		}
		ll st = pre.back();
		for (int i = (int)pre.size(); i < r; ++i) {
			st = (st * 1103515245LL + 12345LL) % (1LL<<31);
			a.push_back(st >> (31-c));
		}
		ss.push_back({});
		for (int j = 0; j < c; ++j) {
			ss[0].push_back(0);
		}
		map<vector<int>, int> cnt;
		cnt.clear();
		ll ans = 0LL;
		for (int i = 0; i <= r; ++i) {
			if (i == 0) {
				vector<int> v(c-1, 0);
				cnt[v]++;
			} else {
				vector<int> v;
				ss.push_back({});
				for (int j = 0; j < c; ++j) {
					ss[i].push_back(ss[i-1][j]);
					if ((1<<j)&a[i-1]) {
						ss[i][j]++;
					}
				}
				for (int j = 1; j < c; ++j) {
					v.push_back(ss[i][j]-ss[i][j-1]);
				}
				ans += cnt[v];
				cnt[v]++;
			}
		}
		return ans;
	}
};
