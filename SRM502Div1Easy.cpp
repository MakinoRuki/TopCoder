#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 52
using namespace std;
typedef long long ll;
class TheLotteryBothDivs {
public:
	bool issuffix(string s, string t) {
		if (s.size() > t.size()) return false;
		for (int i = s.size()-1; i >= 0; --i) {
			int det = s.size()-1-i;
			if (s[i] != t[t.size()-1-det]) return false;
		}
		return true;
	}
	double getpr(int x) {
		double res=1.0;
		for (int i = 1; i <= x; ++i) {
			res /= 10.0;
		}
		return res;
	}
	double find(vector<string> goodsuffix) {
		// for (int i = 0; i < goodsuffix.size(); ++i) {
		// 	while(goodsuffix[i].size() > 1 && goodsuffix[i][0] == '0') {
		// 		goodsuffix[i] = goodsuffix[i].substr(1);
		// 	}
		// }
		set<string> ss(goodsuffix.begin(), goodsuffix.end());
		vector<string> sv(ss.begin(), ss.end());
		double ans=0.0;
		int n = sv.size();
		for (int i = 0; i < n; ++i) {
			int j;
			for (j = 0; j < n; ++j) {
				if (i==j) continue;
				if (issuffix(sv[j], sv[i])) break;
			}
		//	cout<<sv[i]<<endl;
			if (j >= n) {
		//		cout<<getpr(sv[i].size())<<endl;
				ans += getpr(sv[i].size());
			}
		}
		return ans;
	}
};
