#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class BalancedStrings {
	public:
		vector<string> ans;
		vector<string> findAny (int n) {
			ans.clear();
			if (n <= 26) {
				for (int i = 0; i < n; ++i) {
					string res = " ";
					res[0] = 'a' + i;
					ans.push_back(res);
				}
			} else {
				int tot = n - 26;
				for (int i =  0; i < 24; i += 3) {
					int j;
					for (j = 1; j <= min(10, tot + 1); ++j) {
						string res = " ";
						res[0] = 'a' + i;
						ans.push_back(res);
					}
					j--;
					tot -= (j - 1);
					if (i == 21) {
						if (n >= 99) ans.push_back("v");
						if (n >= 100) ans.push_back("v");
					}
					int k = j * (j - 1) / 2;
					string nxt = "";
					for (int t = 1; t <= k; ++t) {
						nxt += " ";
						nxt[nxt.size() - 1] = i + 1 + 'a';
						nxt += " ";
						nxt[nxt.size() - 1] = i + 2 + 'a';
					}
					nxt += " ";
					nxt[nxt.size() - 1] = i + 1 + 'a';
					ans.push_back(nxt);
					nxt = " ";
					nxt[nxt.size() - 1] = 'a' + i + 2;
					ans.push_back(nxt);
				}
				if (n == 99) {
					string res = "";
					for (int i = 1; i <= 10; ++i) {
						res += "yz";
					}
					res += "y";
					ans.push_back(res);
				} 
				if (n == 100) {
					string res = "";
					for (int i = 1; i <= 21; ++i) {
						res += "yz";
					}
					res += "y";
					ans.push_back(res);
				}
				if (n < 99) ans.push_back("y");
				ans.push_back("z");
			}
			return ans;
		}
};
