#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 3002
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
int cnt[N], cnt2[N];
int status[N];
int in[10], out[10];
ll res1[9][N], res2[9][N];
class MappingABC {
	public:
		int n;
		int countStrings (vector<int> t) {
			ll ans = 0LL;
			n = t.size();
			memset(cnt, 0, sizeof(cnt));
			for (int i = 0; i < n; ++i) {
				cnt[t[i]]++;
			}
			for (int i = 0; i < 8; ++i) {
				res1[i][0] = res2[i][0] = 1LL;
				for (int j = 1; j <= n; ++j) {
					res1[i][j] = res1[i][j - 1] * __builtin_popcount(i) % mod;
					res2[i][j] = res2[i][j - 1] * __builtin_popcount(i & 5) % mod;
 				}
			}
			for (int a = 0; a < n; ++a) {
			//	cout<<"a="<<a<<endl;
				memset(status, 0, sizeof(status));
				memset(in, 0, sizeof(in));
				memset(out, 0, sizeof(out));
				for (int i = 0; i < a; ++i) {
					status[t[i]] = 6;
				}
				if (status[t[a]] == 6) continue;
				status[t[a]] = 1;
				for (int i = 1; i <= 3000; ++i) {
					cnt2[i] = cnt[i];
					if (cnt[i] && !status[i]) status[i] = 7;
				}
				for (int i = 0; i <= a; ++i) {
					cnt2[t[i]]--;
				}
			//	if (a==1)cout<<cnt[1]<<" "<<cnt2[1]<<" "<<status[1]<<endl;
				for (int i = 1; i <= 3000; ++i) {
					if (cnt[i] && !cnt2[i]) {
						out[status[i]]++;
					} else if (cnt[i] && cnt2[i]) {
						in[status[i]]++;
					}	 
				}
			//	cout<<md<<" "<<mdb<<endl;
				for (int c = n - 1; c >= a + 2; --c) {
					in[status[t[c]]]--;
					ll sumi1 = 1LL, sumi2 = 1LL;
					ll sumo = 1LL;
					if (status[t[c]] & 4) {
						for (int i = 0; i < 8; ++i) {
							sumi1 = sumi1 * res1[i][in[i]] % mod;
							sumi2 = sumi2 * res2[i][in[i]] % mod;
							sumo = sumo * res1[i][out[i]] % mod;
						}
						ans = (ans + (sumi1 - sumi2) * sumo % mod) % mod;
					}
					status[t[c]] &= 3;
					cnt2[t[c]]--;
					if (!cnt2[t[c]]) out[status[t[c]]]++;
					else in[status[t[c]]]++;
				}
			//	cout<<a<<" "<<ans<<endl;
			}
			return ans;
		}
};
