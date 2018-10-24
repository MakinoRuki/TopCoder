#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
#define M 5002
#define mp make_pair
#define pii pair<int, int>
using namespace std;
class AlbertoTheAviator {
	public:
		int n;
		int dp[N][M];
		void update(int& org, int val) {
			org = max(org, val);
		}
		int MaximumFlights(int F, vector <int> d, vector <int> r) {
			n = d.size();
			vector<pii> missions;
			missions.clear();
			for (int i = 0; i < n; ++i) {
				missions.push_back(mp(r[i], d[i]));
			}
			sort(missions.begin(), missions.end());
			reverse(missions.begin(), missions.end());
			memset(dp, 0, sizeof(dp));
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j <= F; ++j) {
					update(dp[i + 1][j], dp[i][j]);
					if (j >= missions[i].second) {
						update(dp[i + 1][j - missions[i].second + missions[i].first], dp[i][j] + 1);
					}
				}
			}
			int ans = 0;
			for (int i = 0; i <= F; ++i) {
				ans = max(ans, dp[n][i]);
			}
			return ans;
		}
};
