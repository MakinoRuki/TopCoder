#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class CardCounter {
	public:
		double dp1[25][2][1<<16];
		vector<double> dp2[25][2][1<<16];
		vector<int> ds;
		int n, dv;
		vector<double> dfs2(int sum, int ace, int deck) {
			vector<double> res(22, 0);
			if (sum > 21) {
				res[0] = 1;
			} else if (ace && sum + 10 >= 17 && sum + 10 <= 21) {
				res[sum + 10] = 1;
			} else if (sum >= 17 && sum <= 21) {
				res[sum] = 1;
			} else {
				if (dp2[sum][ace][deck].size() > 0) {
					return dp2[sum][ace][deck];
				}
				int num = __builtin_popcount(deck);
				for (int i = 0; i < ds.size(); ++i) {
					if ((1<<i) & deck) {
						auto res2 = dfs2(sum + ds[i], ace | (ds[i] == 1), deck ^ (1<<i));
						for (int j = 0; j < res2.size(); ++j) {
							res[j] += res2[j] / (double)num;
						}
					}
				}
				dp2[sum][ace][deck] = res;
			}
			return res;
		}
		double dfs(int sum, int ace, int deck) {
			if (sum > 21) return 0;
			if (dp1[sum][ace][deck] < 0) {
				auto deals = dfs2(dv, (dv == 1), deck);
				int pv = sum;
				if (ace && sum + 10 <= 21) pv += 10;
				double p1 = 0.0;
				for (int i = 0; i < pv; ++i) {
					p1 += deals[i];
				}
				double p2 = 0.0;
				for (int i = 0; i < ds.size(); ++i) {
					if ((1<<i) & deck) {
						p2 += dfs(sum + ds[i], ace | (ds[i] == 1), deck ^ (1<<i));
					}
				}
				dp1[sum][ace][deck] = max(p1, p2 / (double)__builtin_popcount(deck));
			}
			return dp1[sum][ace][deck];
		}
		double winningChance(vector<int> deck, int dealer, vector<int> player) {
			ds.clear();
			for (int i = 0; i < deck.size(); ++i) {
				for (int j = 1; j <= deck[i]; ++j) {
					ds.push_back(i + 1);
				}
			}
			dv = dealer;
			n = ds.size();
			for (int i = 0; i <= 22; ++i) {
				for (int j = 0; j < 2; ++j) {
					for (int k = 0; k < (1<<n); ++k) {
						dp1[i][j][k] = -1;
					}
				}
			}
			return dfs(player[0] + player[1], (player[0] == 1)|(player[1] == 1), (1<<n) - 1);
		}
};
