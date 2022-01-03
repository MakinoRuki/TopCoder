#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 72
#define N 205
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
class DogsInAGrid {
public:
	vector<string> construct(int n) {
		int q1 = n/116;
		int r1 = n%116;
		vector<string> ans;
		ans.clear();
		ans.push_back(string(40, 'D'));
		for (int i = 1; i <= q1; ++i) {
			ans.push_back(string(40, 'O'));
			if (i%2) {
				ans.push_back(string(40, 'G'));
			} else {
				ans.push_back(string(40, 'D'));
			}
		}
		if (r1 > 0) {
			if (ans.size() == 39) {
				string cur="D";
				for (int i = 1; i <= r1; ++i) {
					if (i%2) cur += "OG";
					else cur += "OD";
				}
				while(cur.size() < 40) cur += "D";
				ans.push_back(cur);
			} else {
				int i;
				for (i = 1; i <= 40; ++i) {
					if (i + max(i-2,0)*2 >= r1) {
						break;
					}
				}
				vector<string> tmp;
				tmp.clear();
				for (int j = 0; j < 3; ++j) {
					tmp.push_back(string(40, 'O'));
				}
				for (int j = 1; j <= i; ++j) {
					tmp[0][j-1] = 'D';
					tmp[2][j-1] = 'G';
				}
				//cout<<tmp[0]<<" "<<tmp[1]<<" "<<tmp[2]<<endl;
				if (3*i-4 - r1 == 1) {
					tmp[1][0] = (ans.empty() ? 'G' : ans.back()[0]);
				} else if (3*i-4-r1 == 2) {
					tmp[1][0] = (ans.empty() ? 'G' : ans.back()[0]);
					tmp[1][i-1]=(ans.empty() ? 'G' : ans.back()[0]);
				}
				for (int j = 0; j < 3; ++j) {
					ans.push_back(tmp[j]);
				}
			}
		}
		return ans;
	}
};
