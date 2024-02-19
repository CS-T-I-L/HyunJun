/*
 * Problem: https://inha.codetree.ai/missions/2/problems/n-permutations-of-k-with-repetition/description
 * File: Backtracking_1_1.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-02-12
 * License: MIT License
 * Comment: nPk (중복 허용) 기본 코드
 */

#include <iostream>
#include <vector>
using namespace std;

int k, n;
vector<int> v;

void choose(int cur_num) {
	if (cur_num == n + 1) {
		for (int i = 0; i < n; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= k; i++) {
		v.push_back(i);
		choose(cur_num + 1);
		v.pop_back();
	}
}

int main() {
	cin >> k >> n;
	choose(1);
}