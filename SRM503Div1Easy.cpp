#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1000005
using namespace std;
typedef long long ll;
class ToastXToast {
	public:
		int bake(vector<int> ut, vector<int> ot) {
			sort(ut.begin(), ut.end());
			sort(ot.begin(), ot.end());
			if (ut[0] >= ot[0]) return -1;
			int i = 0;
			while(i < ut.size() && ut[i] < ot[0]) i++;
			if (i >= ut.size()) return 1;
			if (ot.back() > ut.back()) {
				return 2;
			}
			return -1;
		}
};
