/*
 * Problem: https://inha.codetree.ai/missions/2/problems/slanted-rectangle/description
 * File: Simulation_1_5.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-01-26
 * License: MIT License
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int grid[20][20];

bool check(int i, int j) {
	return (i >= 0 && i < n&& j >= 0 && j < n);
}

int get_rectangle_max_sum(int i, int j) {
	int maxi = 0;
	int d_w, d_h;
	vector<pair<int, int>> rectangles;

	for (d_w = 1; d_w <= n - 2; d_w++) {
		for (d_h = 1; d_h <= n - 2; d_h++) {
			if (check(i - d_w, j + d_w) && check(i - d_w - d_h, j + d_w - d_h)
				&& check(i - d_h, j - d_h)) {
				rectangles.push_back(make_pair(d_w, d_h));
			}
		}
	}

	for (auto it = rectangles.begin(); it != rectangles.end(); it++) {
		int cur_i = i;
		int cur_j = j;
		int sum = 0;

		for (int d = 0; d < (*it).first; d++) {
			sum += grid[cur_i--][cur_j++];
		}
		
		for (int d = 0; d < (*it).second; d++) {
			sum += grid[cur_i--][cur_j--];
		}
		
		for (int d = 0; d < (*it).first; d++) {
			sum += grid[cur_i++][cur_j--];
		}
		
		for (int d = 0; d < (*it).second; d++) {
			sum += grid[cur_i++][cur_j++];
		}
		
		maxi = max(maxi, sum);
	}
	return maxi;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int rectangle_sum = get_rectangle_max_sum(i, j);
			ans = max(ans, rectangle_sum);
		}
	}

	cout << ans;
}
