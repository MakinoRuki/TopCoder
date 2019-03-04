#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
class ShufflingCardsDiv1 {
	public:
		int n;
		int shuffle (vector<int> permutation) {
			n = permutation.size() / 2;
			int i;
			for (i = 0; i < 2 * n; ++i) {
				if (permutation[i] != i + 1) {
					break;
				}
			}
			if (i >= 2 * n) {
				return 0;
			}
			int tot = 0;
			for (int i = 0; i < 2 * n; i += 2) {
				if (permutation[i] > n) {
					tot++;
				}
			}
			if (tot == 0) return 1;
			if (tot == n / 2) return 2;
			if ((tot == n) && (n & 1)) return 4;
			return 3;
		}
};
