#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 100005
using namespace std;
class WaitingForBus {
	public:
		double dp[N];
		int n;
		double whenWillBusArrive(vector <int> time, vector <int> prob, int s) {
			n = time.size();
			for (int i = 0; i <= s; ++i) {
				dp[i] = 0.0;
			}
			dp[0] = 1.0;
			for (int i = 0; i < s; ++i) {
				for (int j = 0; j < n; ++j) {
					if (i + time[j] <= s) {
						dp[i + time[j]] += dp[i] * (double)prob[j] / 100.0;
					}
				}
			}
			double ans = 0.0;
			double pr_sum = 0.0;
			for (int t = 0; t < s; ++t) {
				for (int i = 0; i < n; ++i) {
					if (t + time[i] >= s) {
						ans += (double)(t + time[i] - s) * dp[t] * (double)prob[i] / 100.0;
						pr_sum += dp[t] * (double)prob[i] / 100.0;
					}
				}
			}
			return (pr_sum == 0.0 ? 0 : ans / pr_sum);
		}
};
