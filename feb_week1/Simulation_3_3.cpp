/*
 * Problem: https://inha.codetree.ai/missions/2/problems/The-1D-bomb-game/description
 * File: Simulation_3_3.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-02-02
 * License: MIT License
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

vector<pair<int, int>> check_cont(vector<int> v) {
	vector<pair<int, int>> temp;
	int s = 0, e = 0;

	for (int i = 1; i < v.size(); i++) {
		if (v[i] == v[i - 1]) {
			e = i;
		}
		else {
			if (e - s >= m - 1) {
				temp.push_back(make_pair(s, e));
			}
			s = i;
			e = i;
		}
	}

	if (e - s >= m - 1) {
		temp.push_back(make_pair(s, e));
	}

	return temp;
}

vector<int> explosion(vector<int> v, vector<pair<int, int>> se) {
	vector<int> temp;
	vector<bool> check_delete;

	for (int i = 0; i < v.size(); i++) {
		check_delete.push_back(false);
	}

	for (int i = 0; i < se.size(); i++) {
		for (int j = se[i].first; j <= se[i].second; j++) {
			check_delete[j] = true;
		}
	}

	for (int i = 0; i < v.size(); i++) {
		if (check_delete[i]) {
			continue;
		}
		temp.push_back(v[i]);
	}

	return temp;
}

int main() {
	cin >> n >> m;
	vector<int> arr;

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		arr.push_back(num);
	}

	reverse(arr.begin(), arr.end());

	while (!check_cont(arr).empty()) {
		arr = explosion(arr, check_cont(arr));
		if (arr.empty()) {
			break;
		}
	}

	cout << arr.size() << '\n';
	for (int i = arr.size() - 1; i >= 0; i--) {
		cout << arr[i] << '\n';
	}
}