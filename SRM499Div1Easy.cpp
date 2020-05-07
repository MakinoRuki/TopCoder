#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 1000005
using namespace std;
typedef long long ll;
class ColorfulRabbits {
public:
	int cnt[N];
	int getMinimum(vector<int> replies) {
		int n = replies.size();
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; ++i) {
			cnt[replies[i]]++;
		}
		int tot=0;
		for (int i = 0; i <= 1000000; ++i) {
			if (cnt[i] > 0) {
				tot += (cnt[i]+i)/(i+1)*(i+1);
			}
		}
		return tot;
	}
};
