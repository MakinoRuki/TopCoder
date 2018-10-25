#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class LCMSet {
public:
	int n, m;
	bool check(vector<int>& a, int b) {
		ll res = 1LL;
		for (int i = 0; i < a.size(); ++i) {
			if (b % a[i] == 0) {
				ll nres = a[i] * res / __gcd(a[i], res);
				res = nres;
			}
		}
		return (res == b);
	}
	string equal(vector<int> A, vector<int> B) {
		n = A.size();
		m = B.size();
		for (int i = 0; i < n; ++i) {
			if (!check(A[i], B)) return "Not equal";
		}
		for (int i = 0; i < m; ++i) {
			if (!check(B[i], A)) return "Not equal";
		}
		return "Equal";
	}
};
