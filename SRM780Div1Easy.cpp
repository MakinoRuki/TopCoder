#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 102
using namespace std;
class BeatTheStar {
	public:
		double dp[N][51*N];
		double doesItMatter(int n, int g) {
			for (int i = 0; i <= n; ++i) {
				for (int j = 0; j <= 51*n; ++j) {
					dp[i][j] = 0.0;
				}
			}
			dp[0][0] = 1.0;
			int sum = (1+n)*n/2;
			vector<int> ns;
			for (int i = 1; i <= n; ++i) {
				if (i != g) ns.push_back(i);
			}
			for (int i = 0; i < n-1; ++i) {
				for (int j = 0; j <= sum-g; ++j) {
					dp[i+1][j] += dp[i][j] * 0.5;
					if (j + ns[i] <= sum-g) {
						dp[i+1][j + ns[i]] += dp[i][j] * 0.5;
					} 
				}
			//	cout<<i<<endl;
			//	for (int j = 0; j <= sum; ++j) cout<<dp[i+1][j]<<" ";
			//	cout<<endl;
			}
			//cout<<dp[4][3]<<" "<<dp[4][4]<<" "<<dp[4][5]<<" "<<dp[4][6]<<" "<<dp[4][7]<<endl;
			double ans=0.0;
			sum -= g;
			for (int i = 0; i <= sum; ++i) {
				if (i < sum-i && i+g>sum-i) {
				//	cout<<"1:"<<i<<" "<<sum-i<<endl;
					ans += dp[n-1][i];
				} else if (i > sum-i && sum-i+g > i) {
				//	cout<<"2:"<<i<<" "<<sum-i<<endl;
					ans += dp[n-1][i];
				} else if (i == sum-i) {
					ans += dp[n-1][i];
				}
			}
			return ans;
		}
};
