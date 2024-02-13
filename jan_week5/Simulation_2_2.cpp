/*
 * Problem: https://inha.codetree.ai/missions/2/problems/conveyor-belt-triangle/description
 * File: Simulation_2_2.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-01-31
 * License: MIT License
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, t;

int main() {
	cin >> n >> t;
	vector<int> V_1, V_2, V_3;
	queue<int> Q_1, Q_2, Q_3;

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		V_1.push_back(num);
	}

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		V_2.push_back(num);
	}

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		V_3.push_back(num);
	}

	for (int i = n - 1; i >= 0; i--) {
		Q_1.push(V_1[i]);
		Q_2.push(V_2[i]);
		Q_3.push(V_3[i]);
	}

	V_1.clear();
	V_2.clear();
	V_3.clear();

	while (t--) {
		Q_2.push(Q_1.front());
		Q_1.pop();
		Q_3.push(Q_2.front());
		Q_2.pop();
		Q_1.push(Q_3.front());
		Q_3.pop();
	}

	int temp;
	for (int i = 0; i < n; i++) {
		temp = Q_1.front();
		V_1.push_back(temp);
		Q_1.pop();

		temp = Q_2.front();
		V_2.push_back(temp);
		Q_2.pop();

		temp = Q_3.front();
		V_3.push_back(temp);
		Q_3.pop();
	}

	for (int i = n - 1; i >= 0; i--) {
		cout << V_1[i] << " ";
	}
	cout << '\n';

	for (int i = n - 1; i >= 0; i--) {
		cout << V_2[i] << " ";
	}
	cout << '\n';

	for (int i = n - 1; i >= 0; i--) {
		cout << V_3[i] << " ";
	}
}