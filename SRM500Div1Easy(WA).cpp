#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 502
using namespace std;
typedef long long ll;
class MafiaGame {
public:
	int cnt[N];
	double comb(int n, int m) {
		if (n < m) return 0.0;
		double res1 = 1.0;
		double res2 = 1.0;
		for (int i = n; i >= n-m+1; --i) res1 *= (double)i;
		for (int i = 1; i <= m; ++i) res2 *= (double)i;
		return res1/res2;
	}
	double probabilityToLose(int n, vector<int> ds) {
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < ds.size(); ++i) {
			cnt[ds[i]]++;
		}
		int tot=0;
		int maxv = 0;
		for (int i = 0; i < n; ++i) {
			if (cnt[i] > 1) {
				maxv = max(maxv, cnt[i]);
			}
		}
		for (int i = 0; i < n; ++i) {
			if (cnt[i] == maxv) {
				tot++;
			}
		}
		if (!tot) return 0.0;
		double ans=1.0;
		while(tot > 1) {
			int r = n % tot;
			if (r == 0) return 0.0;
			ans *= (double)r / (double)tot;
			tot = r;
		}
		return ans;
	}
};
