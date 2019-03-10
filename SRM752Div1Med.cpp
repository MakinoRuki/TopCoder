#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#define N 1002
using namespace std;
class Literature {
	public:
		int m;
		double dp[N][N][3];
		double expectation(int n, vector<int> A, vector<int> his) {
			m = his.size();
			int n1 = 0, n2 = 0;
			set<int> As(A.begin(), A.end());
			set<int> Bs, Cs;
			Bs.clear();
			Cs.clear();
			for (int i = 0; i < m; ++i) {
				if (i % 3 == 0) continue;
				if ((i % 3) == 1 && As.find(his[i]) == As.end()) Cs.insert(his[i]);
				if ((i % 3) == 2 && As.find(his[i]) == As.end()) Bs.insert(his[i]);
				if (Bs.size() == n || Cs.size() == n) return i + 1;
			}
			n1 = Bs.size();
			n2 = Cs.size();
			for (int i = 0; i <= n; ++i) {
				for (int j = 0; j <= n; ++j) {
					for (int k = 0; k < 3; ++k) {
						dp[i][j][k] = 0.0;
					}
				}
			}
			for (int i = n - 1; i >= 0; --i) {
				for (int j = n - 1; j >= 0; --j) {
					dp[i][j][1] = (double)(n - j) / (double)(2 * n) * dp[i][j + 1][2] + (double)(n + j)*(n - i)/(double)(4*n*n) * dp[i+1][j][0];
					dp[i][j][1] += (double)(n+j)*(n+i) / (double)(4*n*n) + (double)(n+j)/(double)(2*n) + 1.0;
					dp[i][j][1] /= (1 - (double)(n+j)*(n+i)/(double)(4*n*n));
					dp[i][j][0] = dp[i][j][1]+1;
					dp[i][j][2] = (double)(n-i)/(double)(2*n) * dp[i + 1][j][0] + (double)(n+i)/(double)(2*n) * dp[i][j][0] + 1.0;
				}
			}
			return dp[n1][n2][m % 3] + m;
		}
};
