#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <deque>
#define N 1000005
using namespace std;
typedef long long ll;
class MathContest {
	public:
		int countBlack(string bs, int rs) {
			string bss;
			for (int i = 1; i <= rs; ++i) {
				bss += bs;
			}
			deque<int> bsq;
			for (int i = 0; i < bss.size(); ++i) {
				bsq.push_back(bss[i]=='B');
			}
			int rv = 0;
			int cc = 0;
			int cnt=0;
			while(!bsq.empty()) {
				int c;
				if (!rv) {
					c = bsq.front() ^ cc;
					bsq.pop_front();
				} else {
					c = bsq.back() ^ cc;
					bsq.pop_back();
				}
				if (c) {
					cnt++;
					cc = !cc;
				} else {
					rv = !rv;
				}
			}
			return cnt;
		}
};
