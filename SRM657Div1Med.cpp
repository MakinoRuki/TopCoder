#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 10005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class PolynomialGCD {
	public:
		int n;
		bool isPrime (int x) {
			for (int i = 2; i * i <= x; ++i) {
				if (x % i == 0) return false;
			}
			return true;
		}
		ll myPow (ll p, int num) {
			ll res = 1LL;
			while (num) {
				if (num & 1) res = (res * (ll)p) % mod;
				p = p * p % mod;
				num /= 2;
			}
			return res;
		}
		ll getPow (string coef, int p) {
			int sz = coef.size();
			if (sz < p) return 0LL;
			ll sum = 0LL;
			ll res = mod;
			for (int i = 0; i < p; ++i) {
				string nxt = "";
				sum = 0LL;
				for (int j = i; j < sz; j += p) {
					sum += coef[j] - '0';
					nxt += coef.substr(j, 1);
				} 
				sum += getPow(nxt, p);
				res = min(res, sum);
			}
			return res;
		}
		int gcd (string s) {
			n = s.size();
			ll ans = 1LL;
			for (int i = 2; i <= n; ++i) {
				if (isPrime(i)) {
					ll pw = getPow(s, i);
					ans = ans * myPow(i, pw) % mod;
				}
			}
			return (int)ans;
		}
};
