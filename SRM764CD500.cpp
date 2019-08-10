// (x+y)^2+(x-y)^2+(z-s)^2+(z+s)^2=2(x^2+y^2+z^2+s^2)=a^2+b^2+c^2+d^2
// 欧拉四平方和定理
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
class FourSquareSum {
	public:
		vector<int> ans;
		vector<int> DivideByTwo(int a, int b, int c, int d) {
			ans.clear();
			vector<int> nums[2];
			nums[a%2].push_back(a);
			nums[b%2].push_back(b);
			nums[c%2].push_back(c);
			nums[d%2].push_back(d);
			for (int i = 0; i < 2; ++i) {
				for (int j = 0; j < nums[i].size(); j += 2) {
					ans.push_back((nums[i][j]+nums[i][j+1])/2);
					ans.push_back(abs(nums[i][j]-nums[i][j+1])/2);
				}
			}
			return ans;
		}
};
