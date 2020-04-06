#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <deque>
#include <map>
#define N 52
using namespace std;
typedef long long ll;
vector<int> pr[N];
class LuckyRemainder {
	public:
		int comb[N][N];
		int pw[N];
		int getLuckyRemainder(string x) {
			reverse(x.begin(), x.end());
			int n = x.size();
			memset(comb, 0, sizeof(comb));
			for (int i = 0; i <= n; ++i) {
				comb[i][0] = 1;
				for (int j = 1; j <= i; ++j) {
					comb[i][j] = (comb[i-1][j]+comb[i-1][j-1])%9;
				}
			}
			pw[0] = 1;
			for (int i = 1; i <= n; ++i) {
				pw[i] = pw[i-1]*10%9;
			}
			int ans=0;
			for (int i = 0; i < n; ++i) {
				int res=0;
				int d= x[i]-'0';
				for (int j = 0; j <= i; ++j) {
					res = (res + d * pw[j]*comb[i][j] % 9) % 9;
				//	if (i==1) cout<<j<<" "<<d<<" "<<pw[j]<<" "<<comb[i][j]<<" "<<res<<endl;
				}
			//	cout<<i<<" "<<d<<" "<<res<<endl;
				int res2=1;
				for (int j = 1; j <= n-i-1;++j) {
					res2=res2*2%9;
				}
				ans = (ans + res*res2%9) % 9;
			}
			return ans;
		}
};
