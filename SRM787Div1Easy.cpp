#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 500005
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
class AqaAsadiMinimizes {
	public:
		ll a[N];
		double getMin(vector<int> p, int b0, int x, int y, int n) {
			for (int i = 0; i < n; ++i) {
				if (i < p.size()) {
					a[i] = p[i];
				} else if (i == p.size()) {
					a[i] = b0;
				} else {
					a[i] = (a[i-1]*(ll)x+(ll)y) % mod;
				}
			}
		//	vector<pair<ll, ll>> q;
		//	q.clear();
		//	q.push_back(make_pair(abs(a[n-2]-a[n-1]), 1));
			vector<pair<ll, int>> rk;
			for (int i = 0; i < n; ++i) {
				rk.push_back(make_pair(a[i], i));
			}
			sort(rk.begin(), rk.end());
			double ans=0.0;
			for (int i = 1; i < rk.size(); ++i) {
				double x1 = rk[i-1].second;
				double y1 = rk[i-1].first;
				double x2 = rk[i].second;
				double y2 = rk[i].first;
				double res = abs(y1-y2)/abs(x1-x2);
				if (i==1) ans =res;
				else if (res<ans) ans = res;
			}
			return ans;
		}
};
