#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class SortArray {
	public:
		int m;
		vector<int> verify(int n, vector<int> cs) {
			m = cs.size();
			for (int i = 0; i < (1<<n); ++i) {
				vector<int> bits(n, 0);
				for (int j = 0; j < n; ++j) {
					if (!((1<<j) & i)) bits[j] = 1;
				}
				for (auto c : cs) {
					vector<int> ns(2, 0);
					for (int j = 0; j < n; ++j) {
						if ((1<<j) & c) ns[bits[j]]++;
					}
					for (int j = 0; j < n; ++j) {
						if ((1<<j) & c) {
							if (ns[0]) {
								ns[0]--;
								bits[j] = 0;
							} else {
								bits[j] = 1;
							}
						}
					}
				}
				int bs = __builtin_popcount(i);
				for (int j = 0; j < bs; ++j) {
					if (bits[j]) {
						vector<int> ans;
						ans.clear();
						int a = 0;
						int b = bs;
						for (int j = 0; j < n; ++j) {
							if ((1<<j) & i) {
								ans.push_back(a++);
							} else {
								ans.push_back(b++);
							}
						}
						return ans;
					}
				}
			}
			return {};
		}
};
