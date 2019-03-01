#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class NarrowPassage2 {
	public:
		int n;
		ll calc (vector<int> & size, int maxSizeSum) {
			if (size.size() < 2) {
				return 1;
			}
			int idx = 0, maxVal = size[0];
			for (int i = 0; i < size.size(); ++i) {
				if (size[i] > maxVal) {
					maxVal = size[i];
					idx = i;
				}
			}
			cerr<<maxVal<<endl;
			vector<int> ls, rs;
			ll res = 1LL;
			ll m = size.size();
			for (int i = 0; i < size.size(); ++i) {
				if (i == idx) continue;
				if (size[i] + size[idx] <= maxSizeSum) {
					res = res * m % mod;
					m--;
				} else {
					if (i < idx) {
						ls.push_back(size[i]);
					} else  if (i > idx) {
						rs.push_back(size[i]);
					}
				}
			}
			return res * (calc(ls, maxSizeSum) * calc(rs, maxSizeSum) % mod) % mod;
		}
		int count (vector<int> size, int maxSizeSum) {
			n = size.size();
			return calc(size, maxSizeSum);
		}
};
