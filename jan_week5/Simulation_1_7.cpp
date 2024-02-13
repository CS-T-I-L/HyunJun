/*
 * Problem: https://inha.codetree.ai/missions/2/problems/max-area-of-positive-rectangle/description
 * File: Simulation_1_7.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-01-29
 * License: MIT License
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int n, m;
int grid[20][20];

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	vector<tuple<int, int, int, int>> rectangles;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int h = 1; h <= n - i; h++) {
				for (int w = 1; w <= m - j; w++) {
					rectangles.push_back({ i, j, h, w });
				}
			}
		}
	}

	vector<int> sizes;
	for (auto it = rectangles.begin(); it != rectangles.end(); it++) {
		bool flag = true;

		for (int i = get<0>(*it); i < get<0>(*it) + get<2>(*it); i++) {
			for (int j = get<1>(*it); j < get<1>(*it) + get<3>(*it); j++) {
				if (grid[i][j] <= 0) {
					flag = false;
					continue;
				}
			}

			if (!flag) {
				continue;
			}
		}

		if (flag) {
			sizes.push_back(get<2>(*it) * get<3>(*it));
		}
	}

	if (sizes.empty()) {
		cout << -1;
	}
	else {
		sort(sizes.begin(), sizes.end());
		cout << sizes.back();
	}
}