#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class MinDegreeSubgraph {
	public:
		string exists(int n, ll m, int k) {
			ll N = n, M = m, K = k;
			if (K == 0) return "ALL";
			if (K > N) return "NONE";
			if (M < K * (K + 1) / 2) return "NONE";
			if (M > K * (K - 1) / 2 + (N - K)*(K - 1)) return "ALL";
			return "SOME";
		}
};
