/*
 * Problem: https://inha.codetree.ai/missions/2/problems/sequential-movement-of-stacked-numbers/description
 * File: Simulation_5_4.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-02-08
 * License: MIT License
 * Comment: 스택 복사 시 사이즈 값 고정시키기!!!
 */

#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
using namespace std;

int n, m;
stack<int> grid[20][20];
vector<int> grid_[20][20];
int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[8] = { 1, 0, -1, -1, -1, 0, 1, 1 };

bool is_range(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < n);
}

vector<int> copy_s_to_v(stack<int> s) {
	int size = s.size();
	vector<int> v;

	for (int i = 0; i < size; i++) {
		v.push_back(s.top());
		s.pop();
	}

	return v;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num; cin >> num;
			grid[i][j].push(num);
		}
	}

	while (m--) {
		int num; cin >> num;

		pair<int, int> pos_cur;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				vector<int> v = copy_s_to_v(grid[i][j]);

				for (auto it = v.begin(); it != v.end(); it++) {
					if (*it == num) {
						pos_cur = { i, j };
						break;
					}
				}
			}
		}

		int max = 0;
		pair<int, int> err = { -1, -1 };
		pair<int, int> pos_max = err;

		for (int d = 0; d < 8; d++) {
			int n_x = pos_cur.first + dx[d];
			int n_y = pos_cur.second + dy[d];

			if (is_range(n_x, n_y) && !grid[n_x][n_y].empty()) {
				vector<int> v = copy_s_to_v(grid[n_x][n_y]);

				for (auto it = v.begin(); it != v.end(); it++) {
					if (*it > max) {
						max = *it;
						pos_max = { n_x, n_y };
					}
				}
			}
		}

		vector<int> v;

		if (pos_max != err) {
			while (grid[pos_cur.first][pos_cur.second].top() != num) {
				v.push_back(grid[pos_cur.first][pos_cur.second].top());
				grid[pos_cur.first][pos_cur.second].pop();
			}
			v.push_back(grid[pos_cur.first][pos_cur.second].top());
			grid[pos_cur.first][pos_cur.second].pop();

			for (auto it = v.rbegin(); it != v.rend(); it++) {
				grid[pos_max.first][pos_max.second].push(*it);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vector<int> v = copy_s_to_v(grid[i][j]);
			if (v.empty()) {
				cout << "None" << '\n';
				continue;
			}

			for (auto it = v.begin(); it != v.end(); it++) {
				cout << *it << ' ';
			}

			cout << '\n';
		}
	}
}