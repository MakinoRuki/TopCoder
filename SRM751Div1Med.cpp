#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
ll mod = 998244353LL;
class WrongBase {
	public:
		ll getpow(ll a, ll b) {
			ll res = 1LL;
			while(b) {
				if (b & 1) res = res * a % mod;
				a = a * a % mod;
				b /= 2;
			}
			return res;
		}
		ll getroot(ll g, ll h) { // return g^x = h (mod m)
			map<int,int> M;
			ll cur = 1;
			int sq = sqrt(mod);
			for(int i = 0; i < sq; ++i) {
				M[cur] = i;
				cur = cur * g % mod;
			}
			ll step = cur;
			cur = 1;
			ll num = 0;
			while(true) {
				ll x = h * getpow(cur, mod - 2) % mod;
				if(M.count(x)) return num + M[x];
				cur = cur * step % mod;
				num += sq;
			}
		}
		int getSum(int g, int h, int a, int d, int n) {
			if (h == 0) return 0;
			ll ans = 0LL;
			ll cur = a;
			ll root = getroot(g, h);
			for (int i = 0; i < n; ++i) {
				ans = (ans + getpow(cur, root)) % mod;
				cur += d;
			}
			return ans;
		}
};
