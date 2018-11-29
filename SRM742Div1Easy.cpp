#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define eps 1e-9
using namespace std;
typedef long long ll;
class ResistorFactory {
	public:
		vector<int> ans;
		void updateans(vector<int>& idx, int & tot, int det, int & tott) {
			if (idx.size() <= 0) return;
			if (idx.size() == 1) {
				tott = idx[0] + det;
				return;
			}
			for (int i = 1; i < idx.size(); ++i) {
				if (i == 1) {
					ans.push_back((idx[0] == 0) ? 0 : (det + idx[0]));
					ans.push_back(idx[1] + det);
					ans.push_back(0);
				} else {
					ans.push_back(tot);
					ans.push_back(idx[i] + det);
					ans.push_back(0);
				}
				tot++;
			}
			tott = tot;
		}
		vector <int> construct(ll nanoOhms) {
			vector<int> idx1;
			vector<int> idx2;
			idx1.clear();
			idx2.clear();
			ans.clear();
			ll nn1 = nanoOhms/1000000000LL;
			double nn2 = (double)(nanoOhms % 1000000000LL) / 1000000000.0;
			int idx = 0;
			while(nn1) {
				if (nn1 % 2) idx1.push_back(idx);
				nn1 /= 2;
				idx++;
			}
			idx = 1;
			double res = 0.5;
			//cout<<nn2<<endl;
			while(fabs(nn2) >= eps) {
			//	cout<<nn2<<endl;
				if (nn2 > res) {
				//	cout<<res<<" "<<idx<<endl;
					nn2 -= res;
					idx2.push_back(idx);
				}
				res *= 0.5;
				idx++;
			}
			int tot = 0;
			int tot1 = -1;
			int tot2 = -1;
			idx = 0;
			while(idx1.size() && idx < idx1.back()) {
				ans.push_back(idx);
				ans.push_back(idx);
				ans.push_back(0);
				idx++;
				tot++;
			}
			updateans(idx1, tot, 0, tot1);
			idx = 0;
			while(idx2.size() && idx < idx2.back()) {
				if (idx == 0) {
					ans.push_back(0);
					ans.push_back(0);
					ans.push_back(1);
				} else {
					ans.push_back(tot);
					ans.push_back(tot);
					ans.push_back(1);
				}
				idx++;
				tot++;
			}
			updateans(idx2, tot, (tot1 > 0 ? tot1 : 0), tot2);
			if (tot1 >= 0 && tot2 >= 0) {
				ans.push_back(tot1);
				ans.push_back(tot2);
				ans.push_back(0);
			}
			return ans;
		}
};
