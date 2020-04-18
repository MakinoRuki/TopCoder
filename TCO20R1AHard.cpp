#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
double dp[N][N][N][N];
class BlindBoxSets {
	public:
		int ns, ni;
		double dfs(int a, int b, int c, int d) {
		//	cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
			if (dp[a][b][c][d]>=0.0) return dp[a][b][c][d];
			int tot=0;
			if (ns == 1) tot = a+b+c+d;
			if (ns == 2) tot = b+c+d;
			if (ns == 3) tot = c+d;
			if (ns == 4) tot = d;
			if (tot >= ni) return 0.0;
			
		//	if (ns==4 && d==ni) return 0.0;
			int e = ni-a-b-c-d;
			dp[a][b][c][d] = 0.0;
			double res = 0.0;
			if (e>0) res += (dfs(a+1, b, c, d))*((double)e/(double)ni);
			if (a>0) res += (dfs(a-1, b+1, c, d))*((double)a/(double)ni);
			if (b>0) res+= (dfs(a, b-1, c+1, d))*((double)b/(double)ni);
			if (c>0) res+=(dfs(a, b, c-1, d+1))*((double)c/(double)ni);
			if (d > 0) dp[a][b][c][d] = (res+1.0)*(double)ni/(double)(ni-d);
			else dp[a][b][c][d] = res + 1.0;
			return dp[a][b][c][d];
		}
		double expectedPurchases(int ns2, int ni2) {
			ns = ns2;
			ni = ni2;
			for (int i = 0; i <= ni; ++i) {
				for (int j = 0; j <= ni; ++j) {
					for (int k = 0; k <= ni; ++k) {
						for (int t= 0; t <= ni; ++t) {
							dp[i][j][k][t] = -1.0;
						}
					}
				}
			}
			double res = dfs(0,0,0,0);
			return res;
		}
};
