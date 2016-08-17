#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class LimitedMemorySeries2 {
	public:
		ll getPre (ll cur, ll a, ll b) {
			ll pre = (cur + (1LL << 50) - b) ^ a;
			pre &= ((1LL << 50) - 1LL);
			return pre;
		}
		ll getNxt (ll cur, ll a, ll b) {
			ll nxt = ((cur ^ a) + b) & ((1LL << 50) - 1LL);
			return nxt;
		}
		int getSum (int n, ll x0, ll a, ll b) {
			ll ans = 0LL;
			ll cur = x0;
			for (int i = 0; i < n; ++i) {
				int j;
				ll pre = cur, nxt = cur;
				for (j = 0; j <= n; ++j) {
					if (i - j < 0 || i + j >= n) break;
					if (j == 0) continue;
					pre = getPre(pre, a, b);
					nxt = getNxt(nxt, a, b);
					if (pre >= cur || nxt >= cur) break;
				}
				j--;
			//	cout<<i<<" "<<j<<endl;
				ans = (ans + j) % mod;
				cur = getNxt(cur, a, b);
			}
			return ans;
		}
};
