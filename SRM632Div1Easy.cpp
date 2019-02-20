#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
class PotentialArithmeticSequence {
	public:
		int n;
		int numberOfSubsequences(vector <int> d) {
			n = d.size();
			int ans = 0;
			for (int i = 0; i < n; ++i) {
				vector<int> stk;
				stk.clear();
				for (int j = i; j < n; ++j) {
					if (j > i && ((d[j] == 0 && d[j - 1] == 0) || (d[j] != 0 && d[j - 1] != 0))) break;
					if (d[j]) {
						int c = 1;
						while(!stk.empty()) {
							if (stk.back() == c) {
								stk.pop_back();
								c++;
							} else {
								break;
							}
						}
						if (!stk.empty() && c > stk.back()) break;
						if (c == d[j]) stk.push_back(c);
						else {
							if (stk.empty() && c < d[j]) stk.push_back(d[j]);
							else break;
						}
					}
					ans++;
				}
			}
			return ans;
		} 
	/*	int lowbit (int num) {
			return num & (num ^ (num - 1));
		}
        bool check (vector<int> & d) {
             int n = d.size();
             for (int i = 0; i < n; ) {
                 if (d[i] == 0) {
                 	if (i < n && d[i + 1] == 0) {
                 		return false;
                 	}
                    i++;
                    continue;
                 }
                 int j;
                 int cnt = d[i];
                 int num = (1<<d[i]);
                 for (j = i + 1; j < min(i + (1<<cnt), n); ++j) {
                     num++;
                     if (lowbit(num) != (1<<d[j])) {
                        return false;
                     }
                 }
                 if (j < n && d[j] <= d[i]) {
                    return false;
                 }
                 i = j;
             }
             return true;
        }
		int numberOfSubsequences (vector<int> d) {
			int n = d.size();
			int ans = n;
			for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    vector<int> tmp;
                    tmp.clear();
                    for (int k = i; k <= j; ++k) {
                        tmp.push_back(d[k]);
                        tmp[tmp.size() - 1] = min(tmp[tmp.size() - 1], 6);
                    }
                    if (check(tmp)) {
                       ans++;
                    }
                }
            }
            return ans;
		} */
};
