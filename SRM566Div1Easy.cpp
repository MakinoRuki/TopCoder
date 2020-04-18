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
#define N 52
using namespace std;
typedef long long ll;
class PenguinSledding {
public:
	int deg[N];
	bool mt[N][N];
	ll countDesigns(int np, vector <int> c1, vector <int> c2) {
		memset(deg, 0, sizeof(deg));
		memset(mt, false, sizeof(mt));
		for (int i = 0; i < c1.size(); ++i) {
			int u = c1[i];
			int v = c2[i];
			mt[u][v] = mt[v][u] = true;
			deg[u]++;
			deg[v]++;
		}
		ll ans = 0LL;
		for (int i = 1; i <= np; ++i) {
			if (deg[i]) {
				ans += (1LL<<deg[i])-1;
			}
		}
		for (int i = 1; i <= np; ++i) {
			for (int j = i+1; j <= np; ++j) {
				for (int k = j+1; k <= np; ++k) {
					if (mt[i][j] && mt[j][k] && mt[i][k]) ans++;
				}
			}
		}
		ans -= (int)c1.size();
		ans++;
		return ans;
	}
};
