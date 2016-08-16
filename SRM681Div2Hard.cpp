#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll dp[32][1<<10];
class XorLists {
	public:
		int n, m;
		int check (vector<int> & s, int i, int st, int b0) {
		//	if (i == 17 && st == 0) cout<<"ok1"<<endl;
			int mi = ((1 << (29 - i)) & m) > 0;
		//	if (i == 17 && st == 0) cout<<"ok2"<<endl;
			int nxt = 0;
			for (int b = 0; b < n; ++b) {
			//	if (i == 17 && st == 0) cout<<b<<endl;
				int bi = (s[b] & (1 << (29 - i))) > 0;
				bi ^= b0;
				int si = ((1 << b) & st);
				if (!si) {
					if (mi) {
						if (!bi) nxt |= (1 << b);
					} else {
						if (bi) return -1;
					}
				} else {
					nxt |= (1 << b);
				}
			}
	//		if (i == 17 && st == 0) cout<<"ok3"<<endl;
			return nxt;
		}
		int countLists (vector<int> s, int _m) {
			n = (int)sqrt(s.size());
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if ((s[i] ^ s[j]) != s[i * n + j]) return 0;
				}
			}
			m = _m;
			memset(dp, 0, sizeof(dp));
			dp[0][0] = 1LL;
			for (int i = 0; i < 30; ++i) {
				for (int j = 0; j < (1<<n); ++j) {
			//		cout<<i<<" "<<j<<endl;
					if (dp[i][j]) {
						for (int b0 = 0; b0 < 2; ++b0) {
					//		if (i == 17 && j == 0) cout<<"b0="<<b0<<endl;
							int nxt = check(s, i, j, b0);
					//		if (i == 17 && j == 0) cout<<"nxt="<<nxt<<endl;
							if (nxt >= 0) {
								dp[i + 1][nxt] = (dp[i + 1][nxt] + dp[i][j]) % mod;
							}
						//	if (i == 17 && j == 0) cout<<"!!!"<<endl;
						}
					}
				//	cout<<i<<" "<<j<<endl;
				}
			}
		//	cout<<dp[29][0]<<" "<<dp[29][1]<<endl;
			ll ans = 0LL;
			for (int i = 0; i < (1<<n); ++i) {
		//		cout<<i<<" "<<dp[30][i]<<endl;
				ans = (ans + dp[30][i]) % mod;
			}
			return (int)ans;
		}
};
