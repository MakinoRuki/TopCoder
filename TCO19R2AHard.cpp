// 在求i的时候，枚举了第一堆的j之后，要考虑所有的i-j的sg值。
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <unordered_set>
using namespace std;
class YetAnotherTokenGame {
	public:
		int n;
		int sg[302];
		string getWinner(vector<int> piles) {
			memset(sg, 0, sizeof(sg));
			unordered_set<int> dp[302];
			for (int i = 0; i <= 300; ++i) {
				dp[i].clear();
			}
			dp[0].insert(sg[0]);
			for (int i = 1; i <= 300; ++i) {
				unordered_set<int> sgs;
				sgs.clear();
				for (int j = 0; j < i; ++j) {
					sgs.insert(sg[j]);
				}
				for (int j = 1; j < i; ++j) {
					for (auto k : dp[i - j]) {
						sgs.insert(sg[j] ^ k);
						dp[i].insert(sg[j] ^ k);
					}
				}
				while(sgs.find(sg[i]) != sgs.end()) {
					sg[i]++;
				}
				dp[i].insert(sg[i]);
			}
			int ans = 0;
			n = piles.size();
			for (int i = 0; i < n; ++i) {
				ans ^= sg[piles[i]];
			}
			return (ans ? "William" : "Xenia");
		}
};
