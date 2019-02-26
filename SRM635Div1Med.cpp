#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1002
using namespace std;
class StoryFromTCO {
	public:
		int n;
		bool taken[N];
		vector<int> pos;
		int minimumChanges(vector <int> ps, vector <int> co) {
			n = ps.size();
			memset(taken, false, sizeof(taken));
			pos.clear();
			for (int i = 0; i < n; ++i) {
				if (ps[i] > co[i]) {
					taken[i] = true;
					pos.push_back(i);
				}
			}
			while(true) {
				vector<int> a, b;
				for (int i = 0; i < pos.size(); ++i) {
					a.push_back(ps[pos[i]]);
					b.push_back(co[pos[i]]);
				}
				sort(a.begin(), a.end());
				sort(b.begin(), b.end());
				bool ok = true;
				for (int i = pos.size() - 1; i >= 0; --i) {
					if (a[i] > b[i]) {
						ok = false;
						int j;
						int minv = 1e9;
						int idx = -1;
						for (j = 0; j < n; ++j) {
							if (!taken[j] && co[j] >= a[i]) {
								if (idx < 0 || minv > ps[j]) {
									idx = j;
									minv = ps[j];
								}
							}
						}
						if (idx < 0) return -1;
						pos.push_back(idx);
						taken[idx] = true;
						break;
					}
				}
				if (ok) break;
			}
			return pos.size();
		}
};
