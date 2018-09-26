// A simple calculator
// implemented by Peng Rui
// Dev-C++ 5.11, 64-bit Windows 10
#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>
using namespace std;

// check if a character is an operator
bool isoperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

// remove extra spaces
void compress(string &s) {
	stringstream ss(s);
	s.clear();
	string tmp;
	while (ss >> tmp)
		s.append(tmp);
}

// modify a string
void modify(string &s) {
	// remove useless characters
	for (int i = 0; i < s.size(); i++)
		if (!isdigit(s[i]) && !isoperator(s[i]))
			s[i] = ' ';
	compress(s);

	// remove surplus operators
	for (int i = 0; i < s.size(); i++)
		if (isoperator(s[i]))
			for (int j = i; j < s.size() - 1; j++)
				if (isoperator(s[j + 1]))
					s[j] = ' ';
				else
					break;
	compress(s);

	// modify the beginning and ending
	if (isoperator(s[0]))
		if (s[0] == '+' || s[0] == '-')
			s.insert(0, "0");
		else
			s[0] = ' ';
	s.insert(0, "0+");
	if (isoperator(s[s.size() - 1]))
		s[s.size() - 1] = ' ';
	compress(s);
}

// converter
vector<vector<pair<int, char> > > getData(string s) {
	int temp = 0;
	vector<pair<int, char> > row;
	vector<vector<pair<int, char> > > data;
	modify(s);
	for (int i = 0;; i++) {
		if (i == s.size() - 1) {
			temp = temp * 10 + s[i] - '0';
			row.push_back(pair<int, char>(temp, '#'));
			temp = 0;
			break;
		}
		if (isdigit(s[i]))
			temp = temp * 10 + s[i] - '0';
		if (isoperator(s[i])) {
			row.push_back(pair<int, char>(temp, s[i]));
			temp = 0;
		}
	}
	for (int i = 0; i < row.size(); i++)
		if (row[i].second == '+' || row[i].second == '-' || row[i].second == '#') {
			data.push_back(vector<pair<int, char> >(row.begin() + temp, row.begin() + i + 1));
			temp = i + 1;
		}
	return data;
}

// calculator main
int calculate(string s) {
	int temp;
	vector<pair<int, char> > row;
	vector<vector<pair<int, char> > > data = getData(s);
	for (int i = 0; i < data.size(); i++)
		for (int j = 0; j < data[i].size(); j++)
			cout << data[i][j].first << " " << data[i][j].second << " ";
	cout << endl;
	for (int i = 0; i < data.size(); i++) {
		temp = data[i][0].first;
		for (int j = 1; j < data[i].size(); j++) {
			if (data[i][j - 1].second == '*')
				temp *= data[i][j].first;
			if (data[i][j - 1].second == '/')
				temp /= data[i][j].first;
		}
		row.push_back(pair<int, char>(temp, data[i][data[i].size() - 1].second));
	}
	temp = row[0].first;
	for (int i = 1; i < row.size(); i++) {
		if (row[i - 1].second == '+')
			temp += row[i].first;
		if (row[i - 1].second == '-')
			temp -= row[i].first;
	}	
	return temp;
}

// test helper
int num = 0;
void test_helper(string s) {
	cout << "test case " << num++ << ":" << endl << s << endl;
	cout << calculate(s) << endl << endl;
}

// test
int main() {
	// test cases
	test_helper("");
	test_helper("1");
	test_helper("1+117");
	test_helper("1-2*3-48/4/2");
	test_helper("++++++++__------\\\\");
	test_helper("a;-+*-c63d/3+9 2 %@#:%#{$++@!@:} ----- 019 ------");

	// customize your own test cases, input "exit" to exit the loop
	string s;
	cout << "Now customize your test cases, the program keeps looping till \"exit\" inputed." << endl;
	while (getline(cin, s) && s != "exit")
		cout << calculate(s) << endl << endl;
	system("pause");
	return 0;
}

