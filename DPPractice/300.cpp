#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1002
using namespace std;
class EmoticonsDiv2 {
	public:
		int dp[N];
		int printSmiles(int sms) {
			for (int i = 1; i <= sms; ++i) {
				if (i==1) dp[i] = 0;
				else {
					dp[i] = i;
					for (int j = 1; j < sms; ++j) {
						if (i % j == 0) {
							int d = i/j;
							dp[i] = min(dp[i], dp[j]+d);
						}
					}
				}
			}
			return dp[sms];
		}
};
