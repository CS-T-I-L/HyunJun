/*
 * Problem: https://inha.codetree.ai/missions/2/problems/falling-horizontal-block/description
 * File: Simulation_4_2.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-02-06
 * License: MIT License
 * Comment: 중첩 조건 꼼꼼히!
 */

#include <iostream>
using namespace std;

int n, m, k;
int dy = 1;
int grid[100][100];
bool is_range(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n);
}

int main() {
	cin >> n >> m >> k;
	k--;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	int c_y = 0;

	for (int j = k; j < k + m; j++) {
		grid[c_y][j] = 1;
	}

	while (true) {
		bool move_below = true;
		int n_y = c_y + dy;

		for (int j = k; j < k + m; j++) {
			if (!is_range(n_y, j) || grid[n_y][j] == 1) {
				move_below = false;
				break;
			}
		}

		if (!move_below) {
			break;
		}

		for (int j = k; j < k + m; j++) {
			grid[c_y][j] = 0;
			grid[n_y][j] = 1;
		}
		
		c_y = n_y;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << grid[i][j] << ' ';
		}
		cout << '\n';
	}
}
