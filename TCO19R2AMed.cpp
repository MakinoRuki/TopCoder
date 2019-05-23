// 给定一个数x，它的# of byes是最低位1和最高位1之间0的个数+1。 因此暴力+=lowbit(x)即可。
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class Byes {
	public:
		int calc(ll x) {
			int cnt = 0;
			while(x > 1) {
				if (x & 1) {
					cnt++;
					x /= 2;
					x++;
				} else {
					x /= 2;
				}
			}
			return cnt;
		}
		ll lowbit(ll x) {
			return x & (-x);
		}
		ll getNumberOfPlayers(ll lb, int byes) {
			while(true) {
				int nbys = calc(lb);
				if (nbys == byes) {
					return lb;
				}
				if (nbys < byes) {
					if (lb % 2 == 0 || lb == 1) {
						lb++;
					} else {
						lb--;
						lb += lowbit(lb);
					}
				} else {
					lb += lowbit(lb);
				}
			}
			return lb;
		}
};
