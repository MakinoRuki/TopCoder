#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class ArpaAsDevotee {
	public:
		vector<string> solve(int n, int q, vector<int> a, vector<int> ls, vector<int> t) {
			vector<pair<int, int>> rk;
			for (int i = 0; i < n; ++i) {
				rk.push_back(make_pair(a[i], ls[i]));
			}
			sort(rk.begin(), rk.end());
			for (int i = 0; i < n; ++i) {
				//cout<<i<<" "<<n<<" "<<rk[i].first<<" "<<rk[i].second<<endl;
				if (i == 0) {
					if (rk[i].second > rk[i].first) return {};
				} else {
					if (rk[i].first == rk[i-1].first) {
						if (rk[i].second != rk[i-1].second) return {};
					} else {
						if (rk[i].second != rk[i-1].second && rk[i].second <= rk[i-1].first) return {};
					}
				}
			}
			//cout<<"???"<<endl;
			vector<string> ans(q, "");
			vector<pair<int, int>> qs;
			for (int i = 0; i < q; ++i) {
				qs.push_back(make_pair(t[i], i));
			}
			sort(qs.begin(), qs.end());
			int j = 0;
			for (int i = 0; i < n; ++i) {
				while(j < q && qs[j].first < rk[i].second) {
					ans[qs[j].second] = "Not Sure";
					j++;
				}
				while(j < q && qs[j].first == rk[i].second) {
					ans[qs[j].second] = "Yes";
					j++;
				}
				while(j < q && qs[j].first <= rk[i].first) {
					ans[qs[j].second] = "No";
					j++;
				}
			}
			while(j < q) {
				ans[qs[j].second] = "Not Sure";
				j++;
			}
			return ans;
		}
};
