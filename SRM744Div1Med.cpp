#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 102
using namespace std;
class UniformingMatrix {
	public:
		bool mat[N][N];
		int n, m;
		string isPossible(vector <string> M) {
			n = M.size();
			m = M[0].size();
			for (int s = 0; s < 2; ++s) {
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < m; ++j) {
						mat[i][j] = (M[i][j] - '0');
					}
				}
				int rt = 0, ct = 0;
				for (int i = 0; i < n; ++i) {
					if (mat[i][0] != s) {
						rt++;
						for (int j = 0; j < m; ++j) {
							mat[i][j] ^= 1;
						}
					}
				}
				for (int j = 0; j < m; ++j) {
					if (mat[0][j] == 0) {
						ct++;
						for (int i = 0; i < n; ++i) {
							mat[i][j] ^= 1;
						}
					}
				}
				bool ok = true;
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < m; ++j) {
						if (mat[i][j] == 0) ok = false;
					}
				}
				if (!ok) continue;
				if ((rt + ct) % 2) continue;
				return "possible";
			}
			return "impossible";
		}
};
