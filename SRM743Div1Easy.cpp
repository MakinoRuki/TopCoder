#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef long long ll;
class MaximizingGCD {
	public:
		int n;
		bool check(vector<int>& a, int g) {
			unordered_map<int, int> cnt;
			cnt.clear();
			for (int i = 0; i < a.size(); ++i) {
				int r1 = a[i] % g;
				int r2 = (g - r1) % g;
				if (cnt.find(r2) == cnt.end()) cnt[r1]++;
				else {
					cnt[r2]--;
					if (cnt[r2] == 0) cnt.erase(r2);
				}
			}
			return (cnt.size() == 0);
		}
		int maximumGCDPairing(vector <int> A) {
			n = A.size();
			int ans = 1;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (i == j) continue;
					int v = A[i] + A[j];
					for (ll g = 1; g * g <= v; ++g) {
						if (v % g != 0) continue;
						vector<int> a;
						a.clear();
						for (int k = 0; k < n; ++k) {
							if (k != i && k != j) a.push_back(A[k]);
						}
						if (g > ans && check(a, g)) ans = g;
						if (g != v / g && v / g > ans && check(a, v / g)) ans = v / g;
					}
				}
			}
			return ans;
		}
};
