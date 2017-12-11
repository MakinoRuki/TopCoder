#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class OrAndSum {
public:
    string isPossible(vector<ll> pairOr, vector<ll> pairSum) {
        int n = pairOr.size();
        for (int i = 0; i < n; ++i) {
        	if (pairSum[i] < pairOr[i]) return "Impossible";
        }
        for (int i = 0; i <= 60; ++i) {
            vector<int>bits(n + 1, -1);
            for (int j = 0; j < n; ++j) {
                ll tmp = pairSum[j] - pairOr[j];
                int n1 = ((tmp >> i) & 1);
                int n0 = ((pairOr[j] >> i) & 1);
                if (n1) {
                    if (!n0) {
                        return "Impossible";
                    }
                    if (bits[j] == 0 || bits[j + 1] == 0) return "Impossible";
                    bits[j] = 1;
                    bits[j + 1] = 1;
                } else {
                    if (n0) continue;
                    if (bits[j] == 1 || bits[j + 1] == 1) return "Impossible";
                    bits[j] = 0;
                    bits[j + 1] = 0;
                }
            }
            int j;
            for (j = 0; j <= n; ++j) {
                if (bits[j] != -1) break;
            }
            for (int k = j - 1; k >= 0; --k) {
            	ll tmp = pairSum[k] - pairOr[k];
            	if (((pairOr[k] >> i) & 1) && !((tmp >> i) & 1)) {
            		if (bits[k] == -1) bits[k] = !bits[k + 1];
            		else if (bits[k] != !bits[k + 1]) return "Impossible";
            	}
            }
            for (int k = j; k < n; ++k) {
            	ll tmp = pairSum[k] - pairOr[k];
            	if (((pairOr[k] >> i) & 1) && !((tmp >> i) & 1)) {
            		if (bits[k + 1] == -1) bits[k + 1] = !bits[k];
            		else if (bits[k + 1] != !bits[k]) return "Impossible";
            	}
            }
        }
        return "Possible";
    }
};
