#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
class DivisorSequences {
	public:
	    unordered_map<int, int> dp;
		int dfs(int N) {
			if (dp.find(N) != dp.end()) return dp[N];
			if (N == 1) return 0;
			if (N <= 3) return dp[N]=1;
			dp[N] = 1;
			for (int i =2; (ll)i * (ll)i <= N; ++i) {
				if (N % i) continue;
				dp[N] = max(dp[N], dfs(N / i - 1)+1);
				dp[N] = max(dp[N], dfs(i - 1) + 1);
			}
			//cout<<N<<" "<<dp[N]<<endl;
			return dp[N];
		}
		int longest(int N) {
			dp.clear();
			if (N == 1) return 1;
			return max(dfs(N), dfs(N-1)+1);
		}
};
