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
#define M 52
#define N 1002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
class ReconstructPermutation {
public:
	vector<int> reconstruct(int n, vector<int> partial) {
	//	int m = (int)partial.size();
		set<int> ss(partial.begin(), partial.end());
		vector<int> v2;
		v2.clear();
		for (int i = 0; i < n; ++i) {
			if (ss.find(i) == ss.end()) {
				v2.push_back(i);
			}
		}
		vector<int> ans;
		ans.clear();
		int i = 0, j = 0;
		while(i < partial.size() || j < v2.size()) {
			if (j >= v2.size() || (i < partial.size() && partial[i] < v2[j])) {
				ans.push_back(partial[i]);
				i++;
			} else {
				ans.push_back(v2[j]);
				j++;
			}
		}
		return ans;
	}
};
