#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class CatsOnTheLineDiv1 {
	public:
		int n;
		int getNumber(vector<int> pos, vector<int> cnt, int tm) {
			vector<pair<int, int> > pc;
			pc.clear();
			n = pos.size();
			for (int i = 0; i < n; ++i) {
				pc.push_back(make_pair(pos[i], cnt[i]));
			}
			sort(pc.begin(), pc.end());
			int ans = 0;
			ll pree = -1LL<<60;
			ll preg = -1LL<<60;
			for (int i = 0; i < n; ++i) {
				int p = pc[i].first;
				int c = pc[i].second;
				if (preg >= p - tm) continue;
				ll l = max(pree + 1LL, (ll)p - (ll)tm);
				ll r = p + tm;
				ll det = r - l + 1;
				if (det >= c) {
					pree = max(pree, l + (ll)c - 1LL);
				} else {
					preg = max(preg, r);
					ans++;
				}
			}
			return ans;
		}
};
