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
/*#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#define N 102
using namespace std;
class Family{
	public:
		int n;
		int col[N];
		vector<int>edges[N];
		vector<int> p1, p2;
		bool bfs(int u, int c) {
			queue<pair<int, int>> q;
			bool vis[N];
			q.push(make_pair(u, c));
			memset(vis, false, sizeof(vis));
			vis[u] = true;
			col[u] = c;
			while(!q.empty()) {
				auto pr = q.front();
				q.pop();
				int u = pr.first;
				int c = pr.second;
				for (int i = 0; i < edges[u].size(); ++i) {
					int j = edges[u][i];
					int v= (p1[j] == u ? p2[j] : p1[j]);
					if (col[v] < 0) {
						col[v] = !c;
						q.push(make_pair(v, !c));
					} else {
						if (col[v] != !c) return false;
					}
				}
			}
			return true;
		}
		string isFamily(vector <int> parent1, vector <int> parent2){
			n=parent1.size();
			p1 = parent1;
			p2 = parent2;
			memset(col,-1,sizeof(col));
			for(int i=0;i<n;++i)
				edges[i].clear();
			for(int i=0;i<n;++i){
				if(parent1[i]==-1)continue;
				int u=parent1[i];
				int v=parent2[i];
				edges[u].push_back(i);
				edges[v].push_back(i);
			}
			for(int i=0;i<n;++i)
				if(col[i]==-1){
					if(!bfs(i,0))return "Impossible";
				}
			return "Possible";
		}
};*/
