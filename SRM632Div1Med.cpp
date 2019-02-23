#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 2002
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class CandyCupRunningCompetition {
	public:
		int f[N];
		int m;
		int find(int x) {
			return x == f[x] ? x : (f[x] = find(f[x]));
		}
		ll getpw(ll a, ll b) {
			ll res = 1LL;
			while(b) {
				if (b & 1) res = res * a % mod;
				a = a * a % mod;
				b /= 2;
			}
			return res;
		}
		int findMaximum(int n, vector <int> A, vector <int> B) {
			m = A.size();
			for (int i = 0; i < n; ++i) {
				f[i] = i;
			} 
			ll ans = 0LL;
			for (int i = m - 1; i >= 0; --i) {
				if ((find(A[i]) == find(0) && find(B[i]) == find(n - 1)) || (find(B[i]) == find(0) && find(A[i]) == find(n - 1))) {
					ans = (ans + getpw(3LL, i)) % mod;
					cout<<i<<endl;
				} else {
					f[find(A[i])] = find(B[i]);
				}
			}
			return ans;
		}
};
