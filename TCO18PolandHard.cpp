#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class SumCards {
	public:
		int n;
		ll ans = 0LL;
		ll pw[31];
		int cmp(string x, string y) {
			if (x + y < y + x) return -1;
			if (x + y > y + x) return 1;
			return 0;
		}
		ll getres(string x, int idx, vector<string>& a, vector<string>& b) {
			ll acc = 1LL;
			for (int i = 0; i < n; ++i) {
				if (i == idx) continue;
				ll sum = 0LL;
				int res = cmp(x, a[i]);
				if (res < 0 || (res == 0 && idx < i)) sum += pw[a[i].size()];
				else sum++;
				res = cmp(x, b[i]);
				if (res < 0 || (res == 0 && idx < i)) sum += pw[b[i].size()];
				else sum++;
				acc = acc * sum % mod;
				//cout<<idx<<" "<<i<<" "<<sum<<endl;
			}
			ll res = 0LL;
			for (int i = 0; i < x.size(); ++i) {
				res = (res * 10LL + x[i] - '0') % mod;
			}
			res = res * acc % mod;
			return res;
		}
		int findsum(vector<string> a, vector<string> b) {
			n = a.size();
			pw[0] = 1LL;
			for (int i = 1; i <= 30; ++i) {
				pw[i] = pw[i - 1] * 10LL % mod;
			}
			for (int i = 0; i < n; ++i) {
				ans = (ans + getres(a[i], i, a, b)) % mod;
				ans = (ans + getres(b[i], i, a, b)) % mod;
			}
			return ans;
		}
};
