#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
class DivisibleSetDiv1 {
	public:
		int n;
		set<int> bs;
		ll getGCD (ll x, ll y) {
			return y == 0 ? x : getGCD(y, x % y);
		}
		ll getLCM (ll x, ll y) {
			return x * y / getGCD(x, y);
		}
		string isPossible (vector<int> b) {
			n = b.size();
			bs.clear();
			ll tot = 1LL;
			for (int i = 0; i < n; ++i) {
				tot = getLCM(tot, (ll)(b[i] + 1));
				bs.insert(b[i]);
			}
			ll sum = 0LL;
			for (int i = 0; i < n; ++i) {
				sum += tot / (ll)(b[i] + 1);
			}
	//		cout<<sum<<" "<<tot<<endl;
			if (sum > tot) {
				return "Impossible";
			}
			if (sum == tot) {
				if (bs.size() < n) return "Impossible";
			}
			return "Possible";
		}
};
