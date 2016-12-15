#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class AB {
	public:
		string createString (int n, int k) {
			int rb = n / 2;
			if (n % 2) rb++;
			if (k > (n - n / 2) * (n / 2)) return "";
			string ans = "";
			int cnt= 0;
			int ca = 0;
			for (int i = 0; i < n; ++i) {
				if (ca == n / 2) {
					ans += "B";
				} else {
					cnt += rb;
					if (cnt <= k) {
						ans += "A";
						ca++;
					} else {
						cnt -= rb;
						ans += "B";
						rb--;
					}
				}
			}
			return ans;
		}
};
