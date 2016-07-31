#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
#define mp make_pair
using namespace std;
class ParenthesesDiv1Medium {
	public:
		int n, m;
		vector<pii> segs;
		bool hasFreeRoot(pii & seg, bool all) {
			return (seg.second - seg.first == n - 1 && !all);
		}
		int minSwaps (string s, vector<int> L, vector<int> R) {
			n = s.size();
			bool all = false;
			for (int i = 0; i < L.size(); ++i) {
				segs.push_back(mp(L[i], R[i]));
				if (L[i] == 0 && R[i] == n - 1) {
					all = true;
				}
			}
			segs.push_back(mp(0, n - 1));
			bool hasbreak = true;
			while (hasbreak) {
				hasbreak = false;
				vector<pii> rank;
				for (int i = 0; i < segs.size(); ++i) {
					rank.push_back(segs[i]);
				}
				sort(rank.begin(), rank.end());
				segs.clear();
				for (int i = 0; i < rank.size(); ++i) {
					if (i == 0) segs.push_back(rank[i]);
					else if (rank[i] != segs.back()) {
						segs.push_back(rank[i]);
					}
				}
				for (int i = 0; i < segs.size(); ++i) {
					for (int j = i + 1; j < segs.size(); ++j) {
						int l1 = segs[i].first;
						int r1 = segs[i].second;
						int l2 = segs[j].first;
						int r2 = segs[j].second;
						if (l1 < l2 && l2 <= r1 && r1 < r2) {
							hasbreak = true;
							segs[i].second = l2 - 1;
							segs[j].second = r1;
							segs.push_back(mp(r1 + 1, r2));
						}
					}
				}
			}
			m = segs.size();
			vector<vector<int> > edges(m);
			vector<pii> lenrank;
			lenrank.clear();
			for (int i = 0; i < m; ++i) {
				lenrank.push_back(mp(segs[i].second - segs[i].first + 1, i));
			}
			sort(lenrank.begin(), lenrank.end());
			int ans = 0;
			vector<int> reml(m, 0);
			vector<int> remr(m, 0);
			for (int i = 0; i < m; ++i) {
				int cur = lenrank[i].second;
				vector<bool> used(n, false);
				int l = 0, r = 0;
				for (int j = 0; j < edges[cur].size(); ++j) {
					int idx = edges[cur][j];
					for (int k = segs[idx].first; k <= segs[idx].second; ++k) {
						used[k] = true;
					}
					l += reml[idx];
					r += remr[idx];
				}
				int minV = 0, tot = 0;
				int freel = 0, freer = 0;
				for (int j = segs[cur].first; j <= segs[cur].second; ++j) {
					if (!used[j]) {
						if (s[j] == '(') {
							if (i == m - 1 && !all) freel++;
							else tot++;
						} else {
							if (i == m - 1 && !all) freer++;
							else tot--;
						}
						minV = min(minV, tot);
					}
				}
				if (abs(tot) & 1) return -1;
				if (tot < 0) {
					minV += abs(tot);
				}
				ans += (-minV + 1) / 2;
				if (i == m - 1 && !all) {
					if (l > r) {
						ans += r;
						l -= r;
						if (freer >= l) {
							ans += l;
						} else {
							return -1;
						}
					} else {
						ans += l;
						r -= l;
						if (freel >= r) {
							ans += r;
						} else {
							return -1;
						}
					}
				} else {
					if (tot > 0) {
						l += tot / 2;
					} else {
						r += (-tot) / 2;
					}
					reml[cur] = (l > r ? l - r : 0);
					remr[cur] = (l < r ? r - l : 0);
					if (edges[cur].size()) {
						ans += min(l, r);
					}
				}
				int j, par = 0;
				for (j = i + 1; j < m; ++j) {
					par = lenrank[j].second;
					if (segs[par].first <= segs[cur].first && segs[par].second >= segs[cur].second) {
						break;
					}
				}
				edges[par].push_back(cur);
			}
			if (all) {
				if (reml[lenrank[m - 1].second] || remr[lenrank[m - 1].second]) return -1;
			}
			return ans;
		}
};
