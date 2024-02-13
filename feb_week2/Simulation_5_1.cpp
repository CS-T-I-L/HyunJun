/*
 * Problem: https://inha.codetree.ai/missions/2/problems/move-to-max-adjacent-cell-simultaneously/introduction
 * File: Simulation_5_1.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-02-07
 * License: MIT License
 * Comment: = 대신 == 써서 30분 날림; 비응
 */

#include <iostream>
#include <tuple>
using namespace std;

int n, m, t;
int grid[20][20];
int num_marble[20][20];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool is_range(int x, int y) {
	return (x >= 0 && x < n&& y >= 0 && y < n);
}

int main() {
	cin >> n >> m >> t;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	while (m--) {
		int r, c; cin >> r >> c;
		r--; c--;

		num_marble[r][c]++;
	}

	while (t--) {
		int num_next_marble[20][20];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				num_next_marble[i][j] = num_marble[i][j];
			}
		}


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (num_marble[i][j] != 0) {
					int max = 0;
					pair<int, int> pos_max;

					for (int k = 0; k < 4; k++) {
						int n_x = i + dx[k];
						int n_y = j + dy[k];

						if (is_range(n_x, n_y) && grid[n_x][n_y] > max) {
							max = grid[n_x][n_y];
							pos_max = { n_x, n_y };
						}
					}

					num_next_marble[i][j]--;
					num_next_marble[pos_max.first][pos_max.second]++;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (num_next_marble[i][j] > 1) {
					num_next_marble[i][j] = 0;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				num_marble[i][j] = num_next_marble[i][j];
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (num_marble[i][j] == 1) {
				ans++;
			}
		}
	}

	cout << ans;
}