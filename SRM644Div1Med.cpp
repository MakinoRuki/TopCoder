// 2^K 表示当前叶节点到根节点路径上儿子个数的状态。

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define SZ 130
using namespace std;
typedef long long ll;
const int mod = 1000000007;
class MakingTournament {
	public:
		int mat[SZ][SZ];
		int ans[SZ][SZ];
		void multi (int mat1[][SZ], int mat2[][SZ], int sz) {
			int tmp[SZ][SZ];
			memset(tmp, 0, sizeof(tmp));
	//		for (int j = 0; j < sz; ++j) {
	//			memset(tmp, 0LL, sizeof(tmp));
	//			for (int i = 0; i < sz; ++i) {
	//				for (int k = 0; k < sz; ++k) {
	//					tmp[i] = (tmp[i] + mat1[i][k] * mat2[k][j] % mod) % mod;
	//				}
	//			}
	//			for (int i = 0; i < sz; ++i) {
	//				mat2[i][j] = tmp[i];
	//			}
	//		} 
			for (int i = 0; i < sz; ++i) {
				for (int j = 0; j < sz; ++j) {
					for (int k = 0; k < sz; ++k) {
						tmp[i][j] = (tmp[i][j] + (int)((ll)mat1[i][k] * (ll)mat2[k][j] % (ll)mod)) % mod;
					}
				}
			}
			for (int i = 0; i < sz; ++i) {
				for (int j = 0; j < sz; ++j) {
					mat2[i][j] = tmp[i][j];
				}
			}
		}
		void multiMat(int sz, ll pw) {
			memset(ans, 0, sizeof(ans));
			for (int i = 0; i < sz; ++i) {
				ans[i][i] = 1;
			}
			while (pw) {
		//		cout<<"pw="<<pw<<endl;
				if (pw & 1) {
					multi(mat, ans, sz);
				}
				multi(mat, mat, sz);
				pw /= 2;
		//		cout<<"ok"<<endl;
			}
		}
		int howManyWays (ll N, int K) {
			memset(mat, 0, sizeof(mat));
			for (int pre = 0; pre < (1<<(K + 1)); ++pre) {
				for (int i = 0; i < (K + 1); ++i) {
					if ((1<<i) & pre) {
						mat[pre - (1<<i) + 1][pre] = 1;
					} else {
						mat[pre + 1][pre] = 1;
						break;
					}
				}
			}
			multiMat((1<<(K + 1)), N - 1);
			return (ans[(1<<(K + 1)) - 1][0] + ans[(1<<K) - 1][0]) % mod;
		}
};
