#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 12
using namespace std;
class ShadowSculpture {
public:
	int n;
	bool ok[N][N][N];
	int vis[N][N][N];
	int cnt;
	void dfs (int i, int j, int k, int stap) {
		if (i < 0 || i >= n) return;
		if (j < 0 || j >= n) return;
		if (k < 0 || k >= n) return;
		if (vis[i][j][k] == stap) return;
		if (!ok[i][j][k]) return;
	//	cout<<i<<" "<<j<<" "<<k<<endl;
		vis[i][j][k] = stap;
		dfs(i - 1, j, k, stap);
		dfs(i + 1, j, k, stap);
		dfs(i, j - 1, k, stap);
		dfs(i, j + 1, k, stap);
		dfs(i, j, k - 1, stap);
		dfs(i, j, k + 1, stap);
	}
	void mark (vector<string> & inx, int flag) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (inx[i][j] == 'N') {
					for (int k = 0; k < n; ++k) {
						if (flag == 0) {
							ok[i][j][k] = false;
						}
						if (flag == 1) {
							ok[k][i][j] = false;
						}
						if (flag == 2) {
							ok[j][k][i] = false;
						}
					}
				}
			}
		}
	}
	void findConnect () {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < n; ++k) {
					if (ok[i][j][k]) {
						cnt++;
						dfs(i, j, k, cnt);
					}
				}
			}
		}
	}
	string findPossible (vector<string> & XY, vector<string> & YZ, vector<string> & ZX, int stap) {
      //     cout<<"stap="<<stap<<endl;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int x = 0, y = 0, z = 0;
				for (int k = 0; k < n; ++k) {
					if (ok[i][j][k] && vis[i][j][k] == stap) {
						x++;
					}
					if (ok[k][i][j] && vis[k][i][j] == stap) {
						y++;
					}
					if (ok[j][k][i] && vis[j][k][i] == stap) {
						z++;
					}
				}
			//	if (i == 0 && j == 0)cout<<x<<" "<<y<<" "<<z<<endl;
				if ((XY[i][j] == 'Y' && !x) || (YZ[i][j] == 'Y' && !y) || (ZX[i][j] == 'Y' && !z)) {
					return "Impossible";
				}
			}
		}
		return "Possible";
	}
	string possible (vector<string> XY, vector<string> YZ, vector<string> ZX) {
		n = XY.size();
		memset(ok, true, sizeof(ok));
		memset(vis, 0, sizeof(vis));
		mark(XY, 0);
		mark(YZ, 1);
		mark(ZX, 2);
	//	for (int i = 0; i < n; ++i)for(int j = 0; j < n; ++j)for(int k = 0 ; k < n; ++k)cout<<i<<" "<<j<<" "<<k<<" "<<ok[i][j][k]<<endl;
		findConnect();
//		cout<<cnt<<endl;
		for (int i = 0; i <= cnt; ++i) {
      //      cout<<i<<endl;
			if (findPossible(XY, YZ, ZX, i) == "Possible"){
				return "Possible";
			}
		}
		return "Impossible";
	}
};
