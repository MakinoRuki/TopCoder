#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class GraphAndPairs {
	public:
		vector<int> ans;
		vector<int> construct (int d, int k) {
			ans.clear();
			int cur = 0;
			if (d <= 2) {
				while (k) {
					for (int i = 1000; i >= 1; --i) {
						if (i * (i - 1) / 2 <= k) {
							for (int j = 1; j <= i; ++j) {
								ans.push_back(cur);
								ans.push_back(cur + j);
							}
							cur += i + 1;
							k -= i * (i - 1) / 2;
							break;
						}
					}
				}
			} else {
				while (k) {
					for (int i = 1; i < d - 1; ++i) {
						ans.push_back(cur + i - 1);
						ans.push_back(cur + i);
					}
					int l = cur, r = cur + d - 2;
					cur += d - 1;
					for (int i = 1000; i >= 1; --i) {
						if (i * i <= k) {
							for (int j = 1; j <= i; ++j) {
								ans.push_back(l);
								ans.push_back(cur + j - 1);
							}
							for (int j = 1; j <= i; ++j) {
								ans.push_back(r);
								ans.push_back(cur + i + j - 1);
							}
							k -= i * i;
							cur += 2 * i;
							break;
						}
						if (i * (i - 1) <= k) {
							for (int j = 1; j <= i; ++j) {
								ans.push_back(l);
								ans.push_back(cur + j - 1);
							}
							for (int j = 1; j < i; ++j) {
								ans.push_back(r);
								ans.push_back(cur + i + j - 1);
							}
							k -= i * (i - 1);
							cur += 2 * i - 1;
							break;
						}
					}
				}
			}
			reverse(ans.begin(), ans.end());
			ans.push_back(cur);
			reverse(ans.begin(), ans.end());
			return ans;
		}
};
