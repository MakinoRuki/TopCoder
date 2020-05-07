#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
class WinterAndPresents{
	public:
		int n;
		ll ans;
		ll getNumber(vector<int> apple, vector<int> orange){
			ans = 0;
			n = apple.size();
			int minv = 2000001;
			for(int i = 0;i<n;++i){
				minv = min(minv,apple[i]+orange[i]);
			}
			for(int k = 1;k<=minv;++k){
			/*	int a = 0;
				int o = 0;
				for(int i = 0;i<n;++i){
					a+=min(k,apple[i]);
					o+=min(k,orange[i]);
				} */
				int l=0, r=0;
				for (int i = 0; i < n; ++i) {
					l += max(0, k-orange[i]);
					r += min(apple[i], k);
				}
				if (r>=l) ans += r-l+1;
				//ans+=(ll)max(min(k*n,a)-max(k*n-o,0)+1,0);
			}
			return ans;
		}
};
