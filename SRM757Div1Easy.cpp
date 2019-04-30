#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class CentipedeSocks {
	public:
		int n;
		int fewestSocks(int C, int F, vector <int> sc) {
			 n = sc.size();
			 int tot = 0;
			 for (int i = 0; i < n; ++i) {
			 	tot += sc[i];
			 }
			 int l = 0, r = tot + 1;
			 while(l < r) {
			 	int m = (l +r)/2;
			 	int cnt = 0;
			 	int tm = m;
			 	vector<int> tsc(sc.begin(), sc.end());
			 	for (int i = 0; i< C; ++i) {
			 		int tmp = 0;
			 		int maxv = 0;
			 		int idx = -1;
			 		for (int j = 0; j < n; ++j) {
			 			tmp += min(tsc[j], F-1);
			 			if (tsc[j] > maxv) {
			 				maxv = tsc[j];
			 				idx = j;
			 			}
			 		}
			 		if (tmp < tm) {
			 			if (maxv >= F && idx != -1) {
			 				tsc[idx] -= F;
			 				cnt++;
			 				tm -= F;
			 			} else {
			 				break;
			 			}
			 		} else {
			 			break;
			 		}
			 	}
			 	if (cnt >= C) {
			 		r = m;
			 	} else {
			 		l = m + 1;
			 	}
			 }
			 if (r <= tot) return r;
			 else return -1;
		}
};
