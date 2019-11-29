#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>
#define N 5600
using namespace std;
typedef long long ll;
class TwoMonthScheduling {
	public:
		int n;
		int dp[N][N];
		int minimumMonths(int workers, vector <int> fm0, vector <int> fm1, vector <int> sm0, vector <int> sm1) {
			int l0 = fm0.size();
			int l1 = fm1.size();
			ll fm[N];
			ll sm[N];
			ll fmsum[N];
			ll smsum[N];
			for (int i1 = 0; i1 < l1; ++i1) {
				for (int i0 = 0; i0 < l0; ++i0) {
					fm[i1 * l0 + i0] = min(workers, fm0[i0] ^ fm1[i1]);
					sm[i1 * l0 + i0] = min(workers, sm0[i0] ^ sm1[i1]);
				}
			}
			memset(fmsum, 0, sizeof(fmsum));
			memset(smsum, 0, sizeof(smsum));
			for (int i = 1; i <= l1 * l0; ++i) {
				fmsum[i] = fmsum[i-1] + fm[i-1];
				smsum[i] = smsum[i-1] + sm[i-1];
			}
			for (int i = 0; i <= l1 * l0; ++i) {
				for (int j = 0; j <= l1 * l0; ++j) {
					dp[i][j] = INT_MAX;
				}
			}
			dp[0][0] = 0;
			for (int i = 1; i <= l1 * l0; ++i) {
				if (fmsum[i] <= workers && smsum[i] <= workers) {
					dp[i][0] = 2;
				}
			}
			for (int i = 1; i < l1 * l0; ++i) {
				int minp = INT_MAX;
				for (int j = 0; j < i; ++j) {
					minp = min(minp, dp[i][j]);
				}
				int idx = i;
				int minv = INT_MAX;
				for (int j = l1 * l0; j > i; --j) {
					if (fmsum[j] - fmsum[i] <= workers && smsum[j] - smsum[i] <= workers) {
						if (minp < INT_MAX) dp[j][i] = min(dp[j][i], minp + 2);
					}
					while(idx > 0 && smsum[i] - smsum[idx-1] + fmsum[j] - fmsum[i] <= workers) {
						minv = min(minv, dp[i][idx-1]);
						idx--;
					}
					if (smsum[j] - smsum[i] <= workers) {
						if (minv < INT_MAX) dp[j][i] = min(dp[j][i], minv + 1);
					}
				}
			}
			int ans = INT_MAX;
			for (int i = 0; i < l1 * l0; ++i) {
				ans = min(ans, dp[l1*l0][i]);
			}
			return ans;
		}
};
