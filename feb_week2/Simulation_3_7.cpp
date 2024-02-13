/*
 * Problem: https://inha.codetree.ai/missions/2/problems/best-cross-shape-bomb/description
 * File: Simulation_3_7.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-02-05
 * License: MIT License
 * Comment: 같은 값 확인 시 0 아닌 값인지 확인!
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int grid[50][50];

int explosion(int r, int c) {
	int temp[50][50];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = grid[i][j];
		}
	}

	int num = temp[r][c] - 1;

	int s_r = r - num;
	if (s_r < 0) {
		s_r = 0;
	}

	int e_r = r + num;
	if (e_r >= n) {
		e_r = n - 1;
	}

	int s_c = c - num;
	if (s_c < 0) {
		s_c = 0;
	}

	int e_c = c + num;
	if (e_c >= n) {
		e_c = n - 1;
	}

	for (int i = s_r; i <= e_r; i++) {
		temp[i][c] = 0;
	}

	for (int j = s_c; j <= e_c; j++) {
		temp[r][j] = 0;
	}

	for (int j = s_c; j <= e_c; j++) {
		vector<int> v;
		int num_zero = 0;

		for (int i = n - 1; i >= 0; i--) {
			if (temp[i][j] != 0) {
				v.push_back(temp[i][j]);
			}
			else {
				num_zero++;
			}
		}

		for (int i = 0; i < num_zero; i++) {
			v.push_back(0);
		}

		for (int i = n - 1; i >= 0; i--) {
			temp[i][j] = v[n - 1 - i];
		}
	}

	int num_cont = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j != 0) {
				if (temp[i][j] == temp[i][j - 1] && temp[i][j] != 0) {
					num_cont++;
				}
			}

			if (i != 0) {
				if (temp[i][j] == temp[i - 1][j] && temp[i][j] != 0) {
					num_cont++;
				}
			}
		}
	}

	return num_cont;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	vector<int> ans;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans.push_back(explosion(i, j));
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.back();
}