/*
 * Problem: https://inha.codetree.ai/missions/2/problems/marble-movement/description
 * File: Simulation_5_5.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-02-10
 * License: MIT License
 * Comment: 객체 관리를 위한 배열 생성 시 객체, 배열 모두 포인터 타입으로!! 
 */

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m, t, k;
int num_marble[50][50];
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, 1, -1, 0 };
pair<int, int> dir[4] = { {dx[0], dy[0]}, {dx[1], dy[1]},
							{dx[2], dy[2]}, {dx[3], dy[3]} };

class Marble {
public:
	static int idx;
	int series_num_;
	int x_;
	int y_;
	int vc_;
	bool is_present_;
	pair<int, int> dir_;

	Marble(int x, int y, int vc, char d)
		:series_num_{ idx }, x_{ x }, y_{ y }, vc_{ vc }, is_present_{ true } {
		if (d == 'U') {
			dir_ = dir[0];
		}

		else if (d == 'R') {
			dir_ = dir[1];
		}

		else if (d == 'L') {
			dir_ = dir[2];
		}

		else if (d == 'D') {
			dir_ = dir[3];
		}

		++idx;
	}
};

int Marble::idx = 1;

void set_dir(Marble& marble) {
	if (marble.x_ == 0 && marble.dir_ == dir[0]) {
		marble.dir_ = dir[3];
	}

	else if (marble.x_ == n - 1 && marble.dir_ == dir[3]) {
		marble.dir_ = dir[0];
	}

	else if (marble.y_ == 0 && marble.dir_ == dir[2]) {
		marble.dir_ = dir[1];
	}

	else if (marble.y_ == n - 1 && marble.dir_ == dir[1]) {
		marble.dir_ = dir[2];
	}
}

bool cmp(Marble* m_1, Marble* m_2) {
	if ((*m_1).vc_ < (*m_2).vc_) {
		return true;
	}
	else if ((*m_1).vc_ == (*m_2).vc_) {
		if ((*m_1).series_num_ < (*m_2).series_num_) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int main() {
	cin >> n >> m >> t >> k;

	vector<Marble*> marbles;

	while (m--) {
		int r, c, v;
		char d;
		cin >> r >> c >> d >> v;
		r--; c--;

		num_marble[r][c]++;
		Marble* marble = new Marble(r, c, v, d);
		marbles.push_back(marble);
	}

	while (t--) {
		int num_next_marble[50][50];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				num_next_marble[i][j] = num_marble[i][j];
			}
		}

		for (auto it = marbles.begin(); it != marbles.end(); it++) {
			if ((*(*it)).is_present_) {
				for (int num_move = 0; num_move < (*(*it)).vc_; num_move++) {
					num_next_marble[(*(*it)).x_][(*(*it)).y_]--;

					set_dir(*(*it));
					(*(*it)).x_ = (*(*it)).x_ + (*(*it)).dir_.first;
					(*(*it)).y_ = (*(*it)).y_ + (*(*it)).dir_.second;

					num_next_marble[(*(*it)).x_][(*(*it)).y_]++;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (num_next_marble[i][j] > k) {
					vector<Marble*> temp;

					for (auto it = marbles.begin(); it != marbles.end(); it++) {
						if ((*(*it)).x_ == i && (*(*it)).y_ == j && (*(*it)).is_present_) {
							temp.push_back((*it));
						}
					}

					sort(temp.begin(), temp.end(), cmp);

					for (int l = 0; l < temp.size() - k; l++) {
						(*temp[l]).is_present_ = false;
						num_next_marble[(*temp[l]).x_][(*temp[l]).y_]--;
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				num_marble[i][j] = num_next_marble[i][j];
			}
		}
	}

	int ans = 0;

	for (auto it = marbles.begin(); it != marbles.end(); it++) {
		if ((*(*it)).is_present_) {
			ans++;
		}
	}

	cout << ans;
}