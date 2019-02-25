#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
#define maxv 1000000000
using namespace std;
class EllysNumberGuessing{
	public:
		int n;
		int getNumber(vector<int>guesses, vector<int>answers){
			n=guesses.size();
			set<int>tmp;
			for(int i=0;i<n;++i){
				if(i==0){
					if(guesses[i]-answers[i]>=1)
						tmp.insert(guesses[i]-answers[i]);
					if(guesses[i]+answers[i]<=maxv)
						tmp.insert(guesses[i]+answers[i]);
				}
				else{
					bool f1=false;
					for(set<int>::iterator itr=tmp.begin();itr!=tmp.end();){
						bool f2=false;
						int x1=guesses[i]-answers[i];
						int x2=guesses[i]+answers[i];
						if(x1>=1 && x1==*itr)
							f2=true;
						if(x2<=maxv && x2==*itr)
							f2=true;
						if(f2){
							f1=true;
							itr++;
						}
						else{
							tmp.erase(itr++);
						}
					}
					if(!f1)
						return -2;
				}
			}
			if(!tmp.size())return -2;
			else{
				if(tmp.size()==1)return *tmp.begin();
				else return -1;
			}
		}
};
