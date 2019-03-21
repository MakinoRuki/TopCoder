#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class QuadraticIdentity {
	public:
		vector<ll> ans;
		ll ext_gcd(ll a, ll b, ll& x, ll& y) {
			if (b == 0) {
				x = 1;
				y = 0;
				return a;
			}
			ll d = ext_gcd(b, a % b, y, x);
			y -= a / b * x;
			return d;
		}
		ll getans(ll a, ll b) {
			ll x, y;
			ext_gcd(a, b, x, y);
			while(x < 0) x += b;
			while(x > b) x -= b;
			return a * x;
		}
		vector<ll> getFixedPoints(ll m) {
			ans.clear();
			for (ll a = 1; a * a <= m; ++a) {
				if (m % a == 0 && __gcd(a, m / a) == 1) {
					ans.push_back(getans(a, m / a));
					if (a != m / a) {
						ans.push_back(getans(m / a, a));
					}
				}
			}
			sort(ans.begin(), ans.end());
			while(ans.size() > 500) {
				vector<ll> res;
				res.clear();
				for (int i = 0; i < ans.size(); i += 2) {
					res.push_back(ans[i]);
				}
				ans = res;
			}
			return ans;
		}
};
