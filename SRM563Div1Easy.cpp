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
class FoxAndHandle {
public:
	string lexSmallestName(string s) {
		int cnt[3][26];
		memset(cnt, 0, sizeof(cnt));
		int n = s.size();
		for (int i = 0; i < n; ++i) {
			cnt[0][s[i]-'a']++;
		}
		string ans="";
		for (int i = 0; i < n; ++i) {
			int c = s[i]-'a';
			if (cnt[1][c] >= cnt[0][c]/2) {
				cnt[2][c]++;
				continue;
			}
			while(ans.size()) {
				if (ans.back()-'a' > c) {
					int c2 = ans.back()-'a';
					if (cnt[2][c2] < cnt[0][c2]/2) {
						ans.pop_back();
						cnt[1][c2]--;
						cnt[2][c2]++;
					} else {
						break;
					}
				} else {
					break;
				}
			}
			ans.push_back(s[i]);
			cnt[1][c]++;
		}
		return ans;
	}
};
