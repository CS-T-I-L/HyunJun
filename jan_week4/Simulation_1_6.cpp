/*
 * Problem: https://inha.codetree.ai/missions/2/problems/non-overlapping-two-rectangles/description
 * File: Simulation_1_6.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-01-26
 * License: MIT License
 */

#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int grid[5][5];
bool check[5][5];



int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	vector<tuple<pair<int, int>, pair<int, int>, pair<int, int>, pair<int, int>>> rectangles;

	for (int i_1 = 0; i_1 < n; i_1++) {
		for (int j_1 = 0; j_1 < m; j_1++) {
			for (int h_1 = 1; h_1 <= n - i_1; h_1++) {
				for (int w_1 = 1; w_1 <= m - j_1; w_1++) {
					for (int i_2 = 0; i_2 < i_1; i_2++) {
						for (int j_2 = 0; j_2 < m; j_2++) {
							for (int h_2 = 1; h_2 <= i_1 - i_2; h_2++) {
								for (int w_2 = 1; w_2 <= m - j_2; w_2++) {
									rectangles.push_back({ { i_1, j_1 }, {h_1, w_1}, {i_2, j_2}, {h_2, w_2} });
								}
							}
						}
					}

					for (int i_2 = i_1; i_2 < i_1 + h_1; i_2++) {
						for (int j_2 = 0; j_2 < j_1; j_2++) {
							for (int h_2 = 1; h_2 <= n - i_2; h_2++) {
								for (int w_2 = 1; w_2 <= j_1 - j_2; w_2++) {
									rectangles.push_back({ { i_1, j_1 }, {h_1, w_1}, {i_2, j_2}, {h_2, w_2} });
								}
							}
						}

						for (int j_2 = j_1 + w_1; j_2 < m; j_2++) {
							for (int h_2 = 1; h_2 <= n - i_2; h_2++) {
								for (int w_2 = 1; w_2 <= m - j_2; w_2++) {
									rectangles.push_back({ { i_1, j_1 }, {h_1, w_1}, {i_2, j_2}, {h_2, w_2} });
								}
							}
						}
					}

					for (int i_2 = i_1 + h_1; i_2 < n; i_2++) {
						for (int j_2 = 0; j_2 < m; j_2++) {
							for (int h_2 = 1; h_2 <= n - i_2; h_2++) {
								for (int w_2 = 1; w_2 <= m - j_2; w_2++) {
									rectangles.push_back({ { i_1, j_1 }, {h_1, w_1}, {i_2, j_2}, {h_2, w_2} });
								}
							}
						}
					}
				}
			}
		}
	}

	int ans = -25000;
	int sum;

	for (auto it = rectangles.begin(); it != rectangles.end(); it++) {
		sum = 0;

		for (int i = get<0>(*it).first; i <= get<0>(*it).first + get<1>(*it).first - 1; i++) {
			for (int j = get<0>(*it).second; j <= get<0>(*it).second + get<1>(*it).second - 1; j++) {
				sum += grid[i][j];
			}
		}

		for (int i = get<2>(*it).first; i <= get<2>(*it).first + get<3>(*it).first - 1; i++) {
			for (int j = get<2>(*it).second; j <= get<2>(*it).second + get<3>(*it).second - 1; j++) {
				sum += grid[i][j];
			}
		}

		ans = max(ans, sum);
	}

	cout << ans;
}