/*
 * Problem: https://inha.codetree.ai/missions/2/problems/number-of-happy-sequence/description
 * File: Simulation_1_2.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-01-25
 * License: MIT License
 */

#include <iostream>
using namespace std;

int grid[100][100];

int main() {
	int m, n;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	if (n == 1 && m == 1) {
		cout << 2;
		return 0;
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		int cont = 1;
		for (int j = 1; j < n; j++) {
			if (grid[i][j] == grid[i][j - 1]) {
				cont++;
			}
			else {
				cont = 1;
			}
			if (cont >= m) {
				ans++;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int cont = 1;
		for (int j = 1; j < n; j++) {
			if (grid[j][i] == grid[j - 1][i]) {
				cont++;
			}
			else {
				cont = 1;
			}
			if (cont >= m) {
				ans++;
				break;
			}
		}
	}

	cout << ans;
}
