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
class TomekPhone {
public:
	int minKeystrokes(vector<int> fq, vector<int> ks) {
		sort(fq.begin(), fq.end());
		reverse(fq.begin(), fq.end());
		int i = 0;
		ll ans=0LL;
		for (int cur=1;; ++cur) {
			if (i >= fq.size()) break;
			bool found=false;
			for (int j = 0; j < ks.size(); ++j) {
				if (ks[j]==0) continue;
				if (i >= fq.size()) break;
				found=true;
				ans += cur*fq[i];
				i++;
				ks[j]--;
			}
			if (!found) break;
		}
		if (i < fq.size()) return -1;
		return ans;
	}
};
