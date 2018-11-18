#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class PairGame {
public:
	int maxSum(int a, int b, int c, int d) {
		set<pii> s1, s2;
		s1.clear();
		s2.clear();
		while(a > 0 && b > 0) {
			s1.insert(mp(a, b));
			if (a >= b) a -= b;
			else b -= a;
		}
		while(c > 0 && d > 0) {
			s2.insert(mp(c, d));
			if (c >= d) c -= d;
			else d -= c;
		}
		int ans = -1;
		for (set<pii>::iterator itr = s1.begin(); itr != s1.end(); ++itr) {
			if (s2.find(*itr) != s2.end()) {
				ans = max(ans, itr->first + itr->second);
			}
		}
		return ans;
	}	
};
