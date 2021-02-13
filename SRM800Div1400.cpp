#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 30
#define SZ 200000002
using namespace std;
typedef long long ll;
class MinMaxGame {
public:
	int lastNumber(vector<int> a) {
		int n = a.size();
		if (n%2==0) {
			return min(a[0], a.back());
		} else {
			return max(a[0], a.back());
		}
	}
};
