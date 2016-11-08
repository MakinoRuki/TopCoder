#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class LineMSTDiv2 {
	public:
		ll mod = 1000000007LL;
		int count (int N) {
			ll ans = 0LL;
			for (int i = 0; i < (1<<(N - 1)); ++i) {
				ll res = 1LL;
				for (int j = 0; j < N - 2; ++j) {
					int maxV = 1;
					if ((1<<j) & i)maxV = 2;
					for (int k = j + 1; k < N - 1; ++k) {
						if ((1<<k) & i) maxV = 2;
						if (maxV == 1) res = res * 2LL % mod;
					}
				}
				ans = (ans + res) % mod;
			}
			for (int i = 3; i <= N; ++i) {
				ans = ans * (ll)i % mod;
			}
			return (int)ans;
		}
};
