#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 102
using namespace std;
class Family{
	public:
		int n;
		int col[N];
		vector<int>edge[N];
		bool dfs(int u, int c){
		//	if(col[u]>=0 && col[u]!=c)return false;
			col[u]=c;
			for(int i=0;i<edge[u].size();++i){
				int v=edge[u][i];
				if(col[v]>=0 && col[v]!=!c)return false;
				if(col[v]<0 && !dfs(v,!c))return false;
			}
			return true;
		}
		string isFamily(vector <int> parent1, vector <int> parent2){
			n=parent1.size();
			memset(col,-1,sizeof(col));
			for(int i=0;i<n;++i)
				edge[i].clear();
			for(int i=0;i<n;++i){
				if(parent1[i]==-1)continue;
				int u=parent1[i];
				int v=parent2[i];
				edge[u].push_back(v);
				edge[v].push_back(u);
			}
			for(int i=0;i<n;++i)
				if(col[i]==-1){
					if(!dfs(i,0))return "Impossible";
				}
			return "Possible";
		}
};
