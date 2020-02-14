#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <bitset>
#define N 2502
using namespace std;
class StringTransformation {
	public:
		bitset<N>l[N];
		bitset<N>r[N];
		bitset<N>eq;
		bitset<N>dp[N];
		bitset<N>can[N][3];
		string getResult(string s, string t) {
			int n = s.size();
			int m = t.size();
			for (int i = 0; i < n - 1; ++i) {
				l[i][i+1] = 1;
				r[i+1][i] = 1;
				if (s[i] == s[i+1]) eq[i] = 1;
				int v = (s[i+1] == 'R' ? 0 : (s[i+1] == 'G' ? 1 : 2));
				can[i][v][i+1] = 1;
			}
			for (int i = n-1; i >= 0; --i) {
				for (int j = i + 2; j < n; ++j) {
				//	int j = i + len;
					int v = (s[j] == 'R' ? 0 : (s[j] == 'G' ? 1 : 2));
					if (s[i] == s[j]) continue;
					if ((l[i] & (r[j]>>1) & eq).count() > 0) {
						l[i][j] = 1;
						r[j][i] = 1;
						can[i][v][j] = 1;
					}
				}
			}
		//	for (int i = 0; i < n; ++i) {
		//		cout<<i<<endl;
		//		for (int j = 0; j < 3; ++j) {
		//			cout<<can[i][j]<<" ";
		//		}
		//		cout<<endl;
		//	}
		//	for (int i = 0; i < n; ++i) {
		//		cout<<can[3][2][i]<<endl;
		//	}
			if (s[0] != t[0]) return "NO";
			dp[0][0] = 1;
			for (int i = 0; i < m - 1; ++i) {
				for (int j = 0; j < n - 1; ++j) {
					if (dp[i][j]) {
						int v = (t[i+1] == 'R' ? 0 : (t[i+1] == 'G' ? 1 : 2));
						dp[i+1] |= (can[j][v]);
					}
				}
			}
			return (dp[m-1][n-1] ? "YES" : "NO");
		}
};
