#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
class ORSolitaire{
	public:
		int n;
		int getMinimum(vector<int>numbers, int goal){
			n = numbers.size();
			int ans=n;
			for (int i = 0; i <= 30; ++i) {
				if ((1<<i)&goal) {
					int cnt=0;
					for (int j = 0; j < n; ++j) {
						int k;
						for (k = 0; k <= 30; ++k) {
							if (((1<<k)&numbers[j]) && !((1<<k)&goal)) break;
						}
						if (k <= 30) continue;
						if ((1<<i) & numbers[j]) cnt++;
					}
					ans=min(ans, cnt);
				}
			}
		/*	int ini = 0;
			for(int i = 0;i<n;++i){
				if((numbers[i]|goal)==goal)ini|=numbers[i];
			}
			if(ini!=goal)return 0;
			int ans = n+1;
			for(int i = 0;i<=30;++i){
				if(((1<<i)&goal)==0)continue;
				int sum = 0;
				for(int j = 0;j<n;++j)
					if((1<<i)&numbers[j]){
						if((numbers[j]|goal)==goal)
							sum++;
					}
				ans = min(ans,sum);
			} */
			return ans;
		}
};
