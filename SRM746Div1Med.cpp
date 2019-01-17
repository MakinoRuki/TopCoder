#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class FindStringHard {
	public:
		string withAntipalindromicSubstrings(int n) {
			int x = 50;
			string ans = "";
			while(n > 1) {
				if (x * (x + 1) <= n) {
					n -= x * (x + 1);
					for (int i = 1; i <= x; ++i) {
						ans += "ab";
					}
					ans += "a";
				} else {
					x--;
				}
			}
			if (n) ans += "ab";
			return ans;
		}
};
