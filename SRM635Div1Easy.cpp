#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define eps 1e-9
typedef long long ll;
class SimilarRatingGraph {
	public:
		double getDis (int x1, int y1, int x2, int y2) {
			double res = (double)sqrt((double)(x1 - x2) * (double)(x1 - x2) + (double)(y1 - y2) * (double)(y1 - y2));
			return res;
		}
		double maxLength (vector<int> date, vector<int> rating) {
			int n = date.size();
			double ans = 0.0;
			double tmp1 = 0.0;
			double tmp2 = 0.0;
			for (int i = 0; i < n; ++i) {
				for (int j = i + 1; j < n; ++j) {
					tmp1 = 0.0;
					tmp2 = 0.0;
					for (int k = 1; i + k < n && j + k < n; ++k) {
						ll r1 = (ll)(date[i + k] - date[i + k - 1]) * (ll)(rating[j + k] - rating[j + k - 1]);
						ll r2 = (ll)(rating[i + k] - rating[i + k - 1]) * (ll)(date[j + k] - date[j + k - 1]);
						if (r1 != r2) {
							break;
						}
						if (k > 1) {
							ll x = (ll)(date[i + 1] - date[i]) * (ll)(date[j + k] - date[j + k - 1]);
							ll y = (ll)(date[j + 1] - date[j]) * (ll)(date[i + k] - date[i + k - 1]);						
							if (x != y) {
								break;
							}
						}
						tmp1 += getDis(date[i + k - 1], rating[i + k - 1], date[i + k], rating[i + k]);
						tmp2 += getDis(date[j + k - 1], rating[j + k - 1], date[j + k], rating[j + k]);
					}
					if (tmp1 + eps > ans) {
						ans = tmp1;
					}
					if (tmp2 + eps > ans) {
						ans = tmp2;
					}
				}
			}
			return ans;
		}
};
