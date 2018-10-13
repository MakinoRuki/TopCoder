#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
class PowerOfThree {
public:
	int pwx[N], pwy[N];
	void check(int * pw, int& mxy) {
		int add = 0;
		for (int i = 0; i < 50; ++i) {
			pw[i] += add;
			add = 0;
			if (pw[i] == 2) {
				pw[i] = -1;
				add += 1;
			} else if (pw[i] == 3) {
				pw[i] = 0;
				add += 1;
			}
			if (pw[i] != 0) mxy = max(mxy, i);
		}
	}
	string ableToGet(int x, int y) {
    x = abs(x);
    y = abs(y);
		memset(pwx, 0, sizeof(pwx));
		memset(pwy, 0, sizeof(pwy));
		int mx = -1, my = -1;
		for (int i = 0; ; ++i) {
			if (x == 0) break;
			pwx[i] = x % 3;
			x /= 3;
		}
		check(pwx, mx);
		check(pwy, my);
		for (int i = 0; i <= max(mx, my); ++i) {
			if (pwx[i] == 0 && pwy[i] == 0) return "Impossible";
			if (pwx[i] != 0 && pwy[i] != 0) return "Impossible";
		}
		return "Possible";
	}
};
