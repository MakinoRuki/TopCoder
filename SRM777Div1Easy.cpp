#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
//#define dv 7
using namespace std;
class PreviousOccurrence {
	public:
		int o1[8000005];
		int o2[8000005];
	//	unordered_map<int, int>o1;
	//	unordered_map<int, int>o2;
		int fo[7002];
		int findValue(int dv, int query) {
			if (dv == 1) {
				if (query != 0 && query != 1) return -1;
				if (query == 0) return 0;
				if (query == 1) return 1;
			} else {
				memset(o1, -1, sizeof(o1));
				memset(o2, -1, sizeof(o2));
				//o1.clear();
			//	o2.clear();
				memset(fo, -1, sizeof(fo));
				o1[0] = 0;
				fo[0] = 0;
				int p = 0;
				for (int i = 1; i <= 8000000; ++i) {
					int v = dv;
				//	if (o1.find(p) != o1.end() && o2.find(p) != o2.end()) {
					if (o1[p] >= 0 && o2[p]>=0) {
						v = abs(o1[p] - o2[p]);
					}
					p = v;
				//	if (o1.find(p) == o1.end()) {
					if (o1[p] < 0) {
				//cout<<p<<" "<<i<<endl;
						if (p <= 7000) fo[p] = i;
						o1[p] = i;
					} else if (o2[p] < 0) {
						o2[p] = i;
					} else {
						o1[p] = o2[p];
						o2[p] = i;
					}
				}
				return fo[query];
			}
			return -1;
		}
};
