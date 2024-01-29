/*
 * Problem: https://inha.codetree.ai/missions/2/problems/gold-mining/description
 * File: Simulation_1_4.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-01-25
 * License: MIT License
 */

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
int grid[20][20];

bool check(int row, int col) {
	return (row >= 0 && row < n && col >= 0 && col < n);
}

int find_gold(int i, int j, int k) {
	int num = 0;

	for (int row = i - k; row <= i + k; row++) {
		for (int col = j - k; col <= j + k; col++) {
			if ((col - row >= j - i - k && col - row <= j - i + k)
				&& (col + row >= i + j - k && col + row <= i + j + k)
				&& check(row, col)) {
				if (grid[row][col]) {
					num++;
				}
			}
		}
	}

	return num;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k <= (2 * n) - 2; k++) {
				int cost = pow(k, 2) + pow(k + 1, 2);
				int gold_num = find_gold(i, j, k);

				if (gold_num * m >= cost) {
					ans = max(ans, gold_num);
				}
			}
		}
	}

	cout << ans;
}
