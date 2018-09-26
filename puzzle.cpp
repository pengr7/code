#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>
#include <ctime>
#include <cmath>

#define SIZE 1000

using namespace std;

class puzzle {
 public:
	/*
	(i, j)num
	(0, 0)1  (0, 1)2  (0, 2)3
	(1, 0)4  (1, 1)5  (1, 2)6
	(2, 0)7  (2, 1)8  (2, 2)0
	*/
	bool upset;
	int total_count;
	vector<vector<int> > data;
	vector<vector<int> > bak;
	puzzle() {
		upset = false;
		total_count = 0;
		data = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
		disorganize();
		bak = data;
	}
	void disorganize() {
		for (int i = 0; i < 1000; i++) {
			int opt = rand() % 4;
			if (opt == 0)
				up();
			if (opt == 1)
				down();
			if (opt == 2)
				left();
			if (opt == 3)
				right();
		}
	}
	bool finished() {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (i * j != 4 && data[i][j] != 3 * i + j + 1)
					return false;
		return data[2][2] == 0;
	}
	pair<int, int> find_pos() {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (data[i][j] == 0)
					return pair<int, int>(i, j);
	}
	bool up() {
		int x = find_pos().first, y = find_pos().second;
		if (x < 2) {
			int temp = data[x][y];
			data[x][y] = data[x + 1][y];
			data[x + 1][y] = temp;
			return true;
		}
		return false;
	}
	bool down() {
		int x = find_pos().first, y = find_pos().second;
		if (x > 0) {
			int temp = data[x][y];
			data[x][y] = data[x - 1][y];
			data[x - 1][y] = temp;
			return true;
		}
		return false;
	}
	bool left() {
		int x = find_pos().first, y = find_pos().second;
		if (y < 2) {
			int temp = data[x][y];
			data[x][y] = data[x][y + 1];
			data[x][y + 1] = temp;
			return true;
		}
		return false;
	}
	bool right() {
		int x = find_pos().first, y = find_pos().second;
		if (y > 0) {
			int temp = data[x][y];
			data[x][y] = data[x][y - 1];
			data[x][y - 1] = temp;
			return true;
		}
		return false;
	}
	void print() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 2; j++)
				cout << data[i][j] << " ";
			cout << data[i][2] << endl;
		}
	}
	int total_manhattan_distance() {
		int total = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (data[i][j])
					total += (abs(i - (data[i][j] - 1) / 3) + abs(j - (data[i][j] - 1) % 3));
		return total;
	}
	bool steepest_ascent_hill_climbing() {
		//print();
		int current = total_manhattan_distance(), min = INT_MAX, mindir = 0;
		vector<int> dir = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
		if (up()) {
			dir[0] = total_manhattan_distance();
			down();
		}
		if (down()) {
			dir[1] = total_manhattan_distance();
			up();
		}
		if (left()) {
			dir[2] = total_manhattan_distance();
			right();
		}
		if (right()) {
			dir[3] = total_manhattan_distance();
			left();
		}
		for (int i = 0; i < 4; i++)
			if (dir[i] < min) {
				min = dir[i];
				mindir = i;
			}
		if (min >= current)
			return finished();
		if (mindir == 0)
			up();
		if (mindir == 1)
			down();
		if (mindir == 2)
			left();
		if (mindir == 3)
			right();
		return steepest_ascent_hill_climbing();
	}
	bool first_choice_hill_climbing() {
		//print();
		int current = total_manhattan_distance(), min = INT_MAX, randomdir = 0;
		vector<int> dir = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
		if (up()) {
			dir[0] = total_manhattan_distance();
			down();
		}
		if (down()) {
			dir[1] = total_manhattan_distance();
			up();
		}
		if (left()) {
			dir[2] = total_manhattan_distance();
			right();
		}
		if (right()) {
			dir[3] = total_manhattan_distance();
			left();
		}
		for (int i = 0; i < 4; i++)
			if (dir[i] < min)
				min = dir[i];
		if (min >= current)
			return finished();
		while (1) {
			randomdir = rand() % 4;
			if (dir[randomdir] < current)
				break;
		}
		if (randomdir == 0)
			up();
		if (randomdir == 1)
			down();
		if (randomdir == 2)
			left();
		if (randomdir == 3)
			right();
		return first_choice_hill_climbing();
	}
	bool hill_climbing_with_random_restart() {
		//print();
		int current = total_manhattan_distance(), min = INT_MAX, mindir = 0;
		vector<int> dir = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
		if (up()) {
			dir[0] = total_manhattan_distance();
			down();
		}
		if (down()) {
			dir[1] = total_manhattan_distance();
			up();
		}
		if (left()) {
			dir[2] = total_manhattan_distance();
			right();
		}
		if (right()) {
			dir[3] = total_manhattan_distance();
			left();
		}
		for (int i = 0; i < 4; i++)
			if (dir[i] < min) {
				min = dir[i];
				mindir = i;
			}
		if (min >= current) {
			if (finished())
				return true;
			upset = true;
			mindir = 4;
		}
		if (mindir == 0)
			up();
		if (mindir == 1)
			down();
		if (mindir == 2)
			left();
		if (mindir == 3)
			right();
		if (upset) {
			disorganize();
			upset = false;
			total_count++;
		}
		if (total_count > 1000) {
			total_count = 0;
			return false;
		}
		return hill_climbing_with_random_restart();
	}
	bool simulated_annealing() {
		for (int t = 0;; t++) {
			//print();
			int current = total_manhattan_distance();
			double T = (double)10 * pow(0.9, t);
			vector<int> dir = {current, current, current, current};
			if (finished())
				return true;
			if (T == 0)
				return finished();
			if (up()) {
				dir[0] = total_manhattan_distance();
				down();
			}
			if (down()) {
				dir[1] = total_manhattan_distance();
				up();
			}
			if (left()) {
				dir[2] = total_manhattan_distance();
				right();
			}
			if (right()) {
				dir[3] = total_manhattan_distance();
				left();
			}
			int randomdir = rand() % 4, E = current - dir[randomdir];
			if (E >= 0 || (E < 0 && (double)rand() / (double)RAND_MAX < exp((double)E / (double)T))) {
				if (randomdir == 0)
					up();
				if (randomdir == 1)
					down();
				if (randomdir == 2)
					left();
				if (randomdir == 3)
					right();
			}
		}
	}
};

vector<puzzle> puzzles;

void generate() {
	for (int i = 0; i < SIZE; i++)
		puzzles.push_back(puzzle());
}

int main() {
	generate();
	int r1 = 0, r2 = 0, r3 = 0, r4 = 0;
	long c0 = clock();
	for (int i = 0; i < SIZE; i++) {
		if (puzzles[i].steepest_ascent_hill_climbing())
			r1++;
		puzzles[i].data = puzzles[i].bak;
	}
	long c1 = clock();
	for (int i = 0; i < SIZE; i++) {
		if (puzzles[i].first_choice_hill_climbing())
			r2++;
		puzzles[i].data = puzzles[i].bak;
	}
	long c2 = clock();
	for (int i = 0; i < SIZE; i++) {
		if (puzzles[i].hill_climbing_with_random_restart())
			r3++;
		puzzles[i].data = puzzles[i].bak;
	}
	long c3 = clock();
	for (int i = 0; i < SIZE; i++) {
		if (puzzles[i].simulated_annealing())
			r4++;
		puzzles[i].data = puzzles[i].bak;
	}
	long c4 = clock();
	cout << "8-puzzle:" << endl; 
	cout << "Steepest-ascent hill climbing " << r1 / 10 << "." << r1 % 10 << "% " << (c1 - c0) / 1000 << "." << (c1 - c0) % 1000 << "s" << endl;
	cout << "First-choice hill climbing " << r2 / 10 << "." << r2 % 10 << "% " << (c2 - c1) / 1000 << "." << (c2 - c1) % 1000 << "s" << endl;
	cout << "Hill climbing with random restart " << r3 / 10 << "." << r3 % 10 << "% " << (c3 - c2) / 1000 << "." << (c3 - c2) % 1000 << "s" << endl;
	cout << "Simulated annealing " << r4 / 10 << "." << r4 % 10 << "% " << (c4 - c3) / 1000 << "." << (c4 - c3) % 1000 << "s" << endl;
	return 0;
}

