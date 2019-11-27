#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class AllEven {
	public:
		ll dp[19][2][1<<10][2][2];
		vector<int> ds;
		ll dfs(int cur, int can, int st, int zr, int cnt) {
			if (cur == ds.size()) {
				if (cnt && (st==0)) return 1;
				return 0;
			}
			if (dp[cur][can][st][zr][cnt] >= 0) return dp[cur][can][st][zr][cnt];
			dp[cur][can][st][zr][cnt] = 0;
			for (int i = 0; i <= 9; ++i) {
				int nst=st;
				int ncnt=cnt;
				if (i == 0) {
					if (zr) {
						nst ^= (1<<i);
						ncnt=1;
					}
					if (can || i < ds[cur]) dp[cur][can][st][zr][cnt] += dfs(cur+1, 1, nst, zr, ncnt);
					else dp[cur][can][st][zr][cnt] += dfs(cur+1, 0, nst, zr, ncnt);
				} else {
					if (!can && i > ds[cur]) continue;
					nst ^= (1<<i);
					ncnt=1;
					if (can || i < ds[cur]) dp[cur][can][st][zr][cnt] += dfs(cur+1, 1, nst, 1, ncnt);
					else dp[cur][can][st][zr][cnt] += dfs(cur+1, 0, nst, 1, ncnt);
				}
			}
			return dp[cur][can][st][zr][cnt];
		}
		ll solve(ll x) {
			ds.clear();
			ll y = x;
			while(y) {
				ds.push_back(y%10);
				y /= 10;
			}
			reverse(ds.begin(), ds.end());
			memset(dp, -1, sizeof(dp));
			return dfs(0, 0, 0, 0, 0);
		}
		ll countInRange(ll lo, ll hi) {
			if (lo == 0) return solve(hi);
			else return solve(hi)-solve(lo-1);
		} 
};
