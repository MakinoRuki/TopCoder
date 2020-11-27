#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class TwoRobots {
	public:
		int dx[4]={-1,1,0,0};
		int dy[4]={0,0,-1,1};
		const int inf = 1000000000;
		int move(vector<string> plan) {
			int n = plan.size();
			int m = plan[0].size();
			int dis[n*m+1][n*m+1];
			int sa=0, sb=0, ea=0, eb=0;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (plan[i][j]=='A') {
						sa=i*m+j;
					} else if (plan[i][j]=='B') {
						sb=i*m+j;
					} else if (plan[i][j]=='a') {
						ea=i*m+j;
					} else if (plan[i][j]=='b') {
						eb=i*m+j;
					}
				}
			}
			queue<pair<int,int>> q;
			q.push(make_pair(sa,sb));
			for (int i = 0; i < n*m; ++i) {
				for (int j = 0; j < n*m; ++j) {
					dis[i][j]=inf;
				}
			}
			dis[sa][sb]=0;
			while(!q.empty()) {
				auto pr = q.front();
				q.pop();
				int cax=pr.first/m;
				int cay=pr.first%m;
				int cbx=pr.second/m;
				int cby=pr.second%m;
				for (int d1=0;d1<4;++d1) {
					for (int d2=0;d2<4; ++d2) {
						int nax=cax+dx[d1];
						int nay=cay+dy[d1];
						int nbx=cbx+dx[d2];
						int nby=cby+dy[d2];
						if (nax>=0&&nax<n&&nay>=0&&nay<m&&plan[nax][nay]!='#'&&nbx>=0&&nbx<n&&nby>=0&&nby<m&&plan[nbx][nby]!='#') {
							if (!(nax==nbx&&nay==nby) && !(nax==cbx&&nay==cby&&nbx==cax&&nby==cay)) {
								if (dis[nax*m+nay][nbx*m+nby]>dis[pr.first][pr.second]+1) {
									dis[nax*m+nay][nbx*m+nby] = dis[pr.first][pr.second]+1;
									q.push(make_pair(nax*m+nay,nbx*m+nby));
								}
							}
						}
					}
				}
			}
			return dis[ea][eb]>=inf ? -1 : dis[ea][eb];
		}
};
