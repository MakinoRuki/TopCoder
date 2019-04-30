#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
map<vector<int>, bool> dp;
class MatchNim {
	public:
		int n;
		bool dfs(vector<int>& piles) {
			if (dp.find(piles) != dp.end()) return dp[piles];
			if (piles.back() >= piles.size() - 1) return dp[piles] = true;
			int tot = (1<<piles.size()) - 1;
			for (int i = 1; i <= tot; ++i) {
				int bit = __builtin_popcount(i);
				vector<int> b;
				b.clear();
				bool found = false;
				for (int j = 0; j < piles.size(); ++j) {
					if ((1<<j) & i) b.push_back(piles[j]);
					else {
						if (piles[j] >= (piles.size() - bit - 1)) found = true;
					}
				}
				if (found && !dfs(b)) return dp[piles] = true;
				for (int j = 0; j < b.size(); ++j) {
					if (b[j] <= piles.size() - bit) continue;
					int lb = max(1, (int)piles.size() - bit);
					for (int k = lb; k < b[j]; ++k) {
						vector<int> c(b.begin(), b.end());
						c[j] = b[j] - k;
						for (int p = j; p > 0; --p) {
							if (c[p] >= c[p-1]) break;
							swap(c[p], c[p-1]);
						}
						if (!dfs(c)) return dp[piles] = true;
					}
				}
			}
			return dp[piles] = false;
		}
		string whoWins(vector<int> piles) {
			n = piles.size();
			dp.clear();
			sort(piles.begin(), piles.end());
			if (piles.back() >= n - 1) return "Yvonne";
			bool res = dfs(piles);
			//cout<<dp[{1}]<<" "<<dp[{1,1}]<<" "<<dp[{1,1,1}]<<endl;
			return res ? "Yvonne" : "Zara";
		}
};
