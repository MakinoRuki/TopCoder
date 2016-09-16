#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class DoubleOrOneEasy {
	public:
		int ans;
		void getAns (int rem, int pw) {
			int pt = 0;
				while (pw > 1) {
					pt++;
					pw /= 2;
				}
				int cnt = 0;
				while (rem) {
					if (rem & 1) ans++, rem--;
					else {
						if (cnt < pt) rem /= 2, cnt++;
						else break;
					}
				}
				ans += pt + rem;
		}
		int minimalSteps (int a, int b, int newA, int newB) {
			ans = 0;
			if (a == b) {
				if (newA != newB) {
					return -1;
				} else {
					if (a > newA) return -1;
					int pw = 0;
					for (pw = 0; ; ++pw) {
						if (a * (1<<pw) > newA) break;
					}	
					pw--;
					getAns(newA - a * (1<<pw), 1<<pw);
				}
			} else {
				if (newA == newB) return -1;
				if (a > newA || b > newB) return -1;
				if ((newA - newB) % (a - b)) return -1;
				int pw = (newA - newB) / (a - b);
				if (__builtin_popcount(pw) > 1) return -1;
				if (newA / a < pw || newB / b < pw) return -1;
				getAns(newA - a * pw, pw);
			}
			return ans;
		}
};
