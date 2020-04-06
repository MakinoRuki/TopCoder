#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <deque>
#include <map>
#define N 52
using namespace std;
typedef long long ll;
class MysteriousRestaurant {
	public:
		int ps1[N][8];
		int dp[1<<7];
		int getps(vector<string>& ps, int i, int j) {
			char c = ps[i][j];
			if (c >= '0' && c <= '9') return c-'0';
			if (c >= 'A' && c <= 'Z') return c-'A'+10;
			return c-'a'+36;
		}
		int maxDays(vector<string> ps, int bt) {
			int n = ps.size();
			int m = ps[0].size();
			for (int i = n; i >= 1; --i) {
				memset(ps1, 0, sizeof(ps1));
				for (int j = 0; j < m; ++j) {
					for (int d = 0; d < 7; ++d) {
						for (int k = d; k < i; k += 7) {
							ps1[j][d] += getps(ps, k, j);
						}
					}
				}
				int md = min(7, i);
				for (int j= 0; j < (1<<md); ++j) {
					dp[j] = 1000000000;
				}
				dp[0] = 0;
				for (int j = 0; j < (1<<md); ++j) {
					if (dp[j] >= 1000000000) continue;
					for (int k = 0; k < m; ++k) {
						for (int d = 0; d < md; ++d) {
							if ((1<<d) & j) continue;
							dp[j|(1<<d)] = min(dp[j|(1<<d)], dp[j]+ps1[k][d]);
						}
					}
				}
			//	cout<<dp[1<<0]<<" "<<dp[2]<<" "<<dp[3]<<" "<<dp[4]<<" "<<dp[5]<<endl;
				if (dp[(1<<md)-1] <= bt) return i;
			}
			return 0;
		}
};
