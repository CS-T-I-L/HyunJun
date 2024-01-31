/*
 * Problem: https://inha.codetree.ai/missions/2/problems/The-2D-wind-blows/description
 * File: Simulation_2_4.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-01-31
 * License: MIT License
 */

#include <iostream>
using namespace std;

int n, m, q;
int grid[100][100];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void shift(int r_1, int c_1, int r_2, int c_2) {
	int temp_1 = grid[r_1][c_2];
	int temp_2 = grid[r_2][c_2];
	int temp_3 = grid[r_2][c_1];

	for (int j = c_2; j > c_1; j--) {
		grid[r_1][j] = grid[r_1][j - 1];
	}

	for (int i = r_2; i > r_1 + 1; i--) {
		grid[i][c_2] = grid[i - 1][c_2];
	}

	for (int j = c_1; j < c_2 - 1; j++) {
		grid[r_2][j] = grid[r_2][j + 1];
	}

	for (int i = r_1; i < r_2 - 1; i++) {
		grid[i][c_1] = grid[i + 1][c_1];
	}

	grid[r_1 + 1][c_2] = temp_1;
	grid[r_2][c_2 - 1] = temp_2;
	grid[r_2 - 1][c_1] = temp_3;
}

bool is_range(int r, int c) {
	return (r >= 0 && r < n&& c >= 0 && c < m);
}

int get_avrg(int r, int c) {
	int sum = grid[r][c];
	int num = 1;

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (is_range(nr, nc)) {
			sum += grid[nr][nc];
			num++;
		}
	}

	return (sum / num);
}

int main() {
	cin >> n >> m >> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	while (q--) {
		int r_1, c_1, r_2, c_2;
		cin >> r_1 >> c_1 >> r_2 >> c_2;
		r_1--; c_1--; r_2--; c_2--;

		shift(r_1, c_1, r_2, c_2);

		int grid_[100][100];

		for (int i = r_1; i <= r_2; i++) {
			for (int j = c_1; j <= c_2; j++) {
				grid_[i][j] = get_avrg(i, j);
			}
		}

		for (int i = r_1; i <= r_2; i++) {
			for (int j = c_1; j <= c_2; j++) {
				grid[i][j] = grid_[i][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << grid[i][j] << " ";
		}
		cout << '\n';
	}
}