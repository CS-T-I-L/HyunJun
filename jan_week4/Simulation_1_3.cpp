/*
 * Problem: https://inha.codetree.ai/missions/2/problems/tromino/description
 * File: Simulation_1_3.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-01-25
 * License: MIT License
 */

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int grid[200][200];

int block(int i, int j) {
	int maxi = 0;
	int sum = 0;

	if (i + 1 < n && j - 1 >= 0) {
		sum += (grid[i][j] + grid[i + 1][j - 1] + grid[i + 1][j]);
		maxi = max(maxi, sum);
		sum = 0;
	}

	if (i + 1 < n && j + 1 < m) {
		sum += (grid[i][j] + grid[i + 1][j] + grid[i + 1][j + 1]);
		maxi = max(maxi, sum);
		sum = 0;
	}

	if (i + 1 < n && j + 1 < m) {
		sum += (grid[i][j] + grid[i + 1][j] + grid[i][j + 1]);
		maxi = max(maxi, sum);
		sum = 0;
	}

	if (i + 1 < n && j + 1 < m) {
		sum += (grid[i][j] + grid[i][j + 1] + grid[i + 1][j + 1]);
		maxi = max(maxi, sum);
		sum = 0;
	}

	if (i + 2 < n) {
		sum += (grid[i][j] + grid[i + 1][j] + grid[i + 2][j]);
		maxi = max(maxi, sum);
		sum = 0;
	}

	if (j + 2 < m) {
		sum += (grid[i][j] + grid[i][j + 1] + grid[i][j + 2]);
		maxi = max(maxi, sum);
		sum = 0;
	}

	return maxi;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = max(ans, block(i, j));
		}
	}

	cout << ans;
}
