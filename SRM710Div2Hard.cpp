#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 302
#define mp make_pair
#define inf 1LL<<60
typedef long long ll;
using namespace std;
class MinMaxMax {
	public:
		int n, m;
		vector<pair<ll, int> > rank;
		ll minw[N][N];
		ll mind[N][N];
		ll findMin (vector<int> a, vector<int> b, vector<int> w, vector<int> v) {
			m = a.size();
			n = v.size();
			rank.clear();
			for (int i = 0; i < n; ++i) {
				rank.push_back(mp((ll)v[i], i));
			}
			sort(rank.begin(), rank.end());
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					mind[i][j] = (i == j ? 0 : inf);
					minw[i][j] = (i == j ? 0 : inf);
				}
			}
			for (int i = 0; i < m; ++i) {
				minw[a[i]][b[i]] = w[i];
				minw[b[i]][a[i]] = w[i];
			}
			for (int k = 0; k < n; ++k) {
				int kp = rank[k].second;
				ll kv = rank[k].first;
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < n; ++j) {
						minw[i][j] = min(minw[i][j], max(minw[i][kp], minw[kp][j]));
						if (minw[i][j] < inf)
						mind[i][j] = min(mind[i][j], minw[i][j] * max(max((ll)v[i], (ll)v[j]), kv));
					}
				}
			}
			ll ans = 0;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					ans += mind[i][j];
				}
			}
			return ans / 2;
		}
};
