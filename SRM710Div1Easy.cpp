#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class ReverseMancala {
	public:
		int n;
		vector<int> ans;
		vector<int> findMoves (vector<int> start, vector<int> target) {
			n = start.size();
			int tot = 0;
			for (int i = 0; i < n; ++i) {
				tot += start[i];
			}
			while (true) {
				if (start[0] == tot) break;
				for (int i = 1; i < n; ++i) {
					if (start[i]) {
						ans.push_back(i);
						int num = start[i];
						start[i] = 0;
						int cur = (i + 1) % n;
						while (num) {
							start[cur]++;
							num--;
							cur = (cur + 1) % n;
						}
						break;
					}
				}
			}
			vector<int> tmp;
			tmp.clear();
			while (true) {
				if (target[0] == tot) break;
				for (int i = 1; i < n; ++i) {
					if (target[i]) {
						tmp.push_back((i + target[i]) % n + n);
						int num = target[i];
						target[i] = 0;
						int cur = (i + 1) % n;
						while (num) {
							target[cur]++;
							num--;
							cur = (cur + 1) % n;
						}
						break;
					}
				}
			}
			reverse(tmp.begin(), tmp.end());
			for (int i = 0; i < tmp.size(); ++i) {
				ans.push_back(tmp[i]);
			}
			return ans;
		}
};
