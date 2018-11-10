#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 100005
using namespace std;
bool c[N];
class MyLongCake{
	public:
	int cut(int n){
		memset(c,false,sizeof(c));
		for(int i=2;i*i<=n;++i)
			if(n%i==0){
				for(int j=0;j<n;j+=i)
					c[j]=true;
				if(n/i!=i){
					for(int j=0;j<n;j+=n/i)
						c[j]=true;
				}
			}
		int cnt=0;
		for(int i=1;i<n;++i)
			if(c[i])cnt++;
		return cnt+1;
	}
};
