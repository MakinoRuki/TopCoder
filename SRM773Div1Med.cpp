#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
class ChristmasTravel {
public:
	vector<string> ans;
	vector<string> plan(int N, int A) {
  		ans.clear();
	    for (int i = 0; i < N; ++i) {
	      ans.push_back(string(N, '-'));
	    }
	    int cnt[26];
	    memset(cnt, 0, sizeof(cnt));
	    for (int i = 0; i < N; ++i) {
	    	for (int j = i + 1; j < N; ++j) {
	    		int k;
	    		for (k = 0; k <= 10; ++k) {
	    			bool x = (1<<k) & i;
	    			bool y = (1<<k) & j;
	    			if (x != y) {
	    				break;
	    			}
	    		}
	    		if (k >= A) return {};
	    		ans[i][j] = ans[j][i] = 'A' + k;
	    		cnt[k]++;
	    	}
	    }
	    for (int i = 0; i < A; ++i) {
	    	if (cnt[i] == 0) {
	    		bool found = false;
	    		for (int x = 0; x < N; ++x) {
	    			for (int y = x + 1; y < N; ++y) {
	    				if (cnt[ans[x][y]-'A'] > 1) {
	    					cnt[ans[x][y]-'A']--;
	    					ans[x][y] = ans[y][x] = i + 'A';
	    					found = true;
	    					break;
	    				}
	    			}
	    			if (found) break;
	    		}
	    		if (!found) return {};
	    	}
	    }
	    return ans;
  	}
};
