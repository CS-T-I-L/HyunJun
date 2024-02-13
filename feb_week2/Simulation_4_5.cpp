/*
 * Problem: https://inha.codetree.ai/missions/2/problems/big-explosion/description
 * File: Simulation_4_5.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-02-06
 * License: MIT License
 * Comment: ½¬¿öÀ×
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m, r, c;
int grid[100][100];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
vector<pair<int, int>> bombs;

bool is_range(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n);
}

int main() {
	cin >> n >> m >> r >> c;
	r--; c--;
	int t = 0;

	bombs.push_back({ r, c });
	grid[r][c] = 1;
	t++;

	while (t <= m) {
		vector<pair<int, int>> temp;

		for (int i = 0; i < bombs.size(); i++) {
			for (int j = 0; j < 4; j++) {
				int n_x = bombs[i].first + pow(2, t - 1) * dx[j];
				int n_y = bombs[i].second + pow(2, t - 1) * dy[j];

				if (is_range(n_x, n_y) && grid[n_x][n_y] == 0) {
					temp.push_back({ n_x, n_y });
					grid[n_x][n_y] = 1;
				}
			}
		}

		bombs.insert(bombs.end(), temp.begin(), temp.end());

		t++;
	}

	cout << bombs.size();
}