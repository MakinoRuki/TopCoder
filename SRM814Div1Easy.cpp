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
class StepLeapSurviveTraps {
public:
	ll minDamage(int n, int j, int seed, int m) {
		dmg[0] = 0LL;
		ll st = seed;
		for (int i = 1; i <= n; ++i) {
			st = (st * 1103515245LL + 12345) % (1LL<<31);
			dmg[i] = 1 + (st % m);
		}
		deque<int> dq;
		dp[0] = 0LL;
		dq.push_back(0);
		for (int i = 1; i <= n; ++i) {
			while(!dq.empty() && i - dq.front() > j) {
				dq.pop_front();
			}
			dp[i] = dp[dq.front()] + dmg[i];
			while(!dq.empty() && dp[i] <= dp[dq.back()]) {
				dq.pop_back();
			}
			dq.push_back(i);
		}
		return dp[n];
	}
};
