#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class ThreeNeighbors {
	public:
		vector<string> construct(int n) {
			vector<string> ans;
			int b = n/96;
			int r = n%96;
			for (int i = 1; i <= b; ++i) {
				ans.push_back(string(50, 'X'));
				ans.push_back(string(50, '.'));
				ans.push_back(string(50, '.'));
				ans.push_back(string(50, 'X'));
			}
			if (r <= 48) {
				while(ans.size()<49) ans.push_back(string(50,'X'));
				ans.push_back(string(r+2, '.')+string(48-r, 'X'));
			} else {
				r -= 48;
				while(ans.size()<47) ans.push_back(string(50, 'X'));
				ans.push_back(string(50, '.'));
				ans.push_back(string(50, '.'));
				//ans.push_back(string(r+2, '.') +string(48-r, 'X'));
				ans.push_back(string(r+2, 'X')+string(48-r,'.'));
			}
			return ans;
		}
};
