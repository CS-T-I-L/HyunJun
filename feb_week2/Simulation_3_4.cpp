/*
 * Problem: https://inha.codetree.ai/problems/one-trial-of-2048-game/description
 * File: Simulation_3_4.cpp
 * Author: Hyeonjun Jo (aaiss0927@naver.com)
 * Date: 2024-02-05
 * License: MIT License
 * Comment: 격자 회전 시 한칸 씩 뽑아서 인덱스의 식 유도 ㄴㄴ 연속된 칸 뽑아서 인덱스의 식 유도!
 */

#include <iostream>
#include <vector>
using namespace std;

int grid[4][4];

vector<int> move(vector<int> v) {
	vector<int> temp;
	for (int i = 0; i < 3; i++) {
		if ((v[i] != 0) && (v[i] == v[i + 1])) {
			v[i] = 2 * v[i];
			v[i + 1] = 0;
		}
	}

	int num_zero = 0;
	for (int i = 0; i < 4; i++) {
		if (v[i] != 0) {
			temp.push_back(v[i]);
		}
		else {
			num_zero++;
		}
	}

	for (int i = 0; i < num_zero; i++) {
		temp.push_back(0);
	}

	return temp;
}

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> grid[i][j];
		}
	}

	char dir; cin >> dir;

	vector<vector<int>> arr;

	if (dir == 'R') {
		int temp[4][4];

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				temp[i][j] = grid[i][3 - j];
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				grid[i][j] = temp[i][j];
			}
		}
	}

	else if (dir == 'U') {
		int temp[4][4];

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				temp[i][j] = grid[j][i];
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				grid[i][j] = temp[i][j];
			}
		}
	}

	else if (dir == 'D') {
		int temp[4][4];

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				temp[i][j] = grid[3 - j][i];
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				grid[i][j] = temp[i][j];
			}
		}
	}



	for (int i = 0; i < 4; i++) {
		vector<int> v;
		int num_zero = 0;
		for (int j = 0; j < 4; j++) {
			if (grid[i][j] != 0) {
				v.push_back(grid[i][j]);
			}
			else {
				num_zero++;
			}
		}
		for (int j = 0; j < num_zero; j++) {
			v.push_back(0);
		}
		arr.push_back(v);
	}

	for (int i = 0; i < 4; i++) {
		vector<int> temp;
		arr[i] = move(arr[i]);
	}

	if (dir == 'R') {
		int temp[4][4];

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				temp[i][j] = arr[i][3 - j];
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				arr[i][j] = temp[i][j];
			}
		}
	}

	else if (dir == 'U') {
		int temp[4][4];

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				temp[i][j] = arr[j][i];
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				arr[i][j] = temp[i][j];
			}
		}
	}

	else if (dir == 'D') {
		int temp[4][4];

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				temp[i][j] = arr[j][3 - i];
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				arr[i][j] = temp[i][j];
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
}