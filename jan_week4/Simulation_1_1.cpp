/*
 * Problem: https://inha.codetree.ai/missions/2/problems/best-place-of-33/description
 * File: Simulation_1_1.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-01-25
 * License: MIT License
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int grid[20][20];

int count_coin(int row, int col) {
	int num_coin = 0;
	for (int i = row; i < row + 3; i++) {
		for (int j = col; j < col + 3; j++) {
			if (grid[i][j]) {
				num_coin++;
			}
		}
	}
	return num_coin;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	vector<int> num_coins;

	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < n - 2; j++) {
			num_coins.push_back(count_coin(i, j));
		}
	}

	sort(num_coins.begin(), num_coins.end());
	cout << num_coins.back();
}
