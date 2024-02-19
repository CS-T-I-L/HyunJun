/*
 * Problem: https://inha.codetree.ai/missions/2/problems/select-segments-without-overlap/description
 * File: Backtracking_1_4.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-02-16
 * License: MIT License
 * Comment: 1_3°ú ºñ½Á
 */

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n;
bool is_full[1001];
vector<pair<int, int>> lines;
vector<vector<int>> all_combi;
int ans = 0;
vector<int> arr;


void choose(int cnt) {
	if (cnt == n) {
		all_combi.push_back(arr);
		return;
	}

	arr.push_back(0);
	choose(cnt + 1);
	arr.pop_back();

	arr.push_back(1);
	choose(cnt + 1);
	arr.pop_back();
}

bool validate(vector<int> combi) {
	for (int i = 0; i < 1001; i++) {
		is_full[i] = false;
	}

	for (int i = 0; i < n; i++) {
		if (combi[i]) {
			for (int j = lines[i].first; j <= lines[i].second; j++) {
				if (is_full[j]) {
					return false;
				}

				is_full[j] = true;
			}
		}
	}

	return true;
}

int get_cnt(vector<int> combi) {
	int cnt = 0;

	for (auto it = combi.begin(); it != combi.end(); it++) {
		if (*it == 1) {
			cnt++;
		}
	}

	return cnt;
}


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x1, x2; cin >> x1 >> x2;
		lines.push_back({ x1, x2 });
	}

	choose(0);

	for (auto it = all_combi.begin(); it != all_combi.end(); it++) {
		if (validate(*it)) {
			ans = max(ans, get_cnt(*it));
		}
	}
	cout << ans;
}