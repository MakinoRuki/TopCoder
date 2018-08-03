#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#define N 102
#define M 10005
#define inf 1000000000
#define pli pair<ll, int>
#define mp make_pair
using namespace std;
typedef long long ll;
class Alchemy {
	public:
		int n;
		bool dp[N][M];
		ll e[M], dis[M];
		string leadToGold(vector<int> lo, vector<int> go, ll goal) {
			n = lo.size();
			vector<int> pg;
			pg.clear();
			memset(dp, false, sizeof(dp));
			for (int i = 0; i < n; ++i) {
				if (lo[i] == 0) {
					if (go[i] == goal) return "YES";
					pg.push_back(go[i]);
				} else {
					dp[lo[i] - 1][go[i]] = true;
				}
			}
			for (int i = N - 1; i > 0; --i) {
				for (int j = M - 1; j >= 0; --j) {
					for (int k = 0; k < pg.size(); ++k) {
						dp[i - 1][j + pg[k]] |= dp[i][j];
					}
				}
			}
			vector<int> a;
			a.clear();
			for (int i = 1; i < M; ++i) {
				if (dp[0][i]) {
					a.push_back(i);
				}
			}
			if (a.empty()) return "NO";
			int mod = a[0];
			a.erase(a.begin());
			memset(e, -1, sizeof(e));
			for (int i = 0; i < pg.size(); ++i) {
				if (goal >= pg[i]) {
					int r = (goal - pg[i]) % mod;
					e[r] = max(e[r], goal - pg[i]);
				}
			}
			int g = a[0];
			for (int i = 1; i < a.size(); ++i) {
				g = __gcd(g, a[i]);
			}
			bool ok = false;
			for (int i = 0; i <= mod; i += g) {
				if (e[i] >= 0) ok = true;
			}
			if (!ok) return "NO";
			set<pli> q;
			q.clear();
			for (int i = 1; i < M; ++i) {
				dis[i] = inf;
			}
			dis[0] = 0;
			if (e[0] >= dis[0]) return "YES";
			q.insert(mp(dis[0], 0));
			while(!q.empty()) {
				pli cur = *q.begin();
				q.erase(cur);
				ll d = cur.first;
				int idx = cur.second;
				if (d > goal) return "NO";
				for (int i = 0; i < a.size(); ++i) {
					int nxt = (idx + a[i]) % mod;
					if (dis[nxt] > dis[idx] + a[i]) {
						q.erase(mp(dis[nxt], nxt));
						dis[nxt] = dis[idx] + a[i];
						if (dis[nxt] <= e[nxt]) return "YES";
						q.insert(mp(dis[nxt], nxt));
					}
				}
			}
			return "NO";
		}
};
