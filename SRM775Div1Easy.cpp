#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 3000006
using namespace std;
typedef long long ll;
ll dp[N];
class IterateOverACube {
	public:
		ll comb(ll a) {
			return a * (a-1) / 2LL;
		}
		vector<int> findCell(int n, ll idx) {
			memset(dp, 0, sizeof(dp));
			for (int i = 0; i <= 3 * n - 3; ++i) {
				dp[i] = comb(i+2);
				if (i >= n) {
					dp[i] -= 3 * comb(i-n+2);
				}
				if (i >= 2 * n) {
					dp[i] += 3 * comb(i-2*n+2); 
				}
				if (i >= 3 * n) {
					dp[i] += comb(i - 3*n+2);
				}
			}
			ll sum = 0;
			idx++;
			int cur=0;
			while(true) {
				if (sum + dp[cur] < idx) {
					sum += dp[cur];
					cur++;
				} else {
					break;
				}
			}
			vector<int> ans;
			ans.clear();
			idx -= sum;
			for (int i = 0; i < n; ++i) {
				ll s2 = cur-i;
				ll l = max(0LL, s2+1-n);
				ll r = min(s2, (ll)n-1);
				if (l <= r) {
					ll det = r-l+1;
					if (idx > det) {
						idx -= det;
					} else {
						ans.push_back(i);
						break;
					}
				}
			}
			ll s2 = cur - ans[0];
			ans.push_back(max(0LL, s2+1-n)+idx-1);
			ans.push_back(s2 - ans[1]);
			return ans;
		}
};
