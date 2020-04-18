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
#define N 52
using namespace std;
typedef long long ll;
class ICPCBalloons {
public:
	int n, m;
	int getres(vector<int>& v1, vector<int>& v2) {
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		reverse(v1.begin(), v1.end());
		reverse(v2.begin(), v2.end());
		int rem = 0;
		int i;
		int j = 0;
		int tot=0;
		for (i = 0; i < v1.size(); ++i) {
			if (j >= v2.size()) break;
			if (v2[j] < v1[i]) tot += v1[i]-v2[j];
			rem += v2[j]-v1[i];
			j++;
		}
		while(j < v2.size()) rem += v2[j++];
		while(i < v1.size()) {
			rem -= v1[i];
			tot += v1[i];
			i++;
		}
		if (rem >=0) return tot;
		return 1000000000;
	}
	int minRepaintings(vector <int> bc, string bs, vector <int> ma) {
		n = bc.size();
		m = ma.size();
		vector<int> mc;
		vector<int> lc;
		mc.clear();
		lc.clear();
		for (int i = 0; i < n; ++i) {
			if (bs[i]=='M') mc.push_back(bc[i]);
			else lc.push_back(bc[i]);
		}
		int ans=1000000000;
		for (int i = 0; i < (1<<m); ++i) {
			vector<int> v1;
			vector<int> v2;
			for (int j = 0; j < m; ++j) {
				if ((1<<j)&i) v1.push_back(ma[j]);
				else v2.push_back(ma[j]);
			}
			int res=getres(v1, mc) + getres(v2, lc);
			ans = min(ans, res);
		}
		return (ans < 1000000000 ? ans : -1);
	}
};
