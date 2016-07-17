#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#define N 100005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
map<int, vector<ll> > facs;
class GCDLCM2 {
	public:
		ll res[N];
		int tot;
		void prime (int num) {
			for (int i = 2; i * i <= num; ++i) {
				ll tmp = 1LL;
				while (num % i == 0) {
					tmp *= (ll)i;
					num /= i;
				}
				if (tmp > 1) facs[i].push_back(tmp);
			}
			if (num > 1) facs[num].push_back(num);
		}
		int getMaximalSum (vector<int> start, vector<int> d, vector<int> cnt) {
			tot = 0;
			for (int i = 0; i < start.size(); ++i) {
				for (int j = 0; j < cnt[i]; ++j) {
					tot++;
					prime(start[i] + j * d[i]);
				}
			}
			for (int i = 0; i < tot; ++i) {
				res[i] = 1LL;
			}
			for (map<int, vector<ll> > :: iterator itr = facs.begin(); itr != facs.end(); ++itr) {
				vector<ll> tmp = itr->second;
				sort(tmp.begin(), tmp.end());
				int delta = tot - tmp.size();
				for (int i = 0; i < tmp.size(); ++i) {
					res[delta + i] = (res[delta + i] * tmp[i]) % mod;
				}
			}
			ll ans = 0LL;
			for (int  i = 0; i < tot; ++i) {
				ans = (ans + res[i]) % mod;
			}
			return ans;
		}
};
