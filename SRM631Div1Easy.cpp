#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
class TaroJiroGrid {
	public:
		bool check (vector<string> grid) {
			int n = grid.size();
			for (int j = 0; j < n; ++j) {
				char pre = ' ';
				int cnt = 0;
				for (int i = 0; i < n; ++i) {
					if (i == 0) {
						pre = grid[i][j];
						cnt = 1;
					} else {
						if (grid[i][j] == pre) {
							cnt++;
						} else {
							pre = grid[i][j];
							cnt = 1;
						}
					}
					if (cnt > n / 2) {
						return false;
					}
				}
			}
			return true;
		}
		int getNumber (vector<string> grid) {
			if (check(grid)){
				return 0;
			}
			int n = grid.size();
			for (int i = 0; i < n; ++i) {
				string tmp = grid[i];
				for (int j = 0; j < n; ++j) {
					grid[i][j] = 'W';
				}
				if (check(grid)) return 1;
				for (int j = 0; j < n; ++j) {
					grid[i][j] = 'B';
				}
				if (check(grid)) return 1;
				grid[i] = tmp;
			}
			return 2;
		}
};
