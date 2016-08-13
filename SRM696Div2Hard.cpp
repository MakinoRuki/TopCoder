#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 21
using namespace std;
class Clicountingd2 {
	public:
		int n, m;
		int ans;
		int mark[N][N];
		int count (vector<string> g) {
			n = g.size();
			m = 0;
			for (int i = 0; i < n; ++i) {
				for (int j = i + 1; j < n; ++j) {
					if (g[i][j] == '?') {
						mark[i][j] = mark[j][i] = m;
						m++;
					}
				}
			}
			int maxq[(1<<m)];
			memset(maxq, 0, sizeof(maxq));
			for (int s = 0; s < (1<<n); ++s) {
				bool ok = true;
				int t = 0;
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < n; ++j) {
						if (i == j) continue;
						if (((1<<i) & s) && ((1<<j) & s)) {
							if (g[i][j] == '0') ok = false;
							if (g[i][j] == '?') t |= (1<<mark[i][j]);
						}
					}	
				}
				if (!ok) continue;
				maxq[t] = max(maxq[t], __builtin_popcount(s));
			}
		//	cout<<maxq[0]<<" "<<maxq[1]<<endl;
			for (int s = 0; s < (1<<m); ++s) {
				for (int i = 0; i < m; ++i) {
					if ((1<<i) & s) continue;
					maxq[s | (1<<i)] = max(maxq[s | (1<<i)], maxq[s]);
				}
			}
			int ans = 0;
			for (int i = 0; i < (1<<m); ++i) {
				ans += maxq[i];
			}
			return ans;
		}
};
