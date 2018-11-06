#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
set<ll>S,O;
class AmebaDiv1{
	public:
		int n;
		int count(vector<int> X){
			n=X.size();
			S.clear();
			O.clear();
			for(int i=0;i<n;++i){
				O.insert((ll)X[i]);
				ll start=X[i];
				for(int j=0;j<n;++j){
					if(X[j]==start){
						start=start*2LL;
					}
				}
				S.insert(start);
			}
			int ans=0;
			for(set<ll>::iterator itr=O.begin();itr!=O.end();++itr){
				if(S.find(*itr)==S.end()){
					ans++;
				}
			}
			return ans;
		}
};
