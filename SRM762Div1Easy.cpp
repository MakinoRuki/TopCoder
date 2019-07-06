#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class LexicographicPartition {
	public:
		vector<int> ans;
		vector<int> positiveSum(int n, vector<int> ap, int seed, int ar) {
			ans.clear();
			vector<int> a;
			a.clear();
			for (int i = 0; i < ap.size(); ++i) {
				a.push_back(ap[i]);
			}
			ll stat = seed;
			for (int i = ap.size(); i < n; ++i) {
				stat = (1103515245LL * stat + 12345);
				a.push_back(stat % (2LL * ar + 1));
				a.back() = a.back() - ar;
				stat = stat % (1LL << 31);
			}
			vector<ll> sum;
			sum.clear();
			for (int i = n - 1; i >= 0; --i) {
				if (i == n - 1) sum.push_back(a[i]);
				else sum.push_back(sum.back() + a[i]);
			}
			reverse(sum.begin(), sum.end());
			if (sum[0] <= 0) return {-1};
			else {
				int cnt1 = 0;
				int cnt2=  0;
				ll tot =0;
				sum.push_back(0);
				for (int i = 0; i < n; ++i) {
					tot += a[i];
					cnt1++;
					if (tot > 0 && sum[i+1] > 0) {
						cnt2++;
						if (cnt2 <= 200) {
							ans.push_back(cnt1);
						}
						cnt1 = 0;
						tot = 0;
					}
				}
				if (cnt1) {
					cnt2++;
					if (tot <= 0) return {-1};
				}
				if (cnt1 && tot > 0 && cnt2 <= 200) {
					ans.push_back(cnt1);
				}
				reverse(ans.begin(), ans.end());
				ans.push_back(cnt2);
				reverse(ans.begin(), ans.end());
			}
			return ans;
		}
};
