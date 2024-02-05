/*
 * Problem: https://inha.codetree.ai/missions/2/problems/The-2D-bomb-game/description
 * File: Simulation_3_6.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-02-05
 * License: MIT License
 * Comment: m(폭발하는 연속되는 폭탄 개수)가 1이면 따로 예외처리!
 */

#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int grid[100][100];

void explosion() {
	while (true) {
		bool flag = false;

		for (int j = 0; j < n; j++) {
			vector<pair<int, int>> to_exp;

			int s = 0;
			int e = 0;

			for (int i = 1; i < n; i++) {
				if (grid[i][j] == grid[i - 1][j] && grid[i][j] != 0) {
					e++;
				}

				else {
					if (e - s >= m - 1) {
						to_exp.push_back({ s, e });
						flag = true;
					}
					s = i;
					e = i;
				}
			}

			if (e - s >= m - 1) {
				to_exp.push_back({ s, e });
				flag = true;
			}

			if (to_exp.empty()) {
				continue;
			}

			vector<int> v;
			int num_zero = 0;

			for (int i = n - 1; i >= 0; i--) {
				bool flag = false;
				for (int j = 0; j < to_exp.size(); j++) {
					if (i >= to_exp[j].first && i <= to_exp[j].second) {
						num_zero++;
						flag = true;
					}
				}
				if (!flag) {
					v.push_back(grid[i][j]);
				}
			}

			for (int i = 0; i < num_zero; i++) {
				v.push_back(0);
			}

			for (int i = n - 1; i >= 0; i--) {
				grid[i][j] = v[n - 1 - i];
			}
		}

		if (!flag) {
			break;
		}
	}

	int temp[100][100];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = grid[n - 1 - j][i];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			grid[i][j] = temp[i][j];
		}
	}

	for (int j = 0; j < n; j++) {
		vector<int> v;
		int num_zero = 0;

		for (int i = n - 1; i >= 0; i--) {
			if (grid[i][j] == 0) {
				num_zero++;
			}
			else {
				v.push_back(grid[i][j]);
			}
		}

		for (int i = 0; i < num_zero; i++) {
			v.push_back(0);
		}

		for (int i = n - 1; i >= 0; i--) {
			grid[i][j] = v[n - 1 - i];
		}
	}

	while (true) {
		bool flag = false;

		for (int j = 0; j < n; j++) {
			vector<pair<int, int>> to_exp;


			int s = 0;
			int e = 0;

			for (int i = 1; i < n; i++) {
				if (grid[i][j] == grid[i - 1][j] && grid[i][j] != 0) {
					e++;
				}

				else {
					if (e - s >= m - 1) {
						to_exp.push_back({ s, e });
						flag = true;
					}
					s = i;
					e = i;
				}
			}

			if (e - s >= m - 1) {
				to_exp.push_back({ s, e });
				flag = true;
			}

			if (to_exp.empty()) {
				continue;
			}

			vector<int> v;
			int num_zero = 0;

			for (int i = n - 1; i >= 0; i--) {
				bool flag = false;
				for (int j = 0; j < to_exp.size(); j++) {
					if (i >= to_exp[j].first && i <= to_exp[j].second) {
						num_zero++;
						flag = true;
					}
				}
				if (!flag) {
					v.push_back(grid[i][j]);
				}
			}

			for (int i = 0; i < num_zero; i++) {
				v.push_back(0);
			}

			for (int i = n - 1; i >= 0; i--) {
				grid[i][j] = v[n - 1 - i];
			}
		}

		if (!flag) {
			break;
		}
	}
}

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	if (m == 1) {
		cout << 0;
		return 0;
	}

	while (k--) {
		explosion();
	}

	int num_bomb = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] != 0) {
				num_bomb++;
			}
		}
	}

	cout << num_bomb;
}