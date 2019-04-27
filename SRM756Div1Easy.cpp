#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class NewBanknote {
	public:
		vector<int> ans;
		int n;
		vector<int> fewestPieces(int nb, vector <int> atp) {
			ans.clear();
			n = atp.size();
			vector<int> c = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000};
			if (nb >= 50000) {
				for (int i = 0; i < n; ++i) {
					int res = 2*1000000000+1;
					for (int j = 0; j <= atp[i]/nb; ++j) {
						int sum = j;
						int x = atp[i] - j * nb;
						for (int k = c.size() - 1; k >= 0; --k) {
							sum += x / c[k];
							x %= c[k];
						}
						res = min(res, sum);
					}
					ans.push_back(res);
				}
			} else {
				for (int i = 0; i < n; ++i) {
					int res = 2000000000+1;
					for (int j = 0; j <= min(50000, atp[i]/nb); ++j) {
						int sum = j;
						int x = atp[i] - j*nb;
						for (int k = c.size() - 1; k >= 0; --k) {
							sum += x/c[k];
							x %= c[k];
						}
						res = min(res, sum);
					}
					ans.push_back(res);
				}
			}
			return ans;
		}
};
