#ifndef HEADERS_H
#define HEADERS_H

//#pragma GCC optimize "O3,omit-frame-pointer,inline"
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <chrono>
#include <functional>
#include <random>
#include <string>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(NULL) {}
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

template <typename T>
void print_vec(vector<T> vec) {
	for (int i = 0; i < (int)vec.size() - 1; i++)
		cout << vec[i] << " ";
	if (vec.size())
		cout << vec[vec.size() - 1];
	cout << endl;
}

template <typename T>
void print_vec(vector<vector<T>> vec) {
	for (int i = 0; i < (int)vec.size(); i++)
		print_vec(vec[i]);
}

void print_list(ListNode *head) {
	while (head) {
		cout << head -> val << " -> ";
		head = head -> next;
	}
	cout << "NULL" << endl;
}

#endif  // HEADERS_H

