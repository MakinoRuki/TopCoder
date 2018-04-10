#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 205
using namespace std;
class TreesAndBrackets {
	public:
		vector<int> edges[N];
		int cnt = -1;
		int dp[N][N];
		int maketree(string t) {
			++cnt;
			int cur = cnt;
			edges[cnt].clear();
			int sum = 0;
			string subt;
			for (int i = 1; i < t.size() - 1; ++i) {
				subt += t[i];
				if (t[i] == '(')sum++;
				else sum--;
				if (sum == 0) {
					edges[cur].push_back(maketree(subt));
					subt.clear();
				}
			} 
			return cur;
		}	
		int solve(int r1, int r2) {
			if (dp[r1][r2] >= 0) return dp[r1][r2];
			if (edges[r1].size() < edges[r2].size()) return dp[r1][r2] = 0;
			if (edges[r2].size() == 0) return dp[r1][r2] = 1;
			int j = 0;
			for (int i = 0; i < edges[r1].size(); ++i) {
				if (j >= edges[r2].size()) break;
				if (!solve(edges[r1][i], edges[r2][j])) continue;
				j++;
			}
			if (j < edges[r2].size()) return dp[r1][r2] = 0;
		//	dp[r1][r2] = 1;
		//	cout<<r1<<" "<<r2<<" "<<dp[r1][r2]<<endl;
			return dp[r1][r2] = 1;
		}
		string check(string t1, string t2) {
			int r1 = maketree(t1);
			int r2 = maketree(t2);
			memset(dp, -1, sizeof(dp));
			if (solve(r1, r2)) return "Possible";
			return "Impossible";
		}
};
