// 补集思想。总数减去凸包不相交的方案数。
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 102
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class IntersectingConvexHull {
	public:
		int n;
		ll comb[N][N];
		ll ans, tot;
		bool check (vector<int> & x, vector<int> & y, int a, int b, int c) {
			ll ax = x[a] - x[b];
			ll ay = y[a] - y[b];
			ll bx = x[c] - x[b];
			ll by = y[c] - y[b];
			return ax * by - bx * ay > 0;
		}
		int count (vector<int> x, vector<int> y) {
			n = x.size();
			tot = 0LL;
			ans = 0LL;
			for (int i = 0; i <= n; ++i) {
				comb[i][0] = 1LL;
				for (int j = 1; j <= i; ++j) {
					comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
				}
			}
			for (int i = 3; i <= n; ++i) {
				for (int j = 3; i + j <= n; ++j) {
					tot = (tot + comb[n][i] * comb[n - i][j] % mod) % mod;
				}
			}
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (i == j) continue;
					int cntl = 0, cntr = 0;
					for (int k = 0; k < n; ++k) {
						if (k == i || k == j) continue;
						if (check(x, y, i, j, k)) cntr++;
						else cntl++;
					}
			//		if (i == 0 && j == 3) cout<<cntl<<" "<<cntr<<endl;
					ll totl = 0, totr = 0;
					for (int k = 2; k <= cntl; ++k) {
						totl = (totl + comb[cntl][k]) % mod;
					}
					for (int k = 2; k <= cntr; ++k) {
						totr = (totr + comb[cntr][k]) % mod;
					}
				//	if (i == 0 && j == 3) cout<<totl<<" "<<totr<<endl;
					ans = (ans + totl * totr % mod) % mod;
				}
			}
			return (tot - ans + mod) % mod;
		}
};
