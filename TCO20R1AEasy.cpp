#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class AveragePrice {
	public:
		double nonDuplicatedAverage(vector<int> ps) {
			sort(ps.begin(), ps.end());
			double a = 0.0;
			double b = 0.0;
			int n = ps.size();
			for (int i = 0; i < n; ++i) {
				if (i ==0 ) {
					a+=(double)ps[i];
					b+=1.0;
				} else {
					if (ps[i] != ps[i-1]) {
						a += (double)ps[i];
						b+=1.0;
					}
				}
			}
			return a/b;
		}
};
