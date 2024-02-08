/*
 * Problem: https://inha.codetree.ai/missions/2/problems/sequential-movement-of-numbers/description
 * File: Simulation_5_2.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-02-08
 * License: MIT License
 * Comment: 조건 좀 잘 확인허자!
 */

#include <iostream>
#include <tuple>
#include <cmath>
using namespace std;

int n, m;
int grid[20][20];
int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[8] = { 1, 0, -1, -1, -1, 0, 1, 1 };

bool is_range(int x, int y) {
	return (x >= 0 && x < n&& y >= 0 && y < n);
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	while (m--) {
		for (int k = 1; k <= pow(n, 2); k++) {
			bool flag_finish = false;

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (grid[i][j] == k) {
						int max = 0;
						pair<int, int> pos_max;

						for (int d = 0; d < 8; d++) {
							int n_x = i + dx[d];
							int n_y = j + dy[d];

							if (is_range(n_x, n_y) && grid[n_x][n_y] > max) {
								max = grid[n_x][n_y];
								pos_max = { n_x, n_y };
							}
						}

						int temp = grid[i][j];
						grid[i][j] = grid[pos_max.first][pos_max.second];
						grid[pos_max.first][pos_max.second] = temp;
						flag_finish = true;
						break;
					}
				}

				if (flag_finish) {
					break;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << grid[i][j] << ' ';
		}
		cout << '\n';
	}
}