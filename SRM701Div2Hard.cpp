#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
class ThueMorseGame {
	public:
		bool odds[1<<16];
		bool getOdd (int i) {
			// 卡常数,把32位分成两段计算。
			return (odds[i & 65535] + odds[i >> 16]) % 2;
		}
		string get (int n, int m) {
			if (n <= m) return "Alice";
			ll mask = (1LL << m) - 1;
			// 用二进制记录下前m个数的胜负状态。
			ll status = (1LL << m) - 1;
			memset(odds, false, sizeof(odds));
			for (int i = 0; i < (1<<16); ++i) {
				odds[i] = (__builtin_popcount(i) & 1);
			}
			for (int i = m + 1; i <= n; ++i) {
				int cur = 0;
				if (getOdd(i) || (status != mask)) {
					cur = 1;
				}
				status = ((status << 1) | cur) & mask;
			}
			return (status & 1) ? "Alice" : "Bob";
		}
};
