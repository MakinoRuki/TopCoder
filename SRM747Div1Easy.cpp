#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class MostFrequentLastDigit {
	public:
		vector<int> ans;
		vector <int> generate(int n, int d) {
			int d1, d2;
			ans.clear();
			if (d % 2) {
				if (d <= 1) d += 10;
				d1 = d / 2;
				d2 = d - d1;
				int a1 = d1, a2 = d2;
				for (int i = 0; i < n / 2; ++i) {
					ans.push_back(a1);
					ans.push_back(a2);
					a1 += 10;
					a2 += 10;
				}
				if (n % 2) {
					ans.push_back(a1);
				}
			} else {
				if (d <= 1) d += 10;
				d1 = d / 2;
				d2 = d - d1;
				int a = d1;
				for (int i = 0; i < n; ++i) {
					ans.push_back(a);
					a += 10;
				}
			}
			return ans;
		}
};
