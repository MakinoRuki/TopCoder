#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
class TheKingsFactorization {
	public:
		int n;
		vector<ll> getVector(ll N, vector<ll> primes) {
			n = primes.size();
			vector<ll> ans;
			ans.clear();
			for (int i = 0; i < n; ++i) {
				if (i == 0) {
					ans.push_back(primes[i]);
					N /= primes[i];
				} else {
					N /= primes[i];
					bool ok = false;
					for (ll j = 2; j * j <= N; ++j) {
						if (N % j == 0) {
							ok = true;
							N /= j;
							ans.push_back(j);
							break;
						}
					}
					if (N > 1 && !ok) {
						ans.push_back(N);
						N /= N;
					}
					ans.push_back(primes[i]);
				}
			}
			if (N > 1) {
				ans.push_back(N);
			}
			return ans;
		}
};
