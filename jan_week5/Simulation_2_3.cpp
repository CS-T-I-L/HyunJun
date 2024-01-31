/*
 * Problem: https://inha.codetree.ai/missions/2/problems/The-1D-wind-blows/description
 * File: Simulation_2_3.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-01-31
 * License: MIT License
 */

#include <iostream>
using namespace std;

int n, m, q;
int r;
char d;
int grid[100][100];

void L2R(int row) {
	int temp = grid[row][m - 1];
	for (int i = m - 1; i > 0; i--) {
		grid[row][i] = grid[row][i - 1];
	}
	grid[row][0] = temp;
}

void R2L(int row) {
	int temp = grid[row][0];
	for (int i = 0; i < m - 1; i++) {
		grid[row][i] = grid[row][i + 1];
	}
	grid[row][m - 1] = temp;
}

bool check_up_sp(int row) {
	if (row == 0) {
		return false;
	}

	for (int i = 0; i < m; i++) {
		if (grid[row][i] == grid[row - 1][i]) {
			return true;
		}
	}

	return false;
}

bool check_down_sp(int row) {
	if (row == n) {
		return false;
	}

	for (int i = 0; i < m; i++) {
		if (grid[row][i] == grid[row - 1][i]) {
			return true;
		}
	}

	return false;
}

bool flag;

int main() {
	cin >> n >> m >> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	while (q--) {
		cin >> r >> d;

		r--;
		int r_ = r;

		if (d == 'L') {
			flag = true;
			L2R(r_);
		}
		else if (d == 'R') {
			flag = false;
			R2L(r_);
		}

		bool flag_ = flag;

		while (check_up_sp(r_)) {
			flag_ = !flag_;

			if (flag_) {
				L2R(r_ - 1);
			}
			else {
				R2L(r_ - 1);
			}

			r_--;
		}

		r_ = r + 1;
		flag_ = flag;

		while (check_down_sp(r_)) {
			flag_ = !flag_;

			if (flag_) {
				L2R(r_);
			}
			else {
				R2L(r_);
			}

			r_++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << grid[i][j] << " ";
		}
		cout << '\n';
	}
}