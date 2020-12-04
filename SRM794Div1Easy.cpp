#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define N 52
using namespace std;
class IslandInALake {
	public:
		bool vis[N][N];
		int par[N*N+2];
		int cnt[N*N+2];
		int n, m;
		int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
		int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
		int find(int x) {
			return x==par[x] ? x : par[x]=find(par[x]);
		}
		int build(vector<string> cc) {
			memset(vis, false, sizeof(vis));
			n = cc.size();
			m = cc[0].size();
			memset(cnt, 0, sizeof(cnt));
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					par[i*m+j] = i*m+j;
					cnt[i*m+j] = 1;
				}
			}
			queue<int> q;
			for (int i = 0; i < n; ++i) {
				vis[i][0]=true;
				q.push(i*m);
				vis[i][m-1]=true;
				q.push(i*m+m-1);
			}
			for (int j = 1; j < m-1; ++j) {
				vis[0][j]=true;
				q.push(j);
				vis[n-1][j]=true;
				q.push((n-1)*m+j);
			}
			while(!q.empty()) {
				int cur=q.front();
				q.pop();
				int x=cur/m;
				int y=cur%m;
				for (int d=0;d<4;++d) {
					int nx=x+dx[d];
					int ny=y+dy[d];
					if (nx>=0 && nx < n && ny >= 0 && ny < m && cc[nx][ny]=='.' && !vis[nx][ny]) {
						vis[nx][ny]=true;
						q.push(nx*m+ny);
					}
				}
			}
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (cc[i][j]=='.') {
						if (vis[i][j]) continue;
						bool found=false;
						for (int d = 0;d < 8; ++d) {
							int ni=i+dx[d];
							int nj=j+dy[d];
						//	if (i == 8 && j == 4) cout<<"y="<<ni<<" "<<nj<<" "<<cc[ni][nj]<<endl;
							if (ni>=0 && ni < n && nj >= 0 && nj < m && cc[ni][nj]=='#') {
								found=true;
								break;
							}
						}
						if (found) vis[i][j]=true;
						//cout<<i<<" "<<j<<" "<<vis[i][j]<<endl;
					}
				}
			}
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (cc[i][j]=='.' && !vis[i][j]) {
				//		cout<<"x="<<i<<" "<<j<<endl;
						for (int d = 0;d < 8; ++d) {
							int ni=i+dx[d];
							int nj=j+dy[d];
							if (ni>=0 && ni < n && nj >= 0 && nj < m && cc[ni][nj]=='.' && !vis[ni][nj]) {
								int px=find(i*m+j);
								int py=find(ni*m+nj);
								if (px != py) {
									cnt[py] += cnt[px];
									par[px]=py;
								}
							} 
						}
					}
				}
			}
			//cout<<vis[3][3]<<endl;
			int ans=0;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (cc[i][j]=='.' && !vis[i][j]) {
				//		cout<<"i="<<i<<" "<<j<<endl;
						par[i*m+j]=find(i*m+j);
						ans=max(ans, cnt[par[i*m+j]]);
					}
				}
			}
			return ans;
		}
};
