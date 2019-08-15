// Tag : Math

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
class PerfectSquare {
	public:
		int nn;
		int n, m;
		ll getpw(int a, int b) {
			ll res = 1;
			while(b) {
				if (b & 1) res = res * a % mod;
				a = a * a % mod;
				b /= 2;
			}
			return res;
		}
		int getrank(vector<vector<int> >& a, vector<int>& b, int p) {
			bool used[nn];
			memset(used, false, sizeof(used));
			int ans = 0;
			for (int j = 0; j < nn; ++j) {
				int i;
				for (i = 0; i < m; ++i) {
					if (a[i][j] != 0 && !used[i]) {
						used[i] = true;
						ans++;
						break;
					}
				}
				if (i >m) continue;
				for (int k = 0; k < m; ++k) {
					int cf = 0;
					while((a[i][j] * cf + a[k][j]) % p != 0) {
						cf++;
					}
					for (int t = j; t < nn; ++t) {
						a[k][t] = (a[k][t] + cf * a[i][t]) % p;
					}
					b[k] = (b[k] + cf * b[i]) % p;
				}
			}
			for (int i = 0; i < m; ++i) {
				if (!used[i] && b[i]) {
					return -1;
				}
			}
			return ans;
		}
		int ways(vector<int> x) {
			nn = x.size();
			n = (int)sqrt(nn);
			set<int> primes;
			map<int, int> prime;
			for (int i = 0; i < nn; ++i) {
				int xi = x[i];
				for (int p = 2; p * p <= xi; ++p) {
					int cnt = 0;
					while(xi % p == 0) {
						xi /= p;
						cnt++;
					}
					if (cnt) {
						primes.insert(p);
						prime[i][p] = cnt;
					}
				}
				if (xi > 1) {
					primes.insert(p);
					prime[i][p] = 1;
				}
			}
			vector<vector<int> > a;
			vector<int> b;
			for (int i = 0; i < n; ++i) {
				vector<int> aa(nn, 0);
				for (int j = 0; j < n; ++j) {
					aa[i * n + j] = 1;
				}
				a.push_back(aa);
				b.push_back(1);
			}
			for (int j = 0; j < n; ++j) {
				vector<int> aa(nn, 0);
				for (int i = 0; i < n; ++i) {
					aa[i * n + j] = 1;
				}
				a.push_back(aa);
				b.push_back(1);
			}
			for (auto p : primes) {
				vector<int> aa(nn, 0);
				for (int i = 0; i < nn; ++i) {
					if (prime[i][p] % 2) {
						aa[i] = 1;
					}
				}
				a.push_back(aa);
				b.push_back(0);
			}
			m = a.size();
			int r = getrank(a, b, 2);
			return r == -1 ? 0 : getpw(2, nn - r);
		}
};
