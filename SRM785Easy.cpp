#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class EllysPalMul {
	public:
		int getMin(int x) {
			ll res = 1000000001;
			for (ll i = 1; i <= 20000000LL; ++i) {
				ll z = i;
				ll z2 = i;
				while(z2) {
					z = z*10 + z2%10;
					z2 /= 10;
				}
				if (z % x == 0 && z/x >= 1 && z/x <= 1000000000) {
					res = min(res, z/x);
				}
				z = i;
				z2 = i/10;
				//if (z2) {
					while(z2) {
						z = z*10 + z2%10;
						z2 /= 10;
					}
					if (z%x == 0 && z/x >=1 && z/x<=1000000000) {
						res=min(res, z/x);
					}
				//}
			}
			if (res > 1000000000) return -1;
			return res;
		}
};
