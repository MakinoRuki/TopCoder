#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#define N 52
#define M 20005
#define mp make_pair
using namespace std;
typedef long long ll;
ll dp[M][N];
class LongLongTripDiv1 {
	public:
		int m;
		string isAble(int n, vector<int> a, vector<int> b, vector<int> d, ll t) {
			m = a.size();
			int d0 = 10001;
			for (int i = 0; i < m; ++i) {
				if (a[i] == 0 || b[i] == 0) d0 = min(d0, d[i]);
			}
			if (d0 > 10000) {
				return "Impossible";
			}
			d0 *= 2;
			for (int i = 0; i <= d0; ++i) {
				for (int j = 0; j < n; ++j) {
					dp[i][j] = 1000000000000000005LL;
				}
			}
			dp[0][0] = 0LL;
			using pii = pair<int, int>;
			set<pair<ll, pii> > Q;
			Q.clear();
			Q.insert(mp(0LL, mp(0, 0)));
			while(!Q.empty()) {
				pii top = Q.begin()->second;
				int dr = top.first;
				int u = top.second;				
				ll dv = dp[dr][u];
				Q.erase({dv, top});
				for (int i = 0; i < m; ++i) {
					int v = -1;
					if (a[i] == u) {
						v = b[i];
					} else if (b[i] == u) {
						v = a[i];
					}
					if (v != -1) {
						int ndr = (dr + d[i]) % d0;
						if (dp[ndr][v] > dp[dr][u] + (ll)d[i]) {
							Q.erase({dp[ndr][v], mp(ndr, v)});
							dp[ndr][v] = dp[dr][u] + (ll)d[i];
							Q.insert({dp[ndr][v], mp(ndr, v)});
						}
					}
				}
			}
			return dp[t % d0][n - 1] <= t ? "Possible" : "Impossible"; 
		}
};
