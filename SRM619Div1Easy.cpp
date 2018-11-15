#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class SplitStoneGame {
public:
	int n;
	string winOrLose(vector<int> number) {
		n = number.size();
		sort(number.begin(), number.end());
		if (n <= 2) return "LOSE";
		if (number[n - 1] == 1) return "LOSE";
		if (n % 2) return "WIN";
		return "LOSE";
	}
};
