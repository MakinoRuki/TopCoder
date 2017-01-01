#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 102
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class ModEquationEasy {
	public:
		int mat[N][N];
		int tmp[N][N];
		void multiMat (int ans[][N], int mat[][N], int n) {
			memset(tmp, 0, sizeof(tmp));
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					for (int k = 0; k < n; ++k) {
						tmp[i][j] = (tmp[i][j] + (int)((ll)mat[i][k] * (ll)ans[k][j] % mod)) % mod;
					}
				}
			}
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					ans[i][j] = tmp[i][j];
				}
			}
		}
		int solve (int mat[][N], int n, int m, int v) {
			int ans[N][N];
			memset(ans, 0, sizeof(ans));
			for (int i = 0; i < n; ++i) {
				ans[i][i] = 1;
			}
			while (m) {
				if (m & 1) {
					multiMat(ans, mat, n);
				}
				multiMat(mat, mat, n);
				m /= 2;
			}
			return ans[v][1];
		}
		int count (int n, int k, int v) {
			memset(mat, 0, sizeof(mat));
			for (int i = 0; i < k; ++i) {
				for (int j = 0; j < k; ++j) {
					int r = (i * j) % k;
					mat[r][i]++;
				}
			}
			return solve(mat, k, n, v);
		}
};
