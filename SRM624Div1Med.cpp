#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#define N 2001
using namespace std;
typedef long long ll;
ll mod=1000000009LL;
ll inf=1000000000LL;
ll dis[N][2],cnt[N][2];
bool vis[N];
vector<pair<int, int> >edge[N];
int n,m;
struct cmp{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b){
		return a.first>b.first;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int> >, cmp>q;
class DrivingPlans{
	public:
		void spfa(int s, int f){
			memset(vis,false,sizeof(vis));
			for(int i=1;i<=n;++i)
				cnt[i][f]=0LL;
			dis[s][f]=0;
			cnt[s][f]=1LL;
			for(int i=1;i<=n;++i)
				if(i!=s)
					dis[i][f]=inf;
			vis[s]=true;
			q.push(make_pair(0,s));
			set<pair<int, int> >st;
			st.insert(make_pair(0,s));
			while(!q.empty()){
				pair<int,int> pi=q.top();//*st.begin();
				q.pop();
				int u=pi.second;
			//	if(pi.first>dis[t][f])continue;
			//	vis[u]=true;
			//	st.erase(st.begin());
				for(int i=0;i<edge[u].size();++i){
					int v=edge[u][i].first;
					int d=edge[u][i].second;
				//	if(vis[v])continue;
					if(dis[v][f]>pi.first+(ll)d){
                  //      st.erase(make_pair(dis[v][f],v));
						dis[v][f]=dis[u][f]+d;
						cnt[v][f]=cnt[u][f];
					//	st.insert(make_pair(dis[v][f],v));
						q.push(make_pair(dis[v][f],v));
					} else if(dis[v][f]==pi.first+(ll)d){
						cnt[v][f]=(cnt[v][f]+cnt[u][f])%mod;
					}
				//	}
				//	cout<<"dis="<<dis[v][f]<<endl;
				}
			//	if(u==5)cout<<" "<<dis[n][f]<<" "<<cnt[n][f]<<endl;
			}
		}
		int count(int _n, vector<int>A, vector<int>B, vector<int>C){
			memset(vis,false,sizeof(vis));
			n=_n;
			m=A.size();
			for(int i=1;i<=n;++i)
				edge[i].clear();
			for(int i=0;i<m;++i){
				int x=A[i];
				int y=B[i];
				edge[x].push_back(make_pair(y,C[i]));
				edge[y].push_back(make_pair(x,C[i]));
			}
			spfa(1,0);
			spfa(n,1);
			for(int i=0;i<m;++i){
				if(C[i]==0){
					int x=A[i];
					int y=B[i];
					if(dis[x][0]+dis[y][1]==dis[n][0])
						return -1;
				}
			}
		//	return cnt[7][0];
			return cnt[n][0];
		}
};
