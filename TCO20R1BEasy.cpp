#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class EllysCandies {
	public:
		int dp[1<<20];
		string getWinner(vector<int> boxes) {
			int n = boxes.size();
			for (int i = 0; i < (1<<n); ++i) {
				dp[i] = -1000000000;
			}
			dp[0] = 0;
			for (int i = 1; i < (1<<n); ++i) {
				int rem=0;
				for (int j = 0; j < n; ++j) {
					if ((1<<j) & i) continue;
					rem += boxes[j];
				}
				for (int j = 0; j < n; ++j) {
					if (((1<<j)&i) && dp[i^(1<<j)] > -1000000000 && -dp[i^(1<<j)]+boxes[j]+rem > dp[i]) {
						dp[i] = -dp[i^(1<<j)]+boxes[j]+rem;
					}
				}
			}
			if (dp[(1<<n)-1] > 0) return "Elly";
			if (dp[(1<<n)-1] == 0) return "Draw";
			return "Kris";
		}
};
