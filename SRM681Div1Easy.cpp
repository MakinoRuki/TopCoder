#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#define mp make_pair
#define pii pair<int, int>
using namespace std;
class FleetFunding {
	public:
		int n;
		int maxShips (int m, vector<int> k, vector<int> a, vector<int> b) {
			n = k.size();
			int l = 0, r = 1000000000;
			vector<pii> rank;
			rank.clear();
			for (int i = 0; i < n; ++i) {
				rank.push_back(mp(a[i], i));
			}
			sort(rank.begin(), rank.end());
			while (l < r) {
				int mid = (l + r + 1) / 2;
			//	cout<<"mid = "<<mid<<endl;
				set<pair<pii, int> > tmp;
				tmp.clear();
				int i;
				int j = 0;
				for (i = 1; i <= m; ++i) {
					int need = mid;
				//	if (mid == 3) cout<<i<<" "<<need<<endl;
					while (j < n && rank[j].first <= i) {
						int idx = rank[j].second;
						tmp.insert(mp(mp(b[idx], idx), k[idx]));
						j++; 
					}
					while (tmp.size() && need) {
						pair<pii, int> cur = *tmp.begin();
						int v = cur.first.first;
						int w = cur.second;
					//	if (mid == 3) cout<<u<<" "<<v<<" "<<w<<endl;
						if (v < i) tmp.erase(cur);
						else {
							int delta = min(w, need);
							need -= delta;
							tmp.erase(cur);
							if (w > delta) {
								cur.second -= delta;
								tmp.insert(cur);
							}
						}
					//	if (mid == 3) cout<<need<<endl;
					}
					if (need) break;
				}
				if (i <= m) {
					r = mid - 1;
				} else {
					l = mid;
				}
			}
			return r;
		}
};
