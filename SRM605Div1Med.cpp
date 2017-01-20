#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 102
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class AlienAndSetDiv1 {
	public:
		ll dp[N][N][1<<11];
		int n, k;
		ll dfs (int cur, int more, int less) {
		//	cout<<cur<<" "<<more<<" "<<less<<endl;
			if (dp[cur][more][less] >= 0) return dp[cur][more][less];
			if (cur > 2 * n) {
				if (!more && !less) {
					return 1;
				}
				return 0;
			}
			if (k == 1) {
				if (!more && !less) {
					dp[cur][more][less] = 2 * dfs(cur + 1, more + 1, less) % mod;
				} else {
					int res = 0;
					if (more) res = (res + dfs(cur + 1, more - 1, less)) % mod;
					res = (res + dfs(cur + 1, more + 1, less)) % mod;
					dp[cur][more][less] = res;
				}
			} else {
				if (!more && !less) {
					dp[cur][more][less] = 2 * dfs(cur + 1, more, less | 1) % mod;
				} else {
					int res = 0;
					if (more) {
						int nmore = more - 1;
						if ((1<<(k-2)) & less) {
							nmore++;
						}
						int nless = (less << 1) & ((1<<(k-1)) - 1);
						res = (res + dfs(cur + 1, nmore, nless)) % mod;
					}
					int nmore = more;
					if ((1<<(k-2)) & less) {
						nmore++;
					}
					int nless = (less << 1) & ((1<<(k-1)) - 1);
					nless |= 1;
					res = (res + dfs(cur + 1, nmore, nless)) % mod;
					dp[cur][more][less] = res;
				}
			}
			return dp[cur][more][less];
		} 
		int getNumber (int n1, int k1) {
			n = n1;
			k = k1;
			memset(dp, -1, sizeof(dp));
			return (int)(dfs(1, 0, 0));
		}
};
