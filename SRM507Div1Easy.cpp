#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <deque>
#include <map>
#define N 102
using namespace std;
typedef long long ll;
class CubeStickers {
	public:
		string isPossible(vector<string> sticker) {
			int n = sticker.size();
			map<string, int> cnt;
			for (int i = 0; i < n; ++i) {
				if (cnt[sticker[i]] < 2) {
					cnt[sticker[i]]++;
				}
			}
			int tot =0;
			for (auto v : cnt) {
				tot += v.second;
			}
			if (tot >= 6) return "YES";
			return "NO";
		}
};
