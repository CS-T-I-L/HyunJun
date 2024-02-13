/*
 * Problem: https://inha.codetree.ai/missions/2/problems/pinball-game/description
 * File: Simulation_4_7.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-02-07
 * License: MIT License
 * Comment: 격자 바깥에서 시작 시 격자 바깥 점 그대로 시작점으로 잡기! (처음 만나는 격자 내부 점에서 조건 발동 가능)
 */

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n;
int grid[100][100];

bool is_range(int x, int y) {
	return (x >= 0 && x < n&& y >= 0 && y < n);
}

pair<int, int> rotate_1(pair<int, int> dir) {
	if (dir.first == 0 && dir.second == 1) {
		return { -1, 0 };
	}

	else if (dir.first == -1 && dir.second == 0) {
		return { 0, 1 };
	}

	else if (dir.first == 0 && dir.second == -1) {
		return { 1, 0 };
	}

	else if (dir.first == 1 && dir.second == 0) {
		return { 0, -1 };
	}
}

pair<int, int> rotate_2(pair<int, int> dir) {
	if (dir.first == 0 && dir.second == 1) {
		return { 1, 0 };
	}

	else if (dir.first == -1 && dir.second == 0) {
		return { 0, -1 };
	}

	else if (dir.first == 0 && dir.second == -1) {
		return { -1, 0 };
	}

	else if (dir.first == 1 && dir.second == 0) {
		return { 0, 1 };
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	int c_x, c_y;
	pair<int, int> cur_dir;
	vector<int> times;

	for (int i = 0; i < n; i++) {
		c_x = i; c_y = -1;
		cur_dir = { 0, 1 };

		int t = 0;

		do {
			int n_x = c_x + cur_dir.first;
			int n_y = c_y + cur_dir.second;

			c_x = n_x;
			c_y = n_y;

			if (grid[c_x][c_y] == 1) {
				cur_dir = rotate_1(cur_dir);
			}

			else if (grid[c_x][c_y] == 2) {
				cur_dir = rotate_2(cur_dir);
			}

			t++;
		} while (is_range(c_x, c_y));

		times.push_back(t);
	}

	for (int j = 0; j < n; j++) {
		c_x = n; c_y = j;
		cur_dir = { -1, 0 };

		int t = 0;

		do {
			int n_x = c_x + cur_dir.first;
			int n_y = c_y + cur_dir.second;

			c_x = n_x;
			c_y = n_y;

			if (grid[c_x][c_y] == 1) {
				cur_dir = rotate_1(cur_dir);
			}

			else if (grid[c_x][c_y] == 2) {
				cur_dir = rotate_2(cur_dir);
			}

			t++;
		} while (is_range(c_x, c_y));

		times.push_back(t);
	}

	for (int i = 0; i < n; i++) {
		c_x = i; c_y = n;
		cur_dir = { 0, -1 };

		int t = 0;

		do {
			int n_x = c_x + cur_dir.first;
			int n_y = c_y + cur_dir.second;

			c_x = n_x;
			c_y = n_y;

			if (grid[c_x][c_y] == 1) {
				cur_dir = rotate_1(cur_dir);
			}

			else if (grid[c_x][c_y] == 2) {
				cur_dir = rotate_2(cur_dir);
			}

			t++;
		} while (is_range(c_x, c_y));

		times.push_back(t);
	}

	for (int j = 0; j < n; j++) {
		c_x = -1; c_y = j;
		cur_dir = { 1, 0 };

		int t = 0;

		do {
			int n_x = c_x + cur_dir.first;
			int n_y = c_y + cur_dir.second;

			c_x = n_x;
			c_y = n_y;

			if (grid[c_x][c_y] == 1) {
				cur_dir = rotate_1(cur_dir);
			}

			else if (grid[c_x][c_y] == 2) {
				cur_dir = rotate_2(cur_dir);
			}

			t++;
		} while (is_range(c_x, c_y));

		times.push_back(t);
	}

	sort(times.begin(), times.end());

	cout << times.back();
}