#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <multiset>
using namespace std;
typedef long long ll;
class SchedulingWoes {
public:
	int study(int n, int seed, vector<int> dpre, int maxd, vector<int> tpre, int fact) {
		vector<pair<int, int>> rk;
		vector<ll> rd(n+1, 0);
		vector<ll> ds(n+1, 0);
		vector<ll> ts(n+1, 0);
		rd[0] = seed;
		ll maxt  = 0;
		for (int i = 1; i < 2*n; ++i) {
			rd[i] = (rd[i-1]*1103515245LL+12345) % (1LL<<31);
		}
		for (int i = 0; i < dpre.size(); ++i) {
			ds[i] = dpre[i];
			ts[i] = tpre[i];
		}
		for (int i = dpre.size(); i < n; ++i) {
			ds[i] = 1+(rd[2*i]%maxd);
			maxt = max(1, ds[i]/fact);
			rs[i] = 1+(rd[2*i+1] % maxt);
		}
		for (int i = 0; i < n; ++i) {
			rk.push_back(make_pair(ds[i], ts[i]));
		}
		sort(rk.begin(), rk.end());
		int tot=0;
		multiset<int> passed;
		passed.clear();
		for (int i = 0; i < n; ++i) {
			int cd = rk[i].first;
			int ct = rk[i].second;
			if (cd - tot >= ct) {
				tot += ct;
				passed.insert(ct);
			} else {
				if (passed.size() && *passed.rbegin() > ct) {
					tot -= *passed.rbegin();
					passed.erase(passed.find(*passed.rbegin()));
					tot += ct;
					passed.inser(ct);
				}
			}
		}
		return passed.size();
	}
};
