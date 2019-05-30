#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 100010
using namespace std;
class EllysThreePrimes {
	public:
		int n;
		bool isprime[N];
		vector<int> primes;
		vector<int> getPrimes(vector <int> sums) {
			n = sums.size();
			primes.clear();
			memset(isprime, true, sizeof(isprime));
			for (int i = 2; i * i <= 100000; ++i) {
				if (isprime[i]) {
					for (int j = 2 * i; j <= 100000; j += i) {
						isprime[j] = false;
					}
				}
			}
			for (int i = 10000; i < 100000; ++i) {
				if (isprime[i]) {
					primes.push_back(i);
				}
			}
			vector<int> pw = {1, 10, 100, 1000, 10000};
			//cout<<primes.size()<<endl;
			for (int i = 0; i < primes.size(); ++i) {
				for (int j = 0; j < primes.size(); ++j) {
					if (i == j) continue;
					int p1 = primes[i];
					int p2 = primes[j];
					int p3 = 0;
					int k;
					for (k = 0; k < 5; ++k) {
						int d = sums[k] - p1 % 10 - p2 % 10;
						if (d < 0 || d > 9) break;
						p3 += d * pw[k];
						p1 /= 10;
						p2 /= 10;
					} 
					if (k < 5) continue;
					if (primes[i] == 20533 && primes[j] == 44987) cout<<p3<<endl;
					if (p3 < 10000 || p3 >= 100000) continue;
					if (isprime[p3] && p3 != primes[i] && p3 != primes[j]) {
						return {primes[i], primes[j], p3};
					}
				}
			}
			return {};
		}
};
