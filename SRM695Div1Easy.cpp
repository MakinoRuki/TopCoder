#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class BearPasswordLexic {
	public:
		int n;
		string findPassword (vector<int> x) {
			n = x.size();
			string ans = "";
			vector<int> len;
			len.clear();
			int tot = 0;
			while (true) {
				int i;
				for (i = n - 1; i >= 0; --i) {
					if (x[i]) break;
				}
				if (i < 0) {
					break;
				}
				int cnt = 0;
				for (int j = i; j >= 0; --j) {
					cnt++;
					if (x[j] < cnt) return "";
					x[j] -= cnt;
				}
				len.push_back(i + 1);
				tot += i + 1;
			}
			if (tot != n) return "";
			sort(len.begin(), len.end());
			int b = 0, e = len.size() - 1;
			int now = 0;
			while (b <= e) {
				int l;
				if (!now) l = len[e], e--;
				else l = len[b], b++;
				for (int i = 1; i <= l; ++i) {
					if (!now) ans += "a";
					else ans += "b";
				}
				now ^= 1; 
			}
			return ans;
		}
};
