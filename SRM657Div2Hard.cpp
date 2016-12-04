#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class PolynomialRemainder {
	public:
		bool check (int a, int b, int c, int x, ll pw) {
			ll ans = (ll)a % pw;
			ans = ans * (ll)x % pw * (ll)x % pw;
			ans = (ans + (ll)b % pw * (ll)x % pw) % pw;
			ans = (ans + (ll)c) % pw;
			return (ans == 0);
		}
		int findRoot (int a, int b, int c) {
			ll pw2 = 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2;
			ll pw5 = 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5;
			int i;
			for (i = 0; i < pw5; ++i) {
				if (check(a, b, c, i, pw5)) {
					break;
				}
			}
			if (i >= pw5) return -1;
			for (int j = i; j < 1000000000; j += pw5) {
				if (check(a, b, c, j, pw2)) return j;
			}
			return -1;
		}
};
