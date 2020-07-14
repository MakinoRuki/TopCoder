#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
bool pr[10000002];
int pw[10000002];
class PrimeSubstrings {
public:
	string dfs(string& x, int y, int cur, int l, int n) {
		if (cur == n) {
			return x;
		}
		int pre = y%pw[l-1];
		if (pre < pw[l-2]) return "";
		for (int i = 0; i <= 9; ++i) {
			int z = pre*10 + i;
			if (!pr[z]) {
				x.push_back('0'+i);
				auto res = dfs(x, z, cur+1, l, n);
				if (!res.empty()) return res;
				x.pop_back();
			}
		}
		return "";
	}
	string construct(int n, int l) {
		if (l == 1) {
			string ans="";
			for (int i = 0; i < n; ++i) {
				if (i%2) ans += "2";
				else ans += "3";
			}
			return ans;
		}
		memset(pr, false, sizeof(pr));
		pw[0] = 1;
		for (int i = 1; i <= l; ++i) {
			pw[i] = pw[i-1]*10;
		}
		for (int i = 2; i * i <= 10000000; ++i) {
			if (!pr[i]) {
				for (int j = i*i; j <= 10000000; j += i) {
					pr[j] = true;
				}
			}
		}
		vector<int> bg;
		bg.clear();
		for (int i = 2; i <= 10000000; ++i) {
			if (!pr[i] && i >= pw[l-1] && i < pw[l]) {
				bg.push_back(i);
			}
		}
		string ans="";
		for (int i = 0; i < bg.size(); ++i) {
			string x = to_string(bg[i]);
		//	cout<<"x size = "<<x.size()<<endl;
			string res= dfs(x, bg[i], l, l, n);
			if (!res.empty()) {
				ans = res;
				break;
			}
		}
		return ans;
	}
};
