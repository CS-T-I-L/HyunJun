/*
 * Problem: https://inha.codetree.ai/missions/2/problems/snake-loves-apples/description
 * File: Simulation_4_6.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-02-06
 * License: MIT License
 * Comment: t 값을 묻는 문제라면, t가 적절한 반복문에 위치하였는지 확인!!
 */

#include <iostream>
#include <vector>
using namespace std;

class Snake {
public:
	pair<int, int> head;
	vector<pair<int, int>> tail;
	int length = 1;

	Snake() {
		head = { 0, 0 };
	}
};

int n, m, k;
int grid[100][100];

bool is_range(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n);
}

int main() {
	Snake snake;

	cin >> n >> m >> k;

	while (m--) {
		int x_apple, y_apple;
		cin >> x_apple >> y_apple;
		x_apple--; y_apple--;
		grid[x_apple][y_apple] = 1;
	}

	int t = 0;

	while (k--) {
		char d;
		int p;
		cin >> d >> p;

		bool flag_is_not_range = false;
		bool flag_twist = false;

		if (d == 'U') {
			while (p--) {
				t++;
				pair<int, int> cur_snake_head = snake.head;
				snake.head.first--;

				if (!is_range(snake.head.first, snake.head.second)) {
					flag_is_not_range = true;
					break;
				}

				if (!snake.tail.empty()) {
					for (int i = 0; i < snake.tail.size() - 1; i++) {
						if (snake.head.first == snake.tail[i].first
							&& snake.head.second == snake.tail[i].second) {
							flag_twist = true;
							break;
						}
					}

					pair<int, int> temp = snake.tail.back();

					for (int i = snake.tail.size() - 1; i >= 1; i--) {
						snake.tail[i] = snake.tail[i - 1];
					}
					snake.tail[0] = cur_snake_head;

					if (grid[snake.head.first][snake.head.second] == 1) {
						snake.tail.push_back(temp);
						grid[snake.head.first][snake.head.second] = 0;
					}
				}

				else {
					if (grid[snake.head.first][snake.head.second] == 1) {
						snake.tail.push_back(cur_snake_head);
						grid[snake.head.first][snake.head.second] = 0;
					}
				}

				if (flag_twist) {
					break;
				}
			}

			if (flag_twist || flag_is_not_range) {
				break;
			}
		}

		else if (d == 'D') {
			while (p--) {
				t++;
				pair<int, int> cur_snake_head = snake.head;
				snake.head.first++;

				if (!is_range(snake.head.first, snake.head.second)) {
					flag_is_not_range = true;
					break;
				}

				if (!snake.tail.empty()) {
					for (int i = 0; i < snake.tail.size() - 1; i++) {
						if (snake.head.first == snake.tail[i].first
							&& snake.head.second == snake.tail[i].second) {
							flag_twist = true;
							break;
						}
					}

					pair<int, int> temp = snake.tail.back();

					for (int i = snake.tail.size() - 1; i >= 1; i--) {
						snake.tail[i] = snake.tail[i - 1];
					}
					snake.tail[0] = cur_snake_head;

					if (grid[snake.head.first][snake.head.second] == 1) {
						snake.tail.push_back(temp);
						grid[snake.head.first][snake.head.second] = 0;
					}
				}

				else {
					if (grid[snake.head.first][snake.head.second] == 1) {
						snake.tail.push_back(cur_snake_head);
						grid[snake.head.first][snake.head.second] = 0;
					}
				}

				if (flag_twist) {
					break;
				}
			}

			if (flag_twist || flag_is_not_range) {
				break;
			}
		}

		else if (d == 'R') {
			while (p--) {
				t++;
				pair<int, int> cur_snake_head = snake.head;
				snake.head.second++;

				if (!is_range(snake.head.first, snake.head.second)) {
					flag_is_not_range = true;
					break;
				}

				if (!snake.tail.empty()) {
					for (int i = 0; i < snake.tail.size() - 1; i++) {
						if (snake.head.first == snake.tail[i].first
							&& snake.head.second == snake.tail[i].second) {
							flag_twist = true;
							break;
						}
					}

					pair<int, int> temp = snake.tail.back();

					for (int i = snake.tail.size() - 1; i >= 1; i--) {
						snake.tail[i] = snake.tail[i - 1];
					}
					snake.tail[0] = cur_snake_head;

					if (grid[snake.head.first][snake.head.second] == 1) {
						snake.tail.push_back(temp);
						grid[snake.head.first][snake.head.second] = 0;
					}
				}

				else {
					if (grid[snake.head.first][snake.head.second] == 1) {
						snake.tail.push_back(cur_snake_head);
						grid[snake.head.first][snake.head.second] = 0;
					}
				}

				if (flag_twist) {
					break;
				}
			}

			if (flag_twist || flag_is_not_range) {
				break;
			}
		}

		else if (d == 'L') {
			while (p--) {
				t++;
				pair<int, int> cur_snake_head = snake.head;
				snake.head.second--;

				if (!is_range(snake.head.first, snake.head.second)) {
					flag_is_not_range = true;
					break;
				}

				if (!snake.tail.empty()) {
					for (int i = 0; i < snake.tail.size() - 1; i++) {
						if (snake.head.first == snake.tail[i].first
							&& snake.head.second == snake.tail[i].second) {
							flag_twist = true;
							break;
						}
					}

					pair<int, int> temp = snake.tail.back();

					for (int i = snake.tail.size() - 1; i >= 1; i--) {
						snake.tail[i] = snake.tail[i - 1];
					}
					snake.tail[0] = cur_snake_head;

					if (grid[snake.head.first][snake.head.second] == 1) {
						snake.tail.push_back(temp);
						grid[snake.head.first][snake.head.second] = 0;
					}
				}

				else {
					if (grid[snake.head.first][snake.head.second] == 1) {
						snake.tail.push_back(cur_snake_head);
						grid[snake.head.first][snake.head.second] = 0;
					}
				}

				if (flag_twist) {
					break;
				}
			}

			if (flag_twist || flag_is_not_range) {
				break;
			}
		}
	}

	cout << t;
}