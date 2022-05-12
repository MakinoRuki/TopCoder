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
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
class QuestionOrder {
public:
	ll getpw(ll x, ll y) {
		ll res=1LL;
		while(y) {
			if (y&1) res=res*x%mod;
			x=x*x%mod;
			y/=2;
		}
		return res;
	}
	int maxExpProfit(vector<int> a, vector<int> p) {
		int n = (int)a.size();
		vector<pair<int,int>> ap;
		ap.clear();
		for (int i = 0; i < n; ++i) {
			ap.push_back(make_pair(a[i], p[i]));
		}
		sort(ap.begin(), ap.end(), [](const pair<int,int>& x, const pair<int,int>& y) {
			return (100-x.second)*y.second*y.first > (100-y.second)*x.second*x.first;
		});
		ll pw0 = getpw(100, mod-2);
		ll ans = 0LL;
		for (int i = 0; i < n; ++i) {
			ans = (ans + ap[i].first) % mod * ap[i].second % mod;
			ans = ans * pw0 % mod;
		}
		ans = ans * getpw(100, n) % mod;
		return ans;
	}
};
