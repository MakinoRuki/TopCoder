// 因为不能直接算的唯一问题是：当算第n次的时候不知道第n-1次是不是已经在你要看的位置上(比如b)。
// 因此只需要记下第i次是否在b上。

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 100005
using namespace std;
class RandomSwaps {
	public:
		double pr[N][2];
		double getProbability(int al, int sc, int a, int b) {
			for (int i = 0; i <= sc; ++i) {
				for (int j = 0; j < 2; ++j) {
					pr[i][j] = 0.0;
				}
			}
			if (a == b) {
				pr[0][1] = 1.0;
			} else {
				pr[0][0] = 1.0;
			}
			for (int i = 0; i < sc; ++i) {
				pr[i+1][1] += pr[i][0] * 2.0/(double)(al*(al-1));
				pr[i+1][0] += pr[i][0] * (1.0 - 2.0/(double)(al*(al-1)));
				pr[i+1][0] += pr[i][1] * 2.0/(double)al;
				pr[i+1][1] += pr[i][1] * (1.0 - 2.0/(double)al);
			}
			return pr[sc][1];
		}
};
