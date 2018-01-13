#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define pii pair<int, int>
#define mp make_pair
#define inf 2000000000
using namespace std;
class Subrectangle {
public:
	int n;
	deque<pii> bw;
    int minMissed(string s) {
        n = s.size();
        if (n == 0) return 1;
        bw.clear();
        for (int i = 0; i < n; ++i) {
        	int c = (s[i] == '#');
        	if (bw.empty() || (bw.back().first != c)) bw.push_back(mp(c, 1));
        	else bw.back().second++;
        }
        if (bw.back().first) bw.push_back(mp(0, 0));
        if (bw.size() == 1) return 1;
        int bm = 0, wm = 0;
        for (auto& x : bw) {
        	if(x.first) bm = max(bm, x.second);
        	else wm = max(wm, x.second);
        }
        int ans = inf;
        for (int x = 0; x <= wm; ++x) {
        	for (int y = 1; y <= bm; ++y) {
        		for (int z = 0; z + x <= wm; ++z) {
        			int del = x + y + z;
        			if (del > ans) continue;
        			int res = 0;
        			deque<pii> tbw = bw;
        			while(!tbw.front().first && tbw.front().second > x) {
        				res += del;
        				tbw.front().second -= del;
        			}
        			if (tbw.front().second <= 0) tbw.pop_front();
        			bool ok = true;
        			while(tbw.size() > 1) {
        				res += del;
        				if (!tbw.front().first && tbw.front().second > x) {
        					if (x + z == 0) {
        						ok = false;
        						break;
        					}
        					tbw.front().second -= x + z;
        					continue;
        				}
        				if (!tbw.front().first) tbw.pop_front();
        				tbw.front().second -= y;
        				if (tbw.front().second > 0) continue;
        				tbw.pop_front();
        				tbw.front().second -= z;
        			}
        			if (!ok) continue;
        			int w = tbw.back().second;
        			res += (w + del - 1) / del * del;
        			ans = min(ans, res);
        		}
        	}
        }
        return ans - s.size();
    }
};
