#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1000010
using namespace std;
typedef long long ll;
ll pos[N];
ll sum[N];
class LeftAndRightHandedDiv1 {
	public:
		int cnt;
		ll solve(int center, int n) {
			ll l = (cnt-1)/2;
			ll r = cnt-1-l;
			ll res = pos[center] * l - (ll)(l+1)*l/2;
			if (center >= l) {
				res -= sum[center] - sum[center-l];
			} else {
				res -= sum[center];
				res -= sum[cnt] - sum[cnt - (l - center)] - (ll)n * (l - center);
			}
			res -= r * pos[center] + (ll)(r+1)*r/2;
			if (center + r < cnt) {
				res += sum[center+r+1] - sum[center+1];	
			} else {
				res += sum[cnt] - sum[center+1];
				res += sum[r - cnt + (center+1)] + (ll)n * (r - cnt + (center+1));
			}
			return res;
		}
		ll countSwaps(string Y, int a, int b, int c, int d, int n) {
			cnt = 0;
			ll t = a;
			for (int i = 0; i < n; ++i) {
				if (i) {
					t = (t * (ll)b % (ll)d + (ll)c) % (ll)d;
				}
				if (Y[t%Y.size()] == 'R') pos[cnt++] = i;
			}
			if (cnt == 0 || cnt == n) {
				return 0;
			}
			for (int i = 0; i < cnt; ++i) {
				sum[i + 1] = sum[i] + pos[i];
			}
			ll ans = (ll)n * (ll)n + 1;
			for (int i = 0; i < cnt; ++i) {
				ans = min(ans, solve(i, n));
			}
			return ans;
		}
};
