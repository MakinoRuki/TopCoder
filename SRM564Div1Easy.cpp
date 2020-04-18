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
#define N 52
using namespace std;
typedef long long ll;
class KnightCircuit2 {
public:
	int maxSize(int w, int h) {
		if (w>h) swap(w,h);
		if (w >= 4) return w*h;
		if (w == 3) {
			if (h==3) return 8;
			return w*h;
		}
		if (w == 2) {
			return (h+1)/2;
		}
		return 1;
	}
};
