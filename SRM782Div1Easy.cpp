#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
double dp[1<<14];
double pr[14];
vector<int> cs[200];
class EmptyTheBox {
	public:
		double minExpectedPenalty(int D, int T) {
			double rem = 0.0;
			for (int i = T; i > 2*D; --i) {
				rem += (double)i;
			}
			for (int i = 0; i < 200; ++i) {
				cs[i].clear();
			}
			for (int i = 0; i <= 2*D; ++i) {
				pr[i] = 0.0;
			}
			for (int i = 1; i <= D; ++i) {
				for (int j = 1; j <= D; ++j) {
					pr[i+j] += 1.0/(double)D * 1.0/(double)D;
				}
			}
			int m = min(2*D, T);
			for (int i = 0; i < (1<<m); ++i) {
				int sum=0;
				for (int j = 0; j < m; ++j) {
					if ((1<<j)&i) sum += j+1;
				}
				cs[sum].push_back(i);
			}
			for (int i = 0; i < (1<<m); ++i) {
				dp[i] = -1.0;
			}
			dp[0] = 0.0;
			for (int i = 1; i < (1<<m); ++i) {
				dp[i] = 0.0;
				double v = 0.0;
				for (int j = 0; j < m; ++j) {
					if ((1<<j)&i) v +=(double)(j+1);
				}
				for (int x= 2; x <= 2*D; ++x) {
					bool found=false;
					double tmp=-1.0;
					for (int j = 0; j < cs[x].size(); ++j) {
						int k = cs[x][j];
						if (dp[i^k]>=0.0 && ((i&k)==k)) {
							found=true;
							if (tmp<0.0) tmp = dp[i^k];
							else tmp = min(tmp, dp[i^k]);
						}
					}
				//	if (i == 1) cout<<x<<" "<<tmp<<" "<<pr[x]<<" "<<v<<endl;
					if (!found) dp[i] += pr[x]*v;
					else dp[i] += pr[x]*tmp;
				}
			//	if (i == 1) cout<<"???"<<dp[i]<<endl;
			}
		//	for (int i = 0; i < (1<<m); ++i) {
			//	cout<<i<<" "<<dp[i]<<endl;
		//	}
			return dp[(1<<m)-1]+rem;
		}
};
