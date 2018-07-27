#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 30
#define inf 1000000000
using namespace std;
class Shuffler {
	public:
		int n;
		int dis[N][N];
		int getnext(int idx, int type) {
			if (idx < 13) {
				return (type == 1 ? 2 * idx : 2 * idx + 1);
			} else {
				return (type == 1 ? 2 * (idx - 13) + 1 : 2 * (idx - 13));
			}
			return 0;
		}
		void perform(string& s, int type) {
			string res;
			for (int i = 0; i < 13; ++i) {
				if (type == 1) {
					res += s.substr(i, 1) + s.substr(i + 13, 1);
				} else {
					res += s.substr(i + 13, 1) + s.substr(i, 1);
				}
			}
			s = res;
		}
		string findShuffles(string name) {
			n = name.size();
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					dis[i][j] = (i == j ? 0 : inf);
				}
			}
			for (int i = 0; i < 13; ++i) {
				dis[i][2 * i] = 1;
				dis[i][2 * i + 1] = 1;
				dis[i + 13][2 * i] = 1;
				dis[i + 13][2 * i + 1] = 1;
			}
			for (int k = 0; k < 26; ++k) {
				for (int i = 0; i < 26; ++i) {
					for (int j = 0; j < 26; ++j) {
						dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
					}
				}
			}
			string s;
			for (int i = 0; i < 26; ++i) {
				s += 'A' + i;
			}
			string ans = "";
			for (int i = 0; i < n; ++i) {
				int idx;
				for (int j = 0; j < 26; ++j) {
					if (s[j] == name[i]) {
						idx = j;
						break;
					}
				}
				while(idx != 0) {
					int x = getnext(idx, 1);
					int y = getnext(idx, 2);
					if (dis[x][0] + 1 == dis[idx][0]) {
						ans += "1";
						perform(s, 1);
						idx = x;
					} else {
						ans += "2";
						perform(s, 2);
						idx = y;
					}
				}
				ans += "R";
			}
			return ans;
		}
};
