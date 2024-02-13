/*
 * Problem: https://inha.codetree.ai/missions/2/problems/roll-a-dice/description
 * File: Simulation_4_4.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-02-06
 * License: MIT License
 * Comment: 재밌누
 */

#include <iostream>
using namespace std;

class Dice {
public:
	int side_upper;
	int side_base;
	int side_front;
	int side_back;
	int side_right;
	int side_left;

	Dice() {
		side_upper = 1;
		side_front = 2;
		side_right = 3;
		side_base = 7 - side_upper;
		side_back = 7 - side_front;
		side_left = 7 - side_right;
	}
};

int n, m, r, c;
int grid[100][100];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

bool is_range(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n);
}

int main() {
	Dice dice;

	cin >> n >> m >> r >> c;
	r--; c--;
	int c_x = r;
	int c_y = c;
	grid[r][c] = dice.side_base;

	while (m--) {
		char roll; cin >> roll;
		int n_x, n_y;

		if (roll == 'L') {
			n_x = c_x + dx[0];
			n_y = c_y + dy[0];

			if (is_range(n_x, n_y)) {
				dice.side_upper = dice.side_right;
				dice.side_right = dice.side_base;
				dice.side_base = 7 - dice.side_upper;
				dice.side_back = 7 - dice.side_front;
				dice.side_left = 7 - dice.side_right;

				c_x = n_x;
				c_y = n_y;

				grid[c_x][c_y] = dice.side_base;
			}
		}

		else if (roll == 'R') {
			n_x = c_x + dx[1];
			n_y = c_y + dy[1];

			if (is_range(n_x, n_y)) {
				dice.side_right = dice.side_upper;
				dice.side_upper = dice.side_left;
				dice.side_base = 7 - dice.side_upper;
				dice.side_back = 7 - dice.side_front;
				dice.side_left = 7 - dice.side_right;

				c_x = n_x;
				c_y = n_y;

				grid[c_x][c_y] = dice.side_base;
			}
		}

		else if (roll == 'U') {
			n_x = c_x + dx[2];
			n_y = c_y + dy[2];

			if (is_range(n_x, n_y)) {
				dice.side_upper = dice.side_front;
				dice.side_front = dice.side_base;
				dice.side_base = 7 - dice.side_upper;
				dice.side_back = 7 - dice.side_front;
				dice.side_left = 7 - dice.side_right;

				c_x = n_x;
				c_y = n_y;

				grid[c_x][c_y] = dice.side_base;
			}
		}

		else if (roll == 'D') {
			n_x = c_x + dx[3];
			n_y = c_y + dy[3];

			if (is_range(n_x, n_y)) {
				dice.side_front = dice.side_upper;
				dice.side_upper = dice.side_back;
				dice.side_base = 7 - dice.side_upper;
				dice.side_back = 7 - dice.side_front;
				dice.side_left = 7 - dice.side_right;

				c_x = n_x;
				c_y = n_y;

				grid[c_x][c_y] = dice.side_base;
			}
		}
	}

	int sum = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] != 0) {
				sum += grid[i][j];
			}
		}
	}

	cout << sum;
}
