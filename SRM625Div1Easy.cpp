#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
class PalindromePermutations {
	public:
		int n;
		int cnt[27];
		double comb[N][N];
		double palindromeProbability(string word) {
			n = word.size();
			memset(cnt, 0, sizeof(cnt));
			for (int i = 0; i <= n; ++i) {
				comb[i][0] = 1.0;
				for (int j = 1; j <= i; ++j) {
					comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
				}
			}
			for (int i = 0; i < n; ++i) {
				cnt[word[i] - 'a']++;
			}
			int odd = 0;
			for (int i = 0; i < 26; ++i) {
				if (cnt[i] & 1) odd++;
			}
			if (odd > 1) return 0.0;
			double ans = 1.0;
			int tot = n;
			for (int i = 0; i < 26; ++i) {
				if (cnt[i] == 0) continue;
				double res = comb[tot / 2][cnt[i] / 2] / comb[tot][cnt[i]];
				ans *= res;
				tot -= cnt[i];
			}
			return ans;
		}
};
