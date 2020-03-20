#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class EpicPartition {
	public:
		string createPartition(int n) {
			int m = 6*n;
			if (n%4) return "";
			string ans(m, ' ');
			int s = 3*n*(6*n+1);
			int s1 = s/4;
			int s2 = s/2;
			int cnt=6*n/3;
			int sum=0;
			for (int i = m; i >= 1; --i) {
				if (cnt == 0) break;
				if (sum + i + cnt*(cnt-1)/2 <= s2) {
					sum += i;
					ans[i-1] = 'c';
					cnt--;
				}
			}
			vector<int> pos;
			for (int i = 1; i <= m; ++i) {
				if (ans[i-1] == ' ') {
					pos.push_back(i);
				}
			}
		//	int l = 0, 
			int r = pos.size()-1;
			sum=0;
			for (int i = 0; i < n-1; ++i) {
				ans[pos[r-i]-1] = 'b';
				ans[pos[i]-1] = 'b';
				sum += pos[r-i] + pos[i];
			}
			//cout<<sum<<endl;
			//cout<<pos[r-n+1]<<endl;
			ans[pos[r-n+1]-1] = 'b';
			sum += pos[r-n+1];
			ans[s1-sum-1] = 'b';
			for (int i = 1; i <= m; ++i) {
				if (ans[i-1] == ' ') ans[i-1] = 'a';
			}
			return ans;
		}
};
