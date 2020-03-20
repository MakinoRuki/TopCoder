#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll mod = 786433LL;
class RandomPartition {
	public:
		ll getpw(ll a, ll b) {
			ll res = 1LL;
			while(b) {
				if (b&1) res= res*a%mod;
				a = a*a%mod;
				b/=2;
			}
			return res;
		}
		int expectedSum(vector <int> nums, int n, int m, int b1, int b2) {
			vector<int> h(2*n);a
			for (int i = 0; i < nums.size(); ++i) {
				h[i] = nums[i];
			}
			for (int i = nums.size(); i < 2*n; ++i) {
				h[i] = ((ll)h[i-1]*(ll)b1 + (ll)h[i-2]*(ll)b2) % (ll)m;
			}
			sort(h.begin(), h.end());
			ll sum = 0LL;
			for (int i = n; i < 2 * n; ++i) {
				sum = (sum + h[i]) % mod;
			}
			for (int i = 0; i < n; ++i) {
				sum = (sum - h[i] + mod) % mod;
			}
			sum = sum * getpw(n, mod-2) % mod;
			return sum;
		}
};
