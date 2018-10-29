#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 100005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class RandomGCD {
	public:
		int dp[N];
		int getres(int num, int n) {
			ll res = 1LL;
			while(n) {
				if (n & 1) res = res * num % mod;
				num = (ll)num * (ll)num % mod;
				n /= 2;
			}
			return res;
		}
		int countTuples(int n, int k, int low, int high) {
			memset(dp, 0, sizeof(dp));
			int len = high - low + 1;
			high = high / k;
			low = low / k + ((low % k) > 0);
			for (int i = len; i > 0; --i) {
				int h = high / i;
				int l = low / i + ((low % i) > 0);
				dp[i] = getres(h - l + 1, n);
				for (int j = 2; j * i <= len; ++j) {
					dp[i] = (dp[i] - dp[i * j] + mod) % mod;
				}
				for (int j = l; j <= h; ++j) {
					if ((ll)j * (ll)i > len) dp[i] = (dp[i] - 1 + mod) % mod;
				}
			}
			return (int)dp[1];
		}
};
