#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 2502
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class PermutationCounts {
	public:
		ll value[N];
		ll fac[N * 450];
		ll rev[N * 450];
		ll getRev (ll n) {
			ll res = 1LL;
			ll pw = mod - 2LL;
			while (pw) {
				if (pw & 1) res = res * n % mod;
				n = n * n % mod;
				pw /= 2;
			}
			return res;
		}
		ll getComb (int n, int m) {
			ll res = fac[n] * rev[m] % mod * rev[n - m] % mod;
			return res;
		}
		int countPermutations (int n, vector<int> pos) {
			sort(pos.begin(), pos.end());
			reverse(pos.begin(), pos.end());
			pos.push_back(0);
			reverse(pos.begin(), pos.end());
			pos.push_back(n);
			fac[0] = 1LL;
			rev[0] = getRev(fac[0]);
			for (int i = 1; i <= n; ++i) {
				fac[i] = fac[i - 1] * (ll)i % mod;
				rev[i] = getRev(fac[i]);
			}
			memset(value, 0LL, sizeof(value));
			value[0] = 1LL;
			for (int i = 1; i < pos.size(); ++i) {
				for (int j = 0; j < i; ++j) {
					ll comb = getComb(pos[i], pos[j]);
					value[i] = (value[i] - value[j] * comb % mod + mod) % mod;
				}
				//cout<<i<<" "<<value[i]<<endl;
			}
			if (pos.size() % 2 == 0) {
				return (-value[pos.size() - 1] + mod) % mod;
			}
			return value[pos.size() - 1];
		}
};
