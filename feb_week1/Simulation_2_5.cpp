/*
 * Problem: https://inha.codetree.ai/problems/rotate-slanted-rectangle/description
 * File: Simulation_2_5.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-02-01
 * License: MIT License
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int grid[100][100];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	int r, c, m_1, m_2, m_3, m_4, dir;
	cin >> r >> c >> m_1 >> m_2 >> m_3 >> m_4 >> dir;
	r--; c--;

	int r_1 = r; int c_1 = c;
	int r_2 = r_1 - m_1; int c_2 = c_1 + m_1;
	int r_3 = r_2 - m_2; int c_3 = c_2 - m_2;
	int r_4 = r_3 + m_3; int c_4 = c_3 - m_3;
	int m_1_ = m_1;
	int m_2_ = m_2;
	int m_3_ = m_3;
	int m_4_ = m_4;

	vector<int> v;
	queue<int> q;
	int i, j;

	i = r_1; j = c_1;
	while (m_1_--) {
		v.push_back(grid[i][j]);
		i--; j++;
	}

	while (m_2_--) {
		v.push_back(grid[i][j]);
		i--; j--;
	}

	while (m_3_--) {
		v.push_back(grid[i][j]);
		i++; j--;
	}

	while (m_4_--) {
		v.push_back(grid[i][j]);
		i++; j++;
	}

	int sz = v.size();

	if (dir == 0) {
		for (auto it = v.rbegin(); it != v.rend(); it++) {
			q.push(*it);
		}
		v.clear();
	}

	else {
		for (auto it = v.begin(); it != v.end(); it++) {
			q.push(*it);
		}
		v.clear();
	}

	int temp = q.front();
	q.pop();
	q.push(temp);

	for (int i = 0; i < sz; i++) {
		int temp = q.front();
		v.push_back(temp);
		q.pop();
	}

	if (dir == 0) {
		reverse(v.begin(), v.end());
	}
	int idx = 0;

	m_1_ = m_1;
	m_2_ = m_2;
	m_3_ = m_3;
	m_4_ = m_4;

	i = r_1; j = c_1;
	while (m_1_--) {
		grid[i][j] = v[idx];
		idx++;
		i--; j++;
	}

	while (m_2_--) {
		grid[i][j] = v[idx];
		idx++;
		i--; j--;
	}

	while (m_3_--) {
		grid[i][j] = v[idx];
		idx++;
		i++; j--;
	}

	while (m_4_--) {
		grid[i][j] = v[idx];
		idx++;
		i++; j++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << grid[i][j] << " ";
		}
		cout << '\n';
	}
}