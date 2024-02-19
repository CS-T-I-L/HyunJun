/*
 * Problem: https://inha.codetree.ai/missions/2/problems/beautiful-number/description
 * File: Backtracking_1_2.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-02-14
 * License: MIT License
 * Comment: 모든 경우의 수를 만든 후, 종료 조건문에 조건 추가
 */

#include <iostream>
#include <vector>
using namespace std;

int n;
int ans = 0;
vector<int> arr;
vector<vector<int>> candidate;
vector<vector<int>> check;

void make_candidate() {
	if (arr.size() == n) {
		candidate.push_back(arr);
		return;
	}

	for (int i = 1; i <= 4; i++) {
		arr.push_back(i);
		make_candidate();
		arr.pop_back();
	}
}

void process(int* cont) {
	for (int i = 0; i < 4; i++) {
		*(cont + i) = *(cont + i) % (i + 1);
	}
}

bool is_beautiful(int* cont) {
	for (int i = 0; i < 4; i++) {
		if (*(cont + i) != 0) {
			return false;
		}
	}

	return true;
}

void num_beautiful_num() {
	for (auto it = candidate.begin(); it != candidate.end(); it++) {
		int cont[4] = { 0, };
		int cur_num = (*it)[0];
		cont[cur_num - 1]++;
		process(cont);

		for (int i = 1; i < n; i++) {
			if ((*it)[i] == (*it)[i - 1]) {
				cont[cur_num - 1]++;
				process(cont);
			}
			else {
				if (!is_beautiful(cont)) {
					break;
				}
				cur_num = (*it)[i];
				cont[cur_num - 1]++;
				process(cont);
			}
		}

		if (!is_beautiful(cont)) {
			continue;
		}

		check.push_back(*it);
		ans++;
	}
}

int main() {
	cin >> n;

	make_candidate();
	num_beautiful_num();
	cout << ans;
}