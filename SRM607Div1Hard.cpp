#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 72
using namespace std;
typedef long long ll;
const ll inf = (1LL<<60);
ll dp[N][N][N][2];
// how do we know this 100000 & 40
ll comb[100002][45];
class PulleyTautLine {
	public:
		double A, B, R, e;
		ll getcomb(ll n, ll m) {
			if (n-m<m) m = n-m;
			if (m==0)return 1;
			if (m == 1) return n;
			if (m == 2 && 1.0/2.0*n*(n-1)<inf) return n*(n-1)/2;
			if (m == 3 && 1.0/6.0*n*(n-1)*(n-2)<inf) return n*(n-1)*(n-2)/6;
			if (n<100000&&m<40) return comb[n][m];
			return inf;
		}
		ll check(double mid, int n) {
			ll res = 0;
			for (int i = 0; i < 70; ++i) {
				for (int j = 0; j < 70; ++j) {
					if (dp[i][j][n-1][0]) {
						for (int k = 0; k <= i; ++k) {
							double L = A*k+(i-k)*B+j*R;
							if (L > mid) continue;
							ll cnt1 = getcomb(i,k);
							ll tmp = (ll)((mid - L)/2.0/R);
							ll cnt2 = getcomb(tmp+1+i,i+1);
							if (cnt2 > inf/cnt1/dp[i][j][n-1][0]) return inf;
							res += cnt2*cnt1*dp[i][j][n-1][0];
							if(res > inf) return inf;
						}
					}
				}
			}
			return res;
		}
		double getLength(int d, int r, int n, ll K) {
			A = d;
			B = sqrt((double)d * d - 4.0 * r * r) + 2.0 * r * asin(2.0 * r / d);
			R = r * acos(-1.0);
			e = sqrt((double)d * d - (double)r * r) + r * asin((double)r / d);
			
			if (n == 1) {
        		return (K - 1) / 2 * 2.0 * R + 2.0 * e;
   			}
			for (int i = 0; i <= 100000; ++i) {
				comb[i][0] = 1LL;
				for (int j = 1; j <= min(i,40); ++j) {
					comb[i][j] = (j > i - j ? comb[i][i-j] : min(comb[i-1][j]+comb[i-1][j-1],inf));
				}
			}
			memset(dp, 0LL, sizeof(dp));
			dp[0][0][0][0] = 2LL;
			for (int i = 0; i < 70; ++i) {
				for (int j = 0; j < 70; ++j) {
					for (int k = 0; k < n; ++k) {
						for (int s = 0; s < 2; ++s) {
							if (s == 0) {
								dp[i][j + 1][k][1] = min(inf, dp[i][j+1][k][1]+dp[i][j][k][s]);
							}
							if (!(j&1) && k + 1 < n) {
								dp[i+1][j][k+1][0] = min(inf, dp[i+1][j][k+1][0]+dp[i][j][k][s]);
							}
							if ((j&1) && k - 1 >= 0) {
								dp[i+1][j][k-1][0] = min(inf, dp[i+1][j][k-1][0]+dp[i][j][k][s]);
							}
						}
					}
				}
			}
			double lb = 0.0, rb = 1000.0*A;
			for (int i = 0; i < 50; ++i) {
				double mid = (lb+rb)*0.5;
				if (check(mid, n) >= K) {
					rb = mid;
				} else {
					lb = mid;
				}
			}
			return rb + 2.0*e;
		}
};
