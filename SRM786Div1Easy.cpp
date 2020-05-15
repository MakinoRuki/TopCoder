#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 200002
using namespace std;
typedef long long ll;
const ll mod = 1812447359LL;
class SwapTheString {
	public:
		ll a[N];
		int cnt[N][27];
		ll findNumberOfSwaps (string p, int a0, int x, int y, int n, int k) {
			a[0] = a0;
			for (int i = 1; i < n; ++i) {
				a[i] = (a[i-1]*(ll)x+(ll)y) % mod;
			}
			string s = p;
			for (int i = p.size(); i < n; ++i) {
				s.push_back(a[i]%26 + 'a');
			}
			memset(cnt, 0, sizeof(cnt));
			ll ans=0LL;
			for (int i = 0; i < n; ++i) {
				int r = i % k;
				int c = s[i]-'a';
				for (int j = 0; j < c; ++j) {
					ans += cnt[r][j];
				}
				cnt[r][c]++;
			}
			return ans;
		}
};
