/*
 * Problem: https://inha.codetree.ai/problems/cross-shape-bomb/description
 * File: Simulation_3_2.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-02-02
 * License: MIT License
 */

#include <iostream>
#include <vector>
using namespace std;

int n;
int grid[200][200];
bool to_delete[200][200];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	int r, c;
	cin >> r >> c;
	r--; c--;

	int num = grid[r][c] - 1;

	int s_r = r - num;
	if (r - num < 0) {
		s_r = 0;
	}

	int e_r = r + num;
	if (r + num > n - 1) {
		e_r = n - 1;
	}

	int s_c = c - num;
	if (c - num < 0) {
		s_c = 0;
	}

	int e_c = c + num;
	if (c + num > n - 1) {
		e_c = n - 1;
	}

	for (int i = s_r; i <= e_r; i++) {
		to_delete[i][c] = true;
	}

	for (int j = s_c; j <= e_c; j++) {
		to_delete[r][j] = true;
	}

	vector<vector<int>> temp;

	for (int j = s_c; j <= e_c; j++) {
		vector<int> v;
		int num_zero = 0;

		for (int i = n - 1; i >= 0; i--) {
			if (to_delete[i][j]) {
				num_zero++;
			}
			else {
				v.push_back(grid[i][j]);
			}
		}

		for (int i = 0; i < num_zero; i++) {
			v.push_back(0);
		}

		temp.push_back(v);
	}

	int idx = 0;
	for (int j = s_c; j <= e_c; j++) {
		for (int i = n - 1; i >= 0; i--) {
			grid[i][j] = temp[idx][n - 1 - i];
		}

		idx++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << grid[i][j] << " ";
		}
		cout << '\n';
	}
}