#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define N 102
using namespace std;
#define inf 1000000000
class AlienAndHamburgers {
public:
	int n;
	int val[N];
	int getNumber(vector<int> type, vector<int> taste) {
		for (int i = 1; i <= 100; ++i) {
			val[i] = -inf;
		}
		for (int i = 0; i < n; ++i) {
			int t = type[i];
			int v = taste[i];
			if (v >= 0) {
				if (val[t] < 0) val[t] = v;
				else val[t] += v;
			} else {
				if (val[t] < 0) val[t] = max(val[t], v);
			}
		}
		vector<int> rks;
		rks.clear();
		for (int i = 1; i <= 100; ++i) {
			if (val[i] > -inf) rks.push_back(val[i]);
		}
		sort(rks.begin(), rks.end());
		int ans = 0;
		int sum = 0;
		for (int i = 1; i <= rks.size(); ++i) {
			sum += rks[size() - i];
			if (sum * i > ans) ans = i * sum;
		}
		return ans;
	}
};

/*#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define inf 1000000000
#define N 52
using namespace std;
class AlienAndHamburgers{
      public:
             int n;
            // vector<int>kind;
           //  int f[N][N];
    		 int tot[N*2];
             int maxv[N*2];
             int getNumber(vector<int>type, vector<int>taste){
                 n = type.size();
                 memset(tot, -1, sizeof(tot));
                 for (int i = 1; i <= 100; ++i) {
                    maxv[i] = -inf;
                 }
                 for (int i = 0; i < n; ++i) {
                    if (taste[i] >= 0) {
                        if (tot[type[i]]<0) tot[type[i]] = taste[i];
                        else tot[type[i]] += taste[i];
                    } else {
                        maxv[type[i]] = max(maxv[type[i]], taste[i]);
                    }
                 }
                 vector<int> rk;
                 rk.clear();
                 for (int i = 1; i <= 100; ++i) {
                    if (tot[i] >= 0) {
                        rk.push_back(tot[i]);
                    } else if (maxv[i] > -inf) {
                        rk.push_back(maxv[i]);
                    }
                 }
                 sort(rk.begin(), rk.end());
                 reverse(rk.begin(), rk.end());
                 int ans=0;
                 int sum=0;
                 for (int i = 1; i <= rk.size(); ++i) {
                    sum += rk[i-1];
                    ans = max(ans, i * sum);
                 }
               /*  int Y = 0;
                 int A = 0;
                 n = type.size();
                 kind.clear();
                 for(int i = 1;i<=100;++i){
                         int tmp = -inf;
                         int sum = 0;
                         for(int j = 0;j<n;++j)
                                 if(type[j]==i){
                                     tmp = max(tmp,taste[j]);
                                     if(taste[j]>=0)
                                          sum+=taste[j];
                                 }        
                         if(tmp>=0){
                                    Y++;
                                    A+=sum;
                         }
                         else if(tmp>-inf){
                              kind.push_back(tmp);
                         }
                 }
                 for(int i = 0;i<=kind.size();++i)
                         for(int j = 0;j<=kind.size();++j)
                               f[i][j] = -inf;
                 f[0][0] = 0;
                 for(int i = 1;i<=kind.size();++i){
                         f[i][0] = 0;
                         for(int j = 1;j<=i;++j){
                                 f[i][j] = f[i-1][j];
                                 if(f[i-1][j-1]>-inf)
                                    f[i][j] = max(f[i][j],f[i-1][j-1]+kind[i-1]);
								//	return f[i][j];                                  
                         }
                 }
                 
                 int ans = Y*A;
                 for(int i = 0;i<=kind.size();++i)
                         ans = max(ans,(Y+i)*(A+f[kind.size()][i])); */
                 return ans;
             }
};*/
