//蚂蚁系列。POJ1852Ants,UVA10881Piotr'sAnts,SRM674Div1Med.
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#define N 200002
#define mp make_pair
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
vector<pair<ll, int> > ants;
int idx[N], dir[N];
int kid[N];
ll tm[N];
class FindingKids {
	public:
		int getCount (vector<ll>& ant, ll t, ll x) {
			int l = 0, r = ant.size();
			while (l < r) {
				int mid = (l + r) / 2;
				if (ant[mid] + t + 3LL * mod <= x) l = mid + 1;
				else r = mid;
			}
			return r;
		}
		ll getSum (int n, int q, int A, int B, int C) {
			ll tmA = A, tmB = B, tmC = C;
			set<ll> pos;
			pos.clear();
			vector<ll> toLeft, toRight;
			toLeft.clear();
			toRight.clear();
			for (int i = 0; i < n; ++i) {
				tmA = (tmA * tmB + tmC) % mod;
				ll p = tmA % (mod - n + i + 1);
				if (pos.find(p) != pos.end()) {
					p = mod - n + i;
				}
				pos.insert(p);
				ants.push_back(mp(p, i));
				dir[i] = !(p & 1);
				if (dir[i]) toRight.push_back(p);
				else toLeft.push_back(p);
			}
			for (int i = 0; i < q; ++i) {
				tmA = (tmA * tmB + tmC) % mod;
				kid[i] = tmA % n;
				tmA = (tmA * tmB + tmC) % mod;
				tm[i] = tmA;
			}
			sort(ants.begin(), ants.end());
			for (int i = 0; i < n; ++i) {
				idx[ants[i].second] = i;
			}
			sort(toLeft.begin(), toLeft.end());
			sort(toRight.begin(), toRight.end());
			ll ans = 0LL;
			for (int i = 0; i < q; ++i) {
				int rank = idx[kid[i]];
				ll l = 0LL, r = 6LL * mod;
				if (i <= 20) cout<<i<<endl;
				while (l < r) {
					ll mid = (l + r) / 2;
					if (i <= 20) cout<<mid<<endl;
					int cnt = getCount(toLeft, -tm[i], mid) + getCount(toRight, tm[i], mid);
					if (cnt >= rank + 1) r = mid;
					else l = mid + 1;
				}
			//	if (i <= 20) cout<<r<<endl;
				ans += abs(r - 3LL * mod);
			}
			return ans;
		}
};
