#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 102
#define upper 1000000000000000LL
using namespace std;
typedef long long ll;
class LR {
public:
    int n;
    vector<ll> ss, tt;
    bool check (int tot, int l) {
    	int r = tot - l;
    	vector<ll> tmp = ss;
    	for (int i = 1; i <= l; ++i) {
    		vector<ll> tmp2 = tmp;
    		for (int j = 0; j < n; ++j) {
    			tmp2[j] += tmp[(j - 1 + n) % n];
    			if (tmp2[j] > tt[j]) return false;
    		}
    		tmp = tmp2;
    	}
    	for (int i = 1; i <= r; ++i) {
    		vector<ll> tmp2 = tmp;
    		for (int j = 0; j < n; ++j) {
    			tmp2[j] += tmp[(j + 1) % n];
    			if (tmp2[j] > tt[j]) return false;
    		}
    		tmp = tmp2;
    	}
    	for (int i = 0; i < n; ++i) {
    		if (tmp[i] != tt[i]) return false;
    	}
    	return true;
    }
    string construct (vector<ll> s, vector<ll> t) {
        n = s.size();
        ss = s;
        tt = t;
        for (int i = 0; i < n; ++i) {
        	if (s[i] > t[i]) return "No solution";
        }
        for (int tot = 0; tot <= 100; ++tot) {
        	for (int l = 0; l <= tot; ++l) {
        		if (check(tot, l)) {
        			string ans = string(l, 'L') + string(tot - l, 'R');
        			return ans;
        		}
        	}
        }
        return "No solution";
    }
};
