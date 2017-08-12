#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 2502
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class ParenthesisRemoval {
	public:
		int n;
		int countWays (string s) {
			n = s.size();
			int j = 0;
			ll ans = 1LL;
			for (int i = 0; i < n;) {
				int sum = 0;
				for (j = i; j < n; ++j) {
					if (s[i] == '(') sum++;
					else sum--;
					if (sum < 0) break;
				}
				ll tmp = 1LL;
				int sum2 = 0;
				for (int k = j - 1; k >= i; --k) {
					if (s[k] == ')') sum2++;
					else {
						tmp = tmp * (ll)sum2 % mod;
						sum2--;
					}
				}
				ans = ans * tmp % mod;
				i = j;
			}
			return ans;
		}
};
