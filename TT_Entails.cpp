// TT_Entails.cpp
// ref: http://vlm1.uta.edu/~athitsos/courses/old/cse4308_fall2015/lectures/03a_tt_entails.pdf
// implemented by Peng Rui

#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class LogicalExpression {
 public:
	string symbol;
	string connective;
	vector<LogicalExpression> children;
	LogicalExpression() {}
	vector<string> ExtractSymbols() {
		vector<string> result;
		if (symbol.length() > 0) {
			result.push_back(symbol);
		} else {
			for (LogicalExpression child : children) {
				vector<string> toAdd = child.ExtractSymbols();
				result.insert(result.end(), toAdd.begin(), toAdd.end());
			}
		}
		return result;
	}
};

bool TT_Entails(vector<LogicalExpression> KB, LogicalExpression alpha);
bool TT_Check_All(vector<LogicalExpression> KB, LogicalExpression alpha, vector<string> symbols, map<string, bool> model);
bool PL_True(vector<LogicalExpression> sentences, map<string, bool> model);
bool PL_True_helper(LogicalExpression sentence, map<string, bool> model);

bool TT_Entails(vector<LogicalExpression> KB, LogicalExpression alpha) {
	vector<string> symbols1;
	for (LogicalExpression sentence : KB) {
		vector<string> toAdd = sentence.ExtractSymbols();
		symbols1.insert(symbols1.end(), toAdd.begin(), toAdd.end());
	}
	vector<string> symbols2 = alpha.ExtractSymbols();
	vector<string> symbols(symbols1.size() + symbols2.size());
	sort(symbols1.begin(), symbols1.end());
	sort(symbols2.begin(), symbols2.end());
	vector<string>::iterator it = set_union(symbols1.begin(), symbols1.end(), symbols2.begin(), symbols2.end(), symbols.begin());
	symbols.resize(it - symbols.begin());
	map<string, bool> model;
	return TT_Check_All(KB, alpha, symbols, model);
}

bool TT_Check_All(vector<LogicalExpression> KB, LogicalExpression alpha, vector<string> symbols, map<string, bool> model) {
	if (symbols.empty()) {
		if (PL_True(KB, model))
			return PL_True_helper(alpha, model);
		return true;
	} else {
		string P = symbols[0];
		vector<string> rest = symbols;
		rest.erase(rest.begin());
		map<string, bool> extended_true = model;
		extended_true[P] = true;
		map<string, bool> extended_false = model;
		extended_false[P] = false;
		return TT_Check_All(KB, alpha, rest, extended_true) && TT_Check_All(KB, alpha, rest, extended_false);
	}
}

bool PL_True(vector<LogicalExpression> sentences, map<string, bool> model) {
	for (LogicalExpression sentence : sentences)
		if (PL_True_helper(sentence, model) == false)
			return false;
	return true;
}

bool PL_True_helper(LogicalExpression sentence, map<string, bool> model) {
	if (sentence.symbol.length() > 0) {
		if (model[sentence.symbol] == true)
			return true;
		return false;
	} else if (sentence.connective == "and") {
		for (LogicalExpression child : sentence.children)
			if (PL_True_helper(child, model) == false)
				return false;
		return true;
	} else if (sentence.connective == "or") {
		for (LogicalExpression child : sentence.children)
			if (PL_True_helper(child, model) == true)
				return true;
		return false;
	} else if (sentence.connective == "not") {
		LogicalExpression child = sentence.children[0];
		return !PL_True_helper(child, model);
	} else if (sentence.connective == "if") {
		LogicalExpression left = sentence.children[0], right = sentence.children[1];
		if (PL_True_helper(left, model) == true && PL_True_helper(right, model) == false)
			return false;
		return true;
	} else if (sentence.connective == "iff") {
		LogicalExpression left = sentence.children[0], right = sentence.children[1];
		if (PL_True_helper(left, model) == PL_True_helper(right, model))
			return true;
		return false;
	}
}

void test() {
	// test case
	// KB: B11 <=> (P12 or P21), B11
	LogicalExpression B11;
	B11.symbol = "B11";

	LogicalExpression P12;
	P12.symbol = "P12";

	LogicalExpression P21;
	P21.symbol = "P21";

	LogicalExpression OR;
	OR.connective = "or";
	OR.children = {P12, P21};

	LogicalExpression B11IFF;
	B11IFF.connective = "iff";
	B11IFF.children = {B11, OR};

	// alpha: not P12
	LogicalExpression NOTP12;
	NOTP12.connective = "not";
	NOTP12.children = {P12};

	cout << "test case:" << endl;
	cout << "KB entails 'not P12': " << TT_Entails({B11IFF, B11}, NOTP12) << endl;
	cout << endl;
}

int main () {
	test();
	return 0;
}

