#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class Decipherability {
	public:
		string check (string s, int k) {
			int n = s.size();
			if (k == n) return "Certain";
			for (int i = 0; i < n; ++i) {
				for (int j = 1; j <= k; ++j) {
					if (s[i] == s[i - j]) return "Uncertain";
				}
			}
			return "Certain";
		}
};
