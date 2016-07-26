#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class BracketSequenceDiv2 {
  
};











/*#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 102
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class BracketSequenceDiv2 {
	public:
		int n;
		int dp[N][N];
		int count(string s) {
			n = s.size();
			memset(dp, 0, sizeof(dp));
			dp[0][0] = 1;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j <= i; ++j) {
					if (dp[i][j]) {
						int k;
						for (k = i + 1; k <= n; ++k) {
							if (s[k - 1] == '(') {
								break;
							}
						}
						dp[k][j + 1] = (dp[i][j] + dp[k][j + 1]) % mod;
						if (!j) continue;
						for (k = i + 1; k <= n; ++k) {
							if (s[k - 1] == ')') {
								break;
							}
						}
						dp[k][j - 1] = (dp[k][j - 1] + dp[i][j]) % mod;
					}	
				}
			}
			ll ans = 0;
			for (int i = 1; i <= n; ++i) {
				ans = (ans + dp[i][0]) % mod;
			}
			return ans;
		}
};*/
