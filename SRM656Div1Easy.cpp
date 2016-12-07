#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 252
using namespace std;
class RandomPancakeStack {
	public:
		int n;
		double exp[N][N];
		double expectedDeliciousness (vector<int> d) {
			n = d.size();
			for (int i = 0; i <= n; ++i) {
				for (int j = 0; j <= n; ++j) {
					exp[i][j] = 0.0;
				}
			}
			for (int i = 0; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					for (int k = 0; k < i; ++k) {
						exp[i][j] += (exp[k][j - 1] + (double)d[k]) / (double)j; 
					}
				}
			}
			return exp[n][n];
		}
};
