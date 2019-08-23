// {{41, 46, 33, 26, 21, 19, 32, 25, 21, 18, 25, 24, 50, 25, 35, 43, 48, 18, 27, 26, 31, 24, 26, 35, 47, 48, 46, 36, 43, 45, 28, 17, 44, 48, 48, 43, 38, 40, 36, 36, 42, 41, 19, 50, 34, 26, 46, 42, 23}, 27}
// {3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 50, 48, 46, 44, 42, 40, 38, 36, 34, 32, 30, 28, 26, 24, 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 49, 1}, 48}
// Tag : 杂
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class FixedPointReversals {
	public:
		int n;
		vector<int> sort(vector<int> a, int fixed) {
			n = a.size();
			vector<int> b(a.begin(), a.end());
			std::sort(b.begin(), b.end());
			vector<int> ans;
			ans.clear();
			if (b[fixed] != a[fixed]) return {-1};
			if (fixed <= n - 1 - fixed) {
				for (int i = 0; i < n; ++i) {
					if (a[i] == b[i]) continue;
					int j;
					int ok = -1;
					for (j = i + 1; j < n; ++j) {
						if (a[j] == b[i]) {
							if (j < fixed || i > fixed) {
								ans.push_back(i);
								ans.push_back(j+1);
								reverse(a.begin() + i, a.begin() + j + 1);
								ok = 1;
								break;
							} else {
								int v = a[fixed];
								reverse(a.begin() + i, a.begin() + j + 1);
								if (v == a[fixed]) {
									ans.push_back(i);
									ans.push_back(j+1);
									ok = 1;
									break;
								}
								reverse(a.begin() + i, a.begin() + j + 1);
								// if (j - fixed == fixed - i) {
								// 	ans.push_back(i);
								// 	ans.push_back(j+1);
								// 	reverse(a.begin() + i, a.begin() + j + 1);
								// 	ok = 1;
								// 	break;
								// }
							}
						}
					}
					if (ok == 1) continue;
					int k;
					for (k = i + 1; k < n; ++k) {
						if (k == fixed) continue;
						if (a[k] == b[i]) {
							break;
						}
					}
					if (k >= n) return {-1};
					for (j = fixed+1; j < n; ++j) {
						int v = a[fixed];
						reverse(a.begin() + i, a.begin() + j + 1);
						if (v == a[fixed]) {
							reverse(a.begin() + i, a.begin() + j + 1);
							break;
						}
						reverse(a.begin() + i, a.begin() + j + 1);
					}
					if (j >= n) return {-1};
					if (k > j) {
						ans.push_back(j);
						ans.push_back(k+1);
						reverse(a.begin() + j, a.begin() + k + 1);
					} else {
						ans.push_back(k);
						ans.push_back(j+1);
						reverse(a.begin() + k, a.begin() + j + 1);
					}
					ans.push_back(i);
					ans.push_back(j+1);
					reverse(a.begin() + i, a.begin() + j + 1);
				}
			} else {
				for (int i = n-1; i >= 0; --i) {
					if (a[i] == b[i]) continue;
					int j;
					int ok = -1;
					for (j = i - 1; j >= 0; --j) {
						if (a[j] == b[i]) {
							if (i < fixed || j > fixed) {
								ans.push_back(j);
								ans.push_back(i+1);
								reverse(a.begin() + j, a.begin() + i + 1);
								ok = 1;
								break;
							} else {
								int v = a[fixed];
								reverse(a.begin() + j, a.begin() + i + 1);
								if (v == a[fixed]) {
									ans.push_back(j);
									ans.push_back(i+1);
									ok = 1;
									break;
								}
								reverse(a.begin() + j, a.begin() + i + 1);
								// if (i - fixed == fixed - j) {
								// 	ans.push_back(j);
								// 	ans.push_back(i+1);
								// 	reverse(a.begin() + j, a.begin() + i + 1);
								// 	ok = 1;
								// 	break;
								// }
							}
						}
					}
					if (ok == 1) continue;
					int k;
					for (k = i - 1; k >= 0; --k) {
						if (k == fixed) continue;
						if (a[k] == b[i]) {
							break;
						}
					}
					for (j = fixed - 1; j >= 0; --j) {
						int v = a[fixed];
						reverse(a.begin() + j, a.begin() + i + 1);
						if (v == a[fixed]) {
							reverse(a.begin() + j, a.begin() + i + 1);
							break;
						}
						reverse(a.begin() + j, a.begin() + i + 1);
					}
					if (k > j) {
						ans.push_back(j);
						ans.push_back(k+1);
						reverse(a.begin() + j, a.begin() + k + 1);
					} else {
						ans.push_back(k);
						ans.push_back(j+1);
						reverse(a.begin() + k, a.begin() + j + 1);
					}
					ans.push_back(j);
					ans.push_back(i+1);
					reverse(a.begin() + j, a.begin() + i + 1);
				}
			}
			return ans;
		}
};
