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
class Flagpole {
public:
	vector<ll> getv(vector<int>& v, int l, int r) {
		vector<ll> res;
		res.clear();
		int m = r-l;
		for (int i = 0; i < (1<<m); ++i) {
			ll sum=0LL;
			for (int j = l; j < r; ++j) {
				if ((1<<(j-l)) & i) {
					sum += v[j];
				}
			}
			res.push_back(sum);
		}
		return res;
	}
	ll build(vector<int> sgs, ll l0, ll h1) {
		int n = (int)sgs.size();
		vector<ll> v1 = getv(sgs, 0, (n+1)/2);
		vector<ll> v2 = getv(sgs, (n+1)/2, n);
		ll ans = 0LL;
		for (int i = 0; i < v1.size(); ++i) {
			if (v1[i] > h1) {
				break;
			}
			ll lb = l0-v1[i];
			ll rb = h1-v1[i];
			int id1 = upper_bound(v2.begin(), v2.end(), lb) - v2.begin();
			int id2 = upper_bound(v2.begin(), v2.end(), rb) - v2.begin() - 1;
			if (id1 <= id2) {
				ans += id2-id1+1;
			}
		}
		return ans;
	}
};
