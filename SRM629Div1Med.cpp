#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1002
#define inf 1000000000
using namespace std;
class CandyCollection {
	public:
		int n;
		int dp[N][2][2];
		vector<pair<int, int> > ss[N];
		vector<int> fs[N];
		bool vis[N];
		int solve(int s) {
			vis[s] = true;
			dp[s][0][0] = 0;
			int n1 = ss[s][0].second;
			int n2 = ss[s][1].second;
			dp[s][1][1] = max(n1, n2) + 1;
			if (n1 < n2) dp[s][0][1] = n1 + 1;
			else if (n1 > n2) dp[s][1][0] = n2 + 1;
			int f = ss[s][1].first;
			int i = s;
			int last;
			while(true) {
				int j = fs[f][0];
				if (j == i) j = fs[f][1];
				if (j == s) break;
				vis[j] = true;
				int f2 = ss[j][0].first;
				if (f2 == f) f2 = ss[j][1].first;
				int n1 = ss[j][0].second, n2 = ss[j][1].second;
				if (f == ss[j][1].first) swap(n1, n2);
				for (int a = 0; a < 2; ++a) {
					for (int b = 0; b < 2; ++b) {
						dp[j][a][1] = min(dp[j][a][1], dp[i][a][b] + max(n1, n2) + 1);
						if (b) {
							dp[j][a][0] = min(dp[j][a][0], dp[i][a][b]);
							if (n1 < n2) dp[j][a][1] = min(dp[j][a][1], dp[i][a][b] + n1 + 1);
							else if (n1 > n2) dp[j][a][0] = min(dp[j][a][0], dp[i][a][b] + n2 + 1);
						} else {
							if (n1 > n2) dp[j][a][0] = min(dp[j][a][0], dp[i][a][b] + n2 + 1);
						}
					}
				}
				f = f2;
				i = j;
				last = j;
			}
			int res = min(dp[last][1][0], dp[last][1][1]);
			res = min(res, dp[last][0][1]);
			return res;
		}
		int solve(vector <int> type1, vector <int> num1, vector <int> type2, vector <int> num2) {
			n = type1.size();
			for (int i = 0; i <= n; ++i) {
				for (int a = 0; a < 2; ++a) {
					for (int b = 0; b < 2; ++b) {
						dp[i][a][b] = inf;
					}
				}
			}
			for (int i = 0; i < n; ++i) {
				ss[i].push_back(make_pair(type1[i], num1[i]));
				fs[type1[i]].push_back(i);
			}
			for (int i = 0; i < n; ++i) {
				ss[i].push_back(make_pair(type2[i], num2[i]));
				fs[type2[i]].push_back(i);
			}
			for (int i = 0; i < n; ++i) {
				sort(ss[i].begin(), ss[i].end());
				sort(fs[i].begin(), fs[i].end());
			}
			memset(vis, false, sizeof(vis));
			int ans = 0;
			for (int i = 0; i < n; ++i) {
				if (!vis[i]) {
					ans += solve(i);
				}
			}
			return ans;
		}
};
