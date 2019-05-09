#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

double dp[2510];

class Consensus {
	public:
	double expectedTime(vector <int> O) {
		memset(dp, 0, sizeof(dp));
		int S=0;
		for (auto v : O) S+=v;
		dp[1]=(double)(S-1)*(S-1)/(double)S;
		for (int i = 1; i < S; ++i) {
			dp[i+1]=2.0*dp[i]-dp[i-1]-(double)(S-1)/(double)(S-i);
		}
		
		double ret=0;
		for(auto v : O) ret+=dp[v];
		
		return ret;
	}
};
