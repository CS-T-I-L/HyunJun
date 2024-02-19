/*
 * Problem: https://inha.codetree.ai/missions/2/problems/merge-marbles/description
 * File: Simulation_5_7.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-02-12
 * License: MIT License
 * Comment: ¿Áπ‘¡¥
 */

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m, t;
int grid[50][50]{ 0, };
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
pair<int, int> dir[4] = { {dx[0], dy[0]}, {dx[1], dy[1]},
						{dx[2], dy[2]} , {dx[3], dy[3]} };

class Marble {
public:
	static int idx;
	int series_num_;
	int x_;
	int y_;
	int w_;
	int dir_idx_;
	pair<int, int> dir_;
	bool is_present;

	Marble(int x, int y, char d, int w)
		: series_num_{ idx }, x_{ x }, y_{ y }, w_{ w }, is_present{ true } {
		idx++;
		dir_idx_ = 0;

		if (d == 'U') {
			dir_idx_ = 0;
			dir_ = dir[0];
		}

		else if (d == 'L') {
			dir_idx_ = 1;
			dir_ = dir[1];
		}

		else if (d == 'R') {
			dir_idx_ = 2;
			dir_ = dir[2];
		}

		else if (d == 'D') {
			dir_idx_ = 3;
			dir_ = dir[3];
		}
	}
};

int Marble::idx = 1;

bool is_range(int x, int y) {
	return (x >= 0 && x < n&& y >= 0 && y < n);
}

bool is_wall(Marble* m) {
	if (m->x_ == 0 && m->dir_idx_ == 0) {
		return true;
	}

	else if (m->x_ == n - 1 && m->dir_idx_ == 3) {
		return true;
	}

	else if (m->y_ == 0 && m->dir_idx_ == 1) {
		return true;
	}

	else if (m->y_ == n - 1 && m->dir_idx_ == 2) {
		return true;
	}

	return false;
}

bool cmp(Marble* m1, Marble* m2) {
	return (m1->series_num_ < m2->series_num_);
}

int main() {
	vector<Marble*> marbles;

	cin >> n >> m >> t;

	while (m--) {
		int r, c, w; char d;
		cin >> r >> c >> d >> w;
		r--; c--;

		Marble* marble = new Marble(r, c, d, w);
		marbles.push_back(marble);
		grid[r][c]++;
	}

	while (t--) {
		int grid_next[50][50];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				grid_next[i][j] = grid[i][j];
			}
		}

		for (auto it = marbles.begin(); it != marbles.end(); it++) {
			if ((*it)->is_present) {
				if (is_wall((*it))) {
					(*it)->dir_idx_ = 3 - (*it)->dir_idx_;
					(*it)->dir_ = dir[(*it)->dir_idx_];
					continue;
				}

				grid_next[(*it)->x_][(*it)->y_]--;

				(*it)->x_ = (*it)->x_ + (*it)->dir_.first;
				(*it)->y_ = (*it)->y_ + (*it)->dir_.second;

				grid_next[(*it)->x_][(*it)->y_]++;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid_next[i][j] > 1) {
					vector<Marble*> v_temp;

					for (auto it = marbles.begin(); it != marbles.end(); it++) {
						if ((*it)->is_present && (*it)->x_ == i && (*it)->y_ == j) {
							v_temp.push_back(*it);
						}
					}

					sort(v_temp.begin(), v_temp.end(), cmp);

					int w_temp = v_temp.back()->w_;

					for (int k = 0; k < v_temp.size() - 1; k++) {
						w_temp += v_temp[k]->w_;
						v_temp[k]->is_present = false;
					}

					v_temp.back()->w_ = w_temp;

					grid_next[i][j] = 1;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				grid[i][j] = grid_next[i][j];
			}
		}
	}

	int num_marble = 0;

	for (auto it = marbles.begin(); it != marbles.end(); it++) {
		if ((*it)->is_present) {
			num_marble++;
		}
	}

	int w_max = 0;

	for (auto it = marbles.begin(); it != marbles.end(); it++) {
		if ((*it)->is_present && (*it)->w_ > w_max) {
			w_max = (*it)->w_;
		}
	}

	cout << num_marble << ' ' << w_max;
}