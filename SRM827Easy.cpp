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
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
ll dp[10][40][40];
class ContestTraining {
public:
	vector<ll> practice(ll hd, ll ld, ll hp, ll lp, vector<ll> qs) {
		vector<ll> ans;
		ans.clear();
		for (int i = 0; i < qs.size(); ++i) {
			ll l = 1, r = 1000000000000000000LL;
			while(l < r) {
				ll mid = (l+r)/2;
				ll q = mid / (hd + ld);
				ll rr = mid % (hd + ld);
				if (q >= qs[i]) {
					r = mid;
					continue;
				}
				if (q >= (qs[i] + hd-1) /hd) {
					r = mid;
					continue;
				}
				if (q * hd >= (qs[i]+hp-1) / hp) {
					r = mid;
					continue;
				}
				if (q >= (qs[i] + ld-1) /ld) {
					r = mid;
					continue;
				}
				if (q * ld >= (qs[i]+lp-1) / lp) {
					r = mid;
					continue;
				}
				ll tot = q * (hp * hd + lp * ld);
				if (tot >= qs[i]) {
					r = mid;
					continue;
				}
				if (min(rr, hd) >= (qs[i] + hp-1)/hp) {
					r = mid;
					continue;
				}
				tot += min(rr, hd) * hp;
				if (tot >= qs[i]) {
					r = mid;
					continue;
				}
				if (max(0LL, rr-hd) >= (qs[i] + lp-1)/lp) {
					r = mid;
					continue;
				}
				tot += max(0LL, rr - hd) * lp;
				if (tot >= qs[i]) {
					r = mid;
				} else {
					l = mid + 1;
				}
			}
			ans.push_back(r);
		}
		return ans;
	}
};
