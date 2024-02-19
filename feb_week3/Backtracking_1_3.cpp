/*
 * Problem: https://inha.codetree.ai/missions/2/problems/strong-explosion/description
 * File: Backtracking_1_3.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-02-15
 * License: MIT License
 * Comment: 복잡해보여도 문제 정리해서 순열의 인덱스로 접근
 */

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n;
bool bombed[20][20];
int bomb_type[20][20];
vector<pair<int, int>> bomb_pos;
int ans;

bool is_range(int x, int y) {
	return (x >= 0 && x < n&& y >= 0 && y < n);
}

void bomb(int x, int y, int b_type) {
	pair<int, int> bomb_shapes[4][5] = {
		{},
		{ {-2, 0}, {-1, 0}, {0, 0}, {1, 0}, {2, 0} },
		{ {-1, 0}, {0, -1}, {0, 0}, {1, 0}, {0, 1} },
		{ {-1, -1}, {1, -1}, {0, 0}, {1, 1}, {-1, 1}}
	};

	for (int i = 0; i < 5; i++) {
		int nx = x + bomb_shapes[b_type][i].first;
		int ny = y + bomb_shapes[b_type][i].second;

		if (is_range(nx, ny)) {
			bombed[nx][ny] = true;
		}
	}
}

int calc() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bombed[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (bomb_type[i][j]) {
				bomb(i, j, bomb_type[i][j]);
			}
		}
	}

	int num_bombed = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (bombed[i][j]) {
				num_bombed++;
			}
		}
	}

	return num_bombed;
}

void back_tracking(int cnt) {
	if (cnt == bomb_pos.size()) {
		ans = max(ans, calc());
		return;
	}

	for (int i = 1; i <= 3; i++) {
		int x, y;
		tie(x, y) = bomb_pos[cnt];

		bomb_type[x][y] = i;
		back_tracking(cnt + 1);
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num; cin >> num;

			if (num) {
				bomb_pos.push_back({ i, j });
			}
		}
	}

	back_tracking(0);
	cout << ans;
}