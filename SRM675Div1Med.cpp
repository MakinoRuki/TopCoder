#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define det 100000
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class LimitedMemorySeries1 {
	int m;
	int cnt[det];
	public:
	ll getSum (int n, int x0, int a, int b, vector<int> query) {
		m = query.size();
		memset(cnt, 0, sizeof(cnt));
		int x = x0;
		cnt[x / det]++;
		for (int i = 1; i < n; ++i) {
			x = (int)(((ll)x * (ll)a + (ll)b) % mod);
			cnt[x / det]++;
		}
	//	for (int i = 0; i < det; ++i) if (cnt[i]) cout<<i<<" "<<cnt[i]<<endl;
		ll ans = 0LL;
		for (int i = 0; i < m; ++i) {
			int q = query[i] + 1;
			int tot = 0;
			int j;
			for (j = 0; j < det; ++j) {
				tot += cnt[j];
				if (tot >= q) break;
			}
			tot -= cnt[j];
	//		cout<<j<<endl;
			vector<int> rem(det, 0);
			x = x0;
			for (int k = 0; k < n; ++k) {
				if (x / det == j) rem[x % det]++;
				x = (int)(((ll)x * (ll)a + (ll)b) % mod);
			}
			for (int k = 0; k < det; ++k) {
				tot += rem[k];
				if (tot >= q) {
					ans += det * j + k;
					break;
				}
			}
		//	cout<<ans<<endl;
		}
		return ans;
	}
};
