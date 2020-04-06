#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <deque>
#include <map>
#define N 1000005
using namespace std;
typedef long long ll;
class DivideAndShift {
	public:
		int dp[N];
		vector<int> pr;
		int getLeast(int n, int m) {
			pr.clear();
			int x = n;
			for (int i = 2; i * i <= x; ++i) {
				if (x % i == 0) {
					pr.push_back(i);
					while(x%i==0) x/=i;
				}
			}
			if (x>1) pr.push_back(x);
		//	cout<<pr[77777][0]<<" "<<pr[11111][0]<<endl;
		//	cout<<pr[49][0]<<endl;
			for (int i = 1; i <= n; ++i) {
				dp[i] = m-1;
			}
			dp[1] = 0;
			for (int i = 2; i <= n; ++i) {
				if (n%i==0) dp[i] = min((m-1)%i, i-(m-1)%i);
				for (int j =0;j < pr.size(); ++j) {
					if (i % pr[j]) continue;
					dp[i] = min(dp[i], dp[i/pr[j]]+1);
				}
			}
		//	cout<<dp[2]<<" "<<dp[4]<<" "<<dp[7]<<" "<<dp[8]<<" "<<dp[14]<<endl;
			return dp[n];
		}
};
