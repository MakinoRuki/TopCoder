#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define SZ 100003
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class TreeWalker {
	public:
		vector<int> edges[SZ];
		ll ans = 0LL;
		ll pw2, pwn;
		ll getPw (ll pw) {
			ll res = 1LL;
			ll num = 2LL;
			while (pw) {
				if (pw & 1) {
					res = res * num % mod;
				}
				num = num * num % mod;
				pw /= 2;
			}
			return res;
		}
		ll dfs (int cur, int par) {
			ll accu = 1LL;
			for (int i = 0; i < edges[cur].size(); ++i) {
				int nxt = edges[cur][i];
				if (nxt == par) continue;
	//			cout<<cur<<" "<<nxt<<endl;
				ll mul = dfs(nxt, cur) * pw2 % mod;
		//		cout<<"mul="<<mul<<endl;
				ans = (ans + mul * accu * 2LL % mod) % mod;
			//	cout<<"ans="<<ans<<endl;
				accu = (accu + mul) % mod;
			}
			return accu;
		}
		int calc (int N, int A0, int B, int C, int MOD) {
			for (int i = 1; i < N; ++i) {
				int j = A0 % i;
				edges[i].push_back(j);
				edges[j].push_back(i);
				A0 = ((ll)B * (ll)A0 + C) % MOD;
			}
			pw2 = getPw(mod - 2);
	//		cout<<"pw2="<<pw2<<endl;
			pwn = getPw(N - 1);
			dfs(0, -1);
			return pwn * ans % mod;
		}
};
