#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
#include<set>
#define M 6000
#define INF 1000000000
using namespace std;
struct Edge  
{  
    int u,v,pre,cap,cost;  
    Edge(){}  
    Edge(int u,int v,int pre,int cap,int cost) :  
        u(u),v(v),pre(pre),cap(cap),cost(cost) {}  
}edge[M];  
  
int head[M],nEdge;  
struct MinCostFlow  
{  
    queue<int> q;  
    int vis[M],pre[M],dis[M],pos[M];  
    void init()  
    {  
       nEdge=0;  
       memset(head,-1,sizeof(head));  
    }  
    void addEdge(int u,int v,int cap,int cost)  
    {  
       edge[nEdge]=Edge(u,v,head[u],cap,cost);  
       head[u]=nEdge++;  
       edge[nEdge]=Edge(v,u,head[v],0,-cost);  
       head[v]=nEdge++;  
    }  
    int spfa(int s,int t,int n)  
    {  
        for(int i=0;i<=n;i++)  
        {  
            pre[i]=-1; vis[i]=0; dis[i]=INF;  
        }  
  
        q.push(s); pre[s]=s; dis[s]=0; vis[s]=1;  
        while(!q.empty())  
        {  
            int u=q.front();  
  
            q.pop(); vis[u]=0;  
  
            for(int i=head[u];i!=-1;i=edge[i].pre)  
            {  
                int v=edge[i].v,cost=edge[i].cost;  
                if(edge[i].cap>0&&dis[u]+cost<dis[v])  
                {  
                    dis[v]=dis[u]+cost;  
  
                    pre[v]=u; pos[v]=i;  
  
                    if(!vis[v])  
                    {  
                        vis[v]=1;  
                        q.push(v);  
                    }  
                }  
            }  
        }  
        if(pre[t]!=-1&&dis[t]<INF) return 1;  
        return 0;  
    }  
    void solve(int s,int t,int n,int &flow,int &cost)  
    {  
        flow=0,cost=0;  
        while(spfa(s,t,n))  
        {  
            int mi=INF;  
            for(int u=t;u!=s;u=pre[u]) mi=min(mi,edge[pos[u]].cap);  
            flow+=mi;  
            cost+=mi*dis[t];  
            for(int u=t;u!=s;u=pre[u])  
            {  
                edge[ pos[u] ].cap-=mi;  
                edge[ pos[u]^1 ].cap+=mi;  
            }  
        }  
    }  
}mcf;  
map<int, int>xm,ym;
set<pair<int, int> >P;
class SpecialCells{
	public:
		int n;
		int guess(vector<int>x, vector<int>y){
			n=x.size();
			xm.clear();
			ym.clear();
			P.clear();
			for(int i=0;i<n;++i){
				xm[x[i]]++;
				ym[y[i]]++;
				P.insert(make_pair(x[i],y[i]));
			}
			mcf.init();
			int xcnt=0,ycnt=0;
			for(map<int, int>::iterator itr=xm.begin();itr!=xm.end();++itr){
				++xcnt;
				mcf.addEdge(0,xcnt,itr->second,0);
				ycnt=0;
				for(map<int, int>::iterator itr2=ym.begin();itr2!=ym.end();++itr2){
					++ycnt;
					if(P.find(make_pair(itr->first,itr2->first))!=P.end()){
						mcf.addEdge(xcnt,xm.size()+ycnt,1,1);
					}
					else{
						mcf.addEdge(xcnt,xm.size()+ycnt,1,0);
					}
				}
			}
			ycnt=0;
			for(map<int, int>::iterator itr=ym.begin();itr!=ym.end();++itr){
				++ycnt;
				mcf.addEdge(xm.size()+ycnt,xm.size()+ym.size()+1,itr->second,0);
			}
			int flow=0;
			int cost=0;
			mcf.solve(0,xm.size()+ym.size()+1,xm.size()+ym.size()+2,flow,cost);
			if(flow==n)
				return cost;
			return n;
		}
};
