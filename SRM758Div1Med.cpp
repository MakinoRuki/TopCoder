#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define N 52
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
class LollipopHoney {
	public:
		ll dp[N][N][2];
		int n;
		ll comb[N][N];
		unordered_map<int, vector<int> > pops;
		vector<int> count(int K, vector<int> flv, vector<int> del) {
			n = flv.size();
			for (int i = 0; i <= n; ++i) {
				comb[i][0] = 1LL;
				for (int j = 1; j <= i; ++j) {
					comb[i][j] = (comb[i-1][j]+comb[i-1][j-1])%mod;
				}
			}
			pops.clear();
			for (int i = 0; i < n; ++i) {
				pops[flv[i]].push_back(del[i]);
			}
			for (int i = 0; i <= n; ++i) {
				for (int j = 0; j <= 2*K; ++j) {
					dp[i][j][0] = -1;
					dp[i][j][1] = 0;
				}
			}
			dp[0][0][0] = 0;
			dp[0][0][1] = 1;
			int i = 0;
		//	for (auto& pop : pops) {
			//	cout<<pop.second[0]<<" ";
		//	}cout<<endl;
			for (auto& pop : pops) {
			    vector<int> ds = pop.second;
			    sort(ds.begin(), ds.end());
			    reverse(ds.begin(), ds.end());
			    vector<int> sum(ds.size() + 1, 0);
			    for (int j = 1; j <= ds.size(); ++j) {
			    	sum[j] = sum[j-1]+ds[j-1];
			    }
			    vector<ll> cnt(ds.size() + 1, 0);
			    cnt[0] = 1;
			    for (int j = 1; j <= ds.size(); ++j) {
			    	int tot = 0;
			    	int idx = 0;
			    	for (int t = 0; t < ds.size(); ++t) {
			    		if (ds[t] == ds[j-1]) {
			    			tot++;
			    			if (t <= j - 1) idx++;
			    		}
			    	}
			    	cnt[j] = comb[tot][idx];
			    }
			 //   for (int j = 0; j <= 2*K; ++j) {
			   // 	cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
			   // }
				for (int j = 0; j <= 2*K; ++j) {
					if (dp[i][j][0] >= 0) {
						for (int k = 0; k <= min(K, (int)ds.size()) && k+j<=2*K; ++k) {
							ll v1 = dp[i][j][0]+sum[k];
							if (v1 > dp[i+1][j+k][0]) {
								dp[i+1][j+k][0] = v1;
								dp[i+1][j+k][1] = dp[i][j][1]*cnt[k]%mod;
							} else if (v1 == dp[i+1][j+k][0]) {
								dp[i+1][j+k][1]=(dp[i+1][j+k][1]+dp[i][j][1]*cnt[k]%mod)%mod;
							}
						}
					}
				}
				i++;
			}
			if (dp[i][2*K][0] >= 0) {
				return {(int)dp[i][2*K][0], (int)dp[i][2*K][1]};
			}
			return {};
		}
};
