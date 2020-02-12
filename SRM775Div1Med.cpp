#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class CardDrawGame {
	public:
		double winChance(int target, vector<int> cnt) {
			double ans = 0.0;
			int n = cnt.size();
			double tot=0.0;
			for (int i = 0; i < n; ++i) {
				tot += cnt[i];
			}
			for (int i = 0; i < n; ++i) {
				if (cnt[i]) {
					double p1 = (double)cnt[i] / tot;
					cnt[i]--;
					tot--;
					for (int j = 0; j < n; ++j) {
						if (cnt[j]) {
							double p2 = p1 * (double)cnt[j] / tot;
							cnt[j]--;
							tot--;
							for (int k = 0; k < n; ++k) {
								if (cnt[k]) {
									double p3 = p2 * (double)cnt[k] / tot;
									cnt[k]--;
									tot--;
									double q[4][62];
									for (int a = 1; a <= 3; ++a) {
										for (int b = 0; b <= 60; ++b) {
											q[a][b]=0.0;
										}
									}
									for (int a = 0; a < n; ++a) {
										if (cnt[a]) {
											double q1 = (double)cnt[a]/tot;
											cnt[a]--;
											tot--;
											q[1][a] += q1;
											for (int b = 0; b < n; ++b) {
												if (cnt[b]) {
													double q2 = q1 * (double)cnt[b]/tot;
													cnt[b]--;
													tot--;
													q[2][a+b] += q2;
													for (int c = 0; c < n; ++c) {
														if (cnt[c]) {
															double q3 = q2 * (double)cnt[c]/tot;
															q[3][a+b+c] += q3;
														}
													}
													cnt[b]++;
													tot++;
												}
											}
											cnt[a]++;
											tot++;
										}
									}
									double cp = 0.0;
									if (i+j+k == target) cp=1.0;
									if (target-i-j >= 0) cp = max(cp, q[1][target-i-j]);
									if (target-j-k >= 0) cp = max(cp, q[1][target-j-k]);
									if (target-i-k >= 0) cp = max(cp, q[1][target-i-k]);
									if (target-i >= 0) cp = max(cp, q[2][target-i]);
									if (target-j >= 0) cp = max(cp, q[2][target-j]);
									if (target-k >= 0) cp = max(cp, q[2][target-k]);
									cp = max(cp, q[3][target]);
									ans += cp * p3;
									cnt[k]++;
									tot++;
								}
							}
							cnt[j]++;
							tot++;
						}
					}
					cnt[i]++;
					tot++;
				}
			}
			return ans;
		}
};
