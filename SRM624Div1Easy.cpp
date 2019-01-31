#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 4002
using namespace std;
class BuildingHeights {
public:
	int n;
	int res[N];
	int minimum(vector<int> heights) {
		n = heights.size();
		sort(heights.begin(), heights.end());
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int sum = 0;
			for (int j = i; j >= 0; --j) {
				res[i - j + 1] = min(res[i - j + 1], (sum += heights[i] - heights[j]));
			}
		}
		for (int i = 1; i <= n; ++i) {
			ans ^= res[i];
		}
	}
}
