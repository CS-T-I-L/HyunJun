/*
 * Problem: https://inha.codetree.ai/missions/2/problems/ladder-game/description
 * File: Backtracking_1_5.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-02-17
 * License: MIT License
 * Comment: 문제 조건 잘 확인하자,,, 터무니없이 많은 경우의 수가 나온다면 문제 다시 확인하기!
 */

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
bool ladder_lines[16][12];

vector<pair<int, int>> lines;
vector<pair<int, int>> selected_lines;
vector<int> target;

int ans = INT_MAX;

bool is_equal(vector<int> v1, vector<int> v2) {
	for (int i = 1; i <= n; i++) {
		if (v1[i] != v2[i]) {
			return false;
		}
	}

	return true;
}

vector<int> ladder_result(vector<pair<int, int>> input) {
	vector<int> initial(n + 1);

	for (int i = 0; i <= n; i++) {
		initial[i] = i;
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 15; j++) {
			ladder_lines[j][i] = false;
		}
	}

	for (auto it = input.begin(); it != input.end(); it++) {
		ladder_lines[it->second][it->first] = true;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 15; j++) {
			if (ladder_lines[j][initial[i]]) {
				initial[i]++;
			}

			else if (ladder_lines[j][initial[i] - 1]) {
				initial[i]--;
			}
		}
	}

	vector<int> result(n + 1);

	for (int i = 0; i <= n; i++) {
		result[initial[i]] = i;
	}

	return result;
}

bool is_wrong(vector<pair<int, int>> input) {
	vector<int> initial(n + 1);

	for (int i = 0; i <= n; i++) {
		initial[i] = i;
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 15; j++) {
			ladder_lines[i][j] = false;
		}
	}

	for (auto it = input.begin(); it != input.end(); it++) {
		ladder_lines[it->second][it->first] = true;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 15; j++) {
			if (ladder_lines[j][initial[i]] && ladder_lines[j][initial[i] - 1]) {
				return true;
			}
		}
	}

	return false;
}

vector<int> subset;

void select(int cnt) {
	if (cnt == m) {
		selected_lines.clear();

		if (subset.empty()) {
			return;
		}

		for (int i = 0; i < subset.size(); i++) {
			selected_lines.push_back(lines[subset[i]]);
		}

		if (!is_wrong(selected_lines)) {
			vector<int> result = ladder_result(selected_lines);

			if (is_equal(result, target)) {
				ans = min(ans, (int)subset.size());
				return;
			}
		}

		return;
	}

	select(cnt + 1);
	subset.push_back(cnt);
	select(cnt + 1);
	subset.pop_back();
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		lines.push_back({ a, b });
	}

	target = ladder_result(lines);

	vector<int> initial(n + 1);

	for (int i = 0; i <= n; i++) {
		initial[i] = i;
	}

	if (is_equal(target, initial)) {
		cout << 0;
		return 0;
	}

	select(0);

	cout << ans;
}