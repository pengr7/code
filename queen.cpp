#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>
#include <ctime>
#include <cmath>

#define SIZE 1000

using namespace std;

class queen {
 public:
	/*
	(i, j)
	(0, 0)  (0, 1)  (0, 2)  (0, 3)  (0, 4)  (0, 5)  (0, 6)  (0, 7)
	(1, 0)  (1, 1)  (1, 2)  (1, 3)  (1, 4)  (1, 5)  (1, 6)  (1, 7)
	(2, 0)  (2, 1)  (2, 2)  (2, 3)  (2, 4)  (2, 5)  (2, 6)  (2, 7)
	(3, 0)  (3, 1)  (3, 2)  (3, 3)  (3, 4)  (3, 5)  (3, 6)  (3, 7)
	(4, 0)  (4, 1)  (4, 2)  (4, 3)  (4, 4)  (4, 5)  (4, 6)  (4, 7)
	(5, 0)  (5, 1)  (5, 2)  (5, 3)  (5, 4)  (5, 5)  (5, 6)  (5, 7)
	(6, 0)  (6, 1)  (6, 2)  (6, 3)  (6, 4)  (6, 5)  (6, 6)  (6, 7)
	(7, 0)  (7, 1)  (7, 2)  (7, 3)  (7, 4)  (7, 5)  (7, 6)  (7, 7)
	*/
	vector<vector<int> > data;
	vector<vector<int> > bak;
	queen() {
		disorganize();
		bak = data;
	}
	void disorganize() {
		data.clear();
		for (int i = 0; i < 8; i++) {
			vector<int> temp(8, 0);
			temp[rand() % 8] = 1;
			data.push_back(temp);
		}
	}
	int conflict() {
		int total = 0;
		for (int i = 0; i < 8; i++) {
			int sumx = 0, sumy = 0, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
			for (int j = 0; j < 8; j++) {
				sumx += data[i][j];
				sumy += data[j][i];
				if (i + j < 8) {
					if (i > 0) {
						sum1 += data[j][i + j];
						sum2 += data[7 - j][i + j];
					}
					sum3 += data[i + j][j];
					sum4 += data[7 - i - j][j];
				}
			}
			if (sumx)
				total += (sumx - 1);
			if (sumy)
				total += (sumy - 1);
			if (sum1)
				total += (sum1 - 1);
			if (sum2)
				total += (sum2 - 1);
			if (sum3)
				total += (sum3 - 1);
			if (sum4)
				total += (sum4 - 1);
		}
		return total;
	}
	bool steepest_ascent_hill_climbing() {
		int current = conflict(), min = INT_MAX;
		pair<int, int> mindir = pair<int, int>(0, 0);
		vector<vector<int> > dir;
		for (int i = 0; i < 8; i++) {
			vector<int> row;
			for (int j = 0; j < 8; j++) {
				vector<int> temp(8, 0), ori = data[i];
				temp[j] = 1;
				data[i] = temp;
				row.push_back(conflict());
				data[i] = ori;
			}
			dir.push_back(row);
		}
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (dir[i][j] < min) {
					min = dir[i][j];
					mindir = pair<int, int>(i, j);
				}
		if (min >= current)
			return conflict() == 0;
		vector<int> vec(8, 0);
		vec[mindir.second] = 1;
		data[mindir.first] = vec;
		return steepest_ascent_hill_climbing();
	}
	bool first_choice_hill_climbing() {
		int current = conflict(), min = INT_MAX;
		pair<int, int> randomdir = pair<int, int>(0, 0);
		vector<vector<int> > dir;
		for (int i = 0; i < 8; i++) {
			vector<int> row;
			for (int j = 0; j < 8; j++) {
				vector<int> temp(8, 0), ori = data[i];
				temp[j] = 1;
				data[i] = temp;
				row.push_back(conflict());
				data[i] = ori;
			}
			dir.push_back(row);
		}
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (dir[i][j] < min) {
					min = dir[i][j];
					randomdir = pair<int, int>(i, j);
				}
		if (min >= current)
			return conflict() == 0;
		while (1) {
			randomdir = pair<int, int>(rand() % 8, rand() % 8);
			if (dir[randomdir.first][randomdir.second] < current)
				break;
		}
		vector<int> vec(8, 0);
		vec[randomdir.second] = 1;
		data[randomdir.first] = vec;
		return first_choice_hill_climbing();
	}
	bool hill_climbing_with_random_restart() {
		int current = conflict(), min = INT_MAX;
		pair<int, int> mindir = pair<int, int>(0, 0);
		vector<vector<int> > dir;
		for (int i = 0; i < 8; i++) {
			vector<int> row;
			for (int j = 0; j < 8; j++) {
				vector<int> temp(8, 0), ori = data[i];
				temp[j] = 1;
				data[i] = temp;
				row.push_back(conflict());
				data[i] = ori;
			}
			dir.push_back(row);
		}
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (dir[i][j] < min) {
					min = dir[i][j];
					mindir = pair<int, int>(i, j);
				}
		if (min >= current) {
			if (conflict() == 0)
				return true;
			disorganize();
		} else {
			vector<int> vec(8, 0);
			vec[mindir.second] = 1;
			data[mindir.first] = vec;
		}
		return hill_climbing_with_random_restart();
	}
	bool simulated_annealing() {
		for (int t = 0;; t++) {
			int current = conflict();
			double T = (double)1 * pow(0.9, t);
			vector<vector<int> > dir;
			if (conflict() == 0)
				return true;
			if (T == 0)
				return conflict() == 0;
			for (int i = 0; i < 8; i++) {
				vector<int> row;
				for (int j = 0; j < 8; j++) {
					vector<int> temp(8, 0), ori = data[i];
					temp[j] = 1;
					data[i] = temp;
					row.push_back(conflict());
					data[i] = ori;
				}
				dir.push_back(row);
			}
			pair<int, int> randomdir = pair<int, int>(rand() % 8, rand() % 8);
			int E = current - dir[randomdir.first][randomdir.second];
			if (E >= 0 || (E < 0 && (double)rand() / (double)RAND_MAX < exp((double)E / (double)T))) {
				vector<int> vec(8, 0);
				vec[randomdir.second] = 1;
				data[randomdir.first] = vec;
			}
		}
	}
	void print() {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 7; j++)
				cout << data[i][j] << " ";
			cout << data[i][7] << endl;
		}
	}
};

vector<queen> queens;

void generate() {
	for (int i = 0; i < SIZE; i++)
		queens.push_back(queen());
}

int main() {
	generate();
	int r1 = 0, r2 = 0, r3 = 0, r4 = 0;
	long c0 = clock();
	for (int i = 0; i < SIZE; i++) {
		if (queens[i].steepest_ascent_hill_climbing())
			r1++;
		queens[i].data = queens[i].bak;
	}
	long c1 = clock();
	for (int i = 0; i < SIZE; i++) {
		if (queens[i].first_choice_hill_climbing())
			r2++;
		queens[i].data = queens[i].bak;
	}
	long c2 = clock();
	for (int i = 0; i < SIZE; i++) {
		if (queens[i].hill_climbing_with_random_restart())
			r3++;
		queens[i].data = queens[i].bak;
	}
	long c3 = clock();
	for (int i = 0; i < SIZE; i++) {
		if (queens[i].simulated_annealing())
			r4++;
		queens[i].data = queens[i].bak;
	}
	long c4 = clock();
	cout << "8-queens:" << endl; 
	cout << "Steepest-ascent hill climbing " << r1 / 10 << "." << r1 % 10 << "% " << (c1 - c0) / 1000 << "." << (c1 - c0) % 1000 << "s" << endl;
	cout << "First-choice hill climbing " << r2 / 10 << "." << r2 % 10 << "% " << (c2 - c1) / 1000 << "." << (c2 - c1) % 1000 << "s" << endl;
	cout << "Hill climbing with random restart " << r3 / 10 << "." << r3 % 10 << "% " << (c3 - c2) / 1000 << "." << (c3 - c2) % 1000 << "s" << endl;
	cout << "Simulated annealing " << r4 / 10 << "." << r4 % 10 << "% " << (c4 - c3) / 1000 << "." << (c4 - c3) % 1000 << "s" << endl;
	return 0;
}

