#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class MaximumBipartiteMatchingProblem {
	public:
		ll solve(int n1, int n2, int ans, int d) {
			if (n1 > n2) swap(n1, n2);
			if (ans < min(2 * d, n1)) return -1;
			if (ans == n1) return (ll)n1 * (ll)n2;
			ll res = (ll)(ans - d) * (ll)n2;
			res += (ll)(n1 - ans + d) * (ll)d;
			return res;
		}
};
