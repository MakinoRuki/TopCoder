#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 21
using namespace std;
class UniformBoard{
	public:
		int n;
		int a[N][N],p[N][N];
		int getBoard(vector<string> board, int K){
			n=board.size();
			memset(a,0,sizeof(a));
			memset(p,0,sizeof(p));
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1];
					p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1];
					if(board[i-1][j-1]=='A'){
						a[i][j] ++;
					} else if(board[i-1][j-1]=='P'){
						p[i][j] ++;
					}
				}
			}
		//	int tot=a[n][n] + p[n][n];
			int ans=0;
			if(a[n][n]==0)return 0;
			for(int x1=1;x1<=n;++x1){
				for(int y1=1;y1<=n;++y1){
					for(int x2=x1;x2<=n;++x2){
						for(int y2=y1;y2<=n;++y2){
								int area=(x2-x1+1) * (y2-y1+1);
								if(area > a[n][n])
									continue;
								int apple=a[x2][y2]-a[x1-1][y2]-a[x2][y1-1] + a[x1-1][y1-1];
								int pear=p[x2][y2]-p[x1-1][y2]-p[x2][y1-1] + p[x1-1][y1-1];
								if(apple == area){
									ans=max(ans,area);
								//	if(ans==24)return apple;
								} else {
									if(area - apple + n*n-area-(a[n][n]+p[n][n]-apple-pear) >= pear){
										if(a[n][n] + p[n][n] < n*n && pear+area-apple <= K){
											ans=max(ans,area);
										//	if(ans==24)return apple;
										}
									}
								}
						}
					}
				}
			}
			return ans;
		}
};
