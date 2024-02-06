/*
 * Problem: https://inha.codetree.ai/missions/2/problems/move-to-larger-adjacent-cell/description
 * File: Simulation_4_1.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-02-06
 * License: MIT License
 * Comment: is_range 빠뜨리지 않기!
 */

#include <iostream>
using namespace std;

int n, r, c;
int grid[100][100];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
bool is_range(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n);
}

int main() {
	cin >> n >> r >> c;
	r--; c--;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	int c_x = c;
	int c_y = r;
	cout << grid[c_y][c_x] << ' ';

	while (true) {
		bool flag = false;

		for (int i = 0; i < 4; i++) {
			int n_x = c_x + dx[i];
			int n_y = c_y + dy[i];

			if (is_range(n_x, n_y) && (grid[n_y][n_x] > grid[c_y][c_x])) {
				c_x = n_x;
				c_y = n_y;
				flag = true;
				cout << grid[c_y][c_x] << ' ';
				break;
			}
		}

		if (!flag) {
			break;
		}
	}
}
