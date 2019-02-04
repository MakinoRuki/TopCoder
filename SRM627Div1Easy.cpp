#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
class HappyLetterDiv1 {
	public:
		int n;
		int cnt[27];
		string getHappyLetters(string letters) {
			n = letters.size();
			memset(cnt, 0, sizeof(cnt));
			for (int i = 0; i < n; ++i) {
				cnt[letters[i] - 'a']++;
			}
			string ans = "";
			for (int i = 0; i < 26; ++i) {
				if (!cnt[i]) continue;
				vector<int> nums;
				nums.clear();
				int sum = 0;
				for (int j = 0; j < 26; ++j) {
					if (cnt[j] && j != i) {
						nums.push_back(cnt[j]);
						sum += cnt[j];
					}
				}
				if (sum == 0) {
					ans += " ";
					ans[ans.size() - 1] = 'a' + i;
					continue;
				}
				sort(nums.begin(), nums.end());
				int left = max(0, 2 * nums.back() - sum);
				if (sum & 1) left = max(left, 1);
				if (left < cnt[i]) {
					ans += " ";
					ans[ans.size() - 1] = 'a' + i;
				}
			}
			return ans;
		}
};
