/*
 * Problem: https://inha.codetree.ai/missions/2/problems/collision-experiment-with-wall/description
 * File: Simulation_5_3.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-02-08
 * License: MIT License
 * Comment: Àç¹Ì½á
 */

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
pair<int, int> dir[4] = { {dx[0], dy[0]}, {dx[1], dy[1]},
						 {dx[2], dy[2]}, {dx[3], dy[3]} };

class Marble {
public:
	int x_;
	int y_;
	pair<int, int> dir_;
	bool is_present_;

	Marble(int x, int y, int d)
		: x_{ x }, y_{ y }, is_present_{ true } {
		if (d == 'U') {
			dir_ = dir[0];
		}

		else if (d == 'D') {
			dir_ = dir[1];
		}

		else if (d == 'R') {
			dir_ = dir[2];
		}

		else if (d == 'L') {
			dir_ = dir[3];
		}
	}
};

pair<int, int> set_dir(Marble marble, int n) {
	if (marble.x_ == 0 && marble.dir_ == dir[0]) {
		return dir[1];
	}

	else if (marble.x_ == n - 1 && marble.dir_ == dir[1]) {
		return dir[0];
	}

	else if (marble.y_ == 0 && marble.dir_ == dir[3]) {
		return dir[2];
	}

	else if (marble.y_ == n - 1 && marble.dir_ == dir[2]) {
		return dir[3];
	}

	return marble.dir_;
}

int main() {
	int T; cin >> T;

	while (T--) {
		vector<Marble> marbles;
		int num_marble[50][50];
		int num_next_marble[50][50];
		int n, m; cin >> n >> m;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				num_marble[i][j] = 0;
			}
		}

		while (m--) {
			int x, y; cin >> x >> y;
			x--; y--;
			char d; cin >> d;

			Marble marble(x, y, d);
			marbles.push_back(marble);
			num_marble[x][y]++;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				num_next_marble[i][j] = num_marble[i][j];
			}
		}

		int t = 2 * n;

		while (t--) {
			for (auto it = marbles.begin(); it != marbles.end(); it++) {
				if ((*it).is_present_ == true) {
					if ((*it).dir_ != set_dir((*it), n)) {
						(*it).dir_ = set_dir((*it), n);
						continue;
					}

					num_next_marble[(*it).x_][(*it).y_]--;

					(*it).x_ = (*it).x_ + (*it).dir_.first;
					(*it).y_ = (*it).y_ + (*it).dir_.second;

					num_next_marble[(*it).x_][(*it).y_]++;
				}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (num_next_marble[i][j] > 1) {
						num_next_marble[i][j] = 0;

						for (auto it = marbles.begin(); it != marbles.end(); it++) {
							if ((*it).x_ == i && (*it).y_ == j) {
								(*it).is_present_ = false;
							}
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
			if ((*it).is_present_ == true) {
				ans++;
			}
		}

		cout << ans << '\n';
	}
}