#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
typedef unsigned int uint;
class EllysPairing{
	public:
		int n;
		int getMax(int M, vector<int>count, vector<int> first, vector<int>mult, vector<int> add){
			n=count.size();
			uint maxv=0,maxc=0;
			int tot=0;
			for(int i=0;i<n;++i){
				tot+=count[i];
				uint x=0;
				for(int j=0;j<count[i];++j){
					//int x=0;
					if(j==0)x=first[i];
					else x=(x*mult[i]+add[i])&(M-1);
					if(maxc==0){
						maxv=x;
						maxc++;
					}
					else{
						if(maxv==x)maxc++;
						else maxc--;
					}
				}
			}
		//	return maxv;
			int cnt=0;
			for(int i=0;i<n;++i){
				uint x=0;
				for(int j=0;j<count[i];++j){
					//int x=0;
					if(j==0)x=first[i];
					else x=(x*mult[i]+add[i])&(M-1);
					if(x==maxv)cnt++;
				}
			}
			if(tot-cnt<=cnt)return tot-cnt;
			else return tot/2;
		}
};
