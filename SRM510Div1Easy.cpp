#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <deque>
#include <map>
#define N 52
using namespace std;
typedef long long ll;
class TheAlmostLuckyNumbersDivOne {
	public:
		vector<int> ds;
		ll dp[17][2][2][2];
		ll dfs(int cur, int f0, int f1, int f2) {
			if (cur == ds.size()) return 1;
			if (dp[cur][f0][f1][f2] >= 0) return dp[cur][f0][f1][f2];
			dp[cur][f0][f1][f2] = 0;
			ll& res = dp[cur][f0][f1][f2];
			if (f2) {
				if (f1) {
					res += 2*dfs(cur+1, 1, f1, f2);
				} else {
					vector<int> xs = {4,7};
					for (int i = 0; i < 2; ++i) {
						if (xs[i] > ds[cur]) continue;
						res += dfs(cur+1, 1, f1 | (xs[i]<ds[cur]), f2);
					}
				}
			} else {
				for (int i = 0; i <= 9; ++i) {
					if (i == 0) {
						if (!f0) res += dfs(cur+1, f0, f1|(i<ds[cur]), f2);
						else {
							if (f2) continue;
							res += dfs(cur+1, f0, f1|(i<ds[cur]), 1);
						}
					} else {
						if (i==4 || i==7) {
							if (f1 || (i<=ds[cur])) {
								res += dfs(cur+1, 1, f1|(i<ds[cur]), f2);
							}
						} else {
							if ((f1 || (i<=ds[cur])) && !f2) {
								res += dfs(cur+1, 1, f1|(i<ds[cur]), 1);
							}
						}
					}
				}
			}
			return res;
		}
		ll solve(ll x) {
			if (x == 0) return 1;
			ds.clear();
			while(x) {
				ds.push_back(x%10);
				x/=10;
			}
			memset(dp, -1, sizeof(dp));
			reverse(ds.begin(), ds.end());
			return dfs(0, 0, 0, 0);
		}
		ll find(ll a, ll b) {
			// cout<<solve(b)<<" "<<solve(a-1)<<endl;
			return solve(b) - solve(a-1);
		}
};
