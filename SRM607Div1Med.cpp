#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class CombinationLockDiv1 {
	public:
		int n;
		int minimumMoves (vector<string> P, vector<string> Q) {
			vector<int> R, S;
			R.clear();
			S.clear();
			string Ps = "", Qs = "";
			for (int i = 0; i < P.size(); ++i) {
				Ps += P[i];
			}
			for (int i = 0; i < Q.size(); ++i) {
				Qs += Q[i];
			}
			n = Ps.size();
			for (int i = 0; i < n; ++i) {
				int Pi = Ps[i] - '0';
				int Qi = Qs[i] - '0';
				R.push_back((Pi - Qi + 10) % 10);
			}
			for (int i = 0; i < n; ++i) {
				if (i == 0) S.push_back(R[i]);
				else S.push_back((R[i] - R[i - 1] + 10) % 10);
			}
			sort(S.begin(), S.end());
			int ans = 1000000000;
			for (int i = 0; i <= n; ++i) {
				int up = 0, down = 0;
				for (int j = 0; j < n; ++j) {
					if (j < i) down += S[j];
					else up += (10 - S[j]);
				}
				ans = min(ans, max(up, down));
			}
			return ans;
		}
};
