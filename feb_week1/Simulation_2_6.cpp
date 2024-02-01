/*
 * Problem: https://inha.codetree.ai/missions/2/problems/shortest-run-length-encoding/description
 * File: Simulation_2_6.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-02-01
 * License: MIT License
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string shift(string A, int n) {
	string S;
	S += A[n - 1];
	for (int i = 0; i < n - 1; i++) {
		S += A[i];
	}
	return S;
}

string encoding(string A, int n) {
	string S;
	int idx = 1;
	char c = A[0];
	int num = 1;

	while (idx < n) {
		if (A[idx] == c) {
			num++;
		}

		else {
			S += c;
			S += to_string(num);
			c = A[idx];
			num = 1;
		}

		idx++;
	}

	S += c;
	S += to_string(num);

	return S;
}

int main() {
	string A; cin >> A;
	int n = A.length();
	vector<int> v;

	if (n == 1) {
		cout << 2;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		string B = A;
		for (int j = 0; j < i; j++) {
			B = shift(B, n);
		}

		string en = encoding(B, n);
		v.push_back(en.length());
	}

	sort(v.begin(), v.end());

	cout << v.front();
}